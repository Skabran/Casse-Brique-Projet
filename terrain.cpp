#include "terrain.h"
#include "affichageJeu.h"
#include "calculateur.h"


terrain::terrain():d_longueurTerrain{780}, d_largeurTerrain{800}, d_nbBalle{0}, d_precisionCollision{1},
 d_tableauElement{}, d_tableauElementMouvant{} {}

terrain::terrain(const std::string& nomFichier) : d_longueurTerrain{}, d_largeurTerrain{},
d_nbBalle{}, d_precisionCollision{}, d_tableauElement{}, d_tableauElementMouvant{} {}

terrain::~terrain()
{
    for(unsigned int i=0; i<d_tableauElement.size();i++)
    {
        delete d_tableauElement[i];
    }
    /*  Inutile car les elements du tableau d'element mouvant sont deja supprimé par le tableau d'element
    for(unsigned int i=0; i<d_tableauElementMouvant.size();i++)
    {
        delete d_tableauElementMouvant[i];
    }
    */
}


int terrain::getNbBalle() const
{
    return d_nbBalle;
}


int terrain::getLongueurTerrain() const
{
    return d_longueurTerrain;
}


int terrain::getLargeurTerrain() const
{
    return d_largeurTerrain;
}


int terrain::getPrecisionCollision() const
{
    return d_precisionCollision;
}


element* terrain::getElement(int i) const
{
    return d_tableauElement[i];
}

elementMouvant* terrain::getElementMouvant(int i) const
{
    return d_tableauElementMouvant[i];
}


std::vector<element*> terrain::getElement() const
{
    return d_tableauElement;
}


std::vector<elementMouvant*> terrain::getElementmouvant() const
{
    return d_tableauElementMouvant;
}


void terrain::boucleDeJeu(const affichageJeu& afficheur)
{

    for(int i = 0; i<d_nbBalle;i++)
    {
        collisionElemM(i);
    }

    if(testPartieFinie()!=0)    //plus efficace car c'est le test le plus susceptible d'etre faux
    {
        if(testPartieFinie()==1)
        {
            afficheur.afficheVictoire();    //Victoire du joueur
            getch();
            return;
        }
        else
        {
            afficheur.afficheDefaite();     //Defaite du joueur
            getch();
            return;
        }
    }

    afficheur.afficheTerrain(*this);
    //pas besoin de getch ici car l'affichage se met en pose pour attendre que l'utilisateur bouge la raquette
    for(int i=d_nbBalle; i<d_tableauElementMouvant.size(); i++)
    {
        deplacerElementMouvant(i); //Deplace le reste des elementMouvant
    }
    afficheur.afficheTerrain(*this);
    getch();
}


void terrain::collisionElemM(int indexElemM)
{
    elementMouvant* elemM = d_tableauElementMouvant[indexElemM];
    double vitesseElemM=elemM->getVecteur().getVitesse();
    double distanceAParcourrir=vitesseElemM;
    while(distanceAParcourrir>0)
    {
        int elementCollision = collisionToutTableauElement(indexElemM, d_precisionCollision);

        if(elementCollision==-1)
        {
            deplacerElementMouvant(indexElemM);  //Pas de collision, la balle se déplace de tout son vecteur vitesse
            distanceAParcourrir=0;
        }
        else
        {
            approchePasAPas(elemM, d_tableauElement[elementCollision], distanceAParcourrir);
        }
    }
    elemM->getVecteur().changeVitesse(vitesseElemM); //Après les calculs ont redonne a l'élémentmouvant sa vitesse d'origine
}


void terrain::approchePasAPas(elementMouvant* elemM, element* elem, double& distanceAParcourir)
{
    elemM->getVecteur().changeVitesse(distanceAParcourir);//a chaque parcour du while on ne garde que la distance restante
    calculateur calc{};
    double distanceApproche;
    distanceApproche=calc.distance(elemM->getPosition(), elem->getPosition());
    elemM->deplaceDistance(distanceApproche);
    effetCollisionDeuxElements(elemM,elem);
    distanceAParcourir=elemM->getVecteur().getVitesse() - distanceApproche;
}


int terrain::collisionToutTableauElement(int indiceElementQuiBouge, int precision) const
{
    int elementCollision;
    int j = precision;                  //Pas obligatoire mais plus claire pour les iterations
    balle* elementTemp;
    elementTemp = new balle{};          //Car ce sera en générale une balle et qu'on ne peut pas créer d'element mouvant (classe virtuelle)
    position positionElementQuiBouge = d_tableauElementMouvant[indiceElementQuiBouge]->getPosition();
    vecteur vecteurElementQuiBouge = d_tableauElementMouvant[indiceElementQuiBouge]->getVecteur();

    while(j>0&&elementCollision==-1)
    {
        vecteur vecteurTemp = vecteurElementQuiBouge*(1/precision);   //Meilleur façon de faire avec Lambda*M + (1-lambda)*M' a faire plus tard
        position positionTemp = positionElementQuiBouge+vecteurTemp;
        elementTemp->changePosition(positionTemp);
        elementTemp->changeVecteur(vecteurTemp);

        //première partie du tableau
        elementCollision = collisionPartieDuTableau(0, indiceElementQuiBouge, elementTemp);
        //deuxième partie du tableau
        if(elementCollision==-1)
        {
            elementCollision=collisionPartieDuTableau(indiceElementQuiBouge+1, d_tableauElement.size(), elementTemp);
        }
        j--;
    }
    delete elementTemp;
    return elementCollision;
}




int terrain::collisionPartieDuTableau(int indiceDebut, int indiceFin, const element *elementQuiBouge) const
{
    int elementCollision=-1;
    int h = indiceDebut;
    while(h<indiceFin&&elementCollision==-1)
    {
        element* elementFixe=getElement(h);

        if(testCollisionDeuxElement(elementQuiBouge, elementFixe))
        {
            elementCollision=h;
        }
        h++;
    }
    return elementCollision;
}


bool terrain::testCollisionDeuxElement(const element *premierElement,const element *deuxiemeElement) const
{

}


void terrain::effetCollisionDeuxElements(elementMouvant *premierElement, element *deuxiemeElement)
{
    premierElement->effetCollision(deuxiemeElement);
    deuxiemeElement->effetCollision(premierElement);
}


int terrain::testPartieFinie() const
{

}


void terrain::deplacerElementMouvant(unsigned int i)
{
    d_tableauElementMouvant[i]->deplacer();
}


int terrain::litTerrain(const std::string& nomFichier)
{
    unsigned int i;
    unsigned int j;
    double x,y,vitesse,angle,diametre;
    char c;
    d_tableauElement.reserve(40);
    d_tableauElementMouvant.reserve(10);

    std::ifstream fichierIn{nomFichier+".txt"};
    if(!fichierIn)
        return 1;

    fichierIn>>d_nbBalle>>d_precisionCollision;
    for(i=0; i<d_nbBalle;i++)
    {
        fichierIn>>c;
        if(c!='A')
            return 2;

        fichierIn>>x>>y>>vitesse>>angle>>diametre;
        d_tableauElement.push_back(nullptr);
        d_tableauElementMouvant.push_back(nullptr);
        d_tableauElementMouvant[i]= new balle{x,y,vitesse,angle,diametre};
        d_tableauElement[i]=d_tableauElementMouvant[i];
    }

    while(c!='@')
    {
        fichierIn>>c;
        switch(c)
        {
        case 'B':
            fichierIn>>x>>y;
            d_tableauElement.push_back(nullptr);
            d_tableauElement[i]=new raquette{x,y};
            i++;
            break;

        case 'C':
            fichierIn>>x>>y;
            d_tableauElement.push_back(nullptr);
            d_tableauElement[i]=new brique{x,y};
            i++;
            break;
        default:
            break;
        }
    }
    return 0;
}
