#include "terrain.h"


terrain::terrain():d_longueurTerrain{800}, d_largeurTerrain{800}, d_nbBalle{0}, d_precisionCollision{1},
 d_tableauElement{}, d_tableauElementMouvant{} {}

terrain::terrain(const std::string& nomFichier) : d_longueurTerrain{}, d_largeurTerrain{},
d_nbBalle{}, d_precisionCollision{}, d_tableauElement{}, d_tableauElementMouvant{}
{

}

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

void terrain::boucleDeJeu()
{

    for(int i = 0; i<d_nbBalle;i++)
    {
        int elementCollision = collisionTotale(i, d_precisionCollision);
        if(elementCollision!=-1)    //Si il n'y a pas eu de collision, on ne fais rien
        {
            effetCollisionDeuxElements(d_tableauElement[i], d_tableauElement[elementCollision] ); //on applique l'effet de la collision entre la balle et l'element qu'elle rencontre
        }
    }
}



int terrain::collisionTotale(int indiceElementQuiBouge, int precision) const
{
    int elementCollision;
    int j = precision;                  //Pas obligatoire mais plus claire pour les iterations
    balle* elementTemp;
    elementTemp = new balle{};          //Car ce sera en générale une balle et qu'on ne peut pas créer d'element mouvant (classe virtuelle)
    position positionElementQuiBouge = d_tableauElement[indiceElementQuiBouge]->getPosition();
    vecteur vecteurElementQuiBouge = d_tableauElementMouvant[indiceElementQuiBouge]->getVecteur();

    while(j>0&&elementCollision==-1)
    {
        vecteur vecteurTemp = vecteurElementQuiBouge*(1/precision);   //Meilleur façon de faire avec Lambda*M + (1-lambda)*M' a faire plus tard
        position positionTemp = positionElementQuiBouge+vecteurTemp;
        elementTemp->changePosition(positionTemp);
        elementTemp->changeVecteur(vecteurTemp);

        //première partie du tableau
        elementCollision = collisionPartielle(0, indiceElementQuiBouge, elementTemp);
        //deuxième partie du tableau
        if(elementCollision==-1)
        {
            elementCollision=collisionPartielle(indiceElementQuiBouge+1, d_tableauElement.size(), elementTemp);
        }
        j--;
    }
    delete elementTemp;
    return elementCollision;
}


int terrain::collisionPartielle(int indiceDebut, int indiceFin, const element *elementQuiBouge) const
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


void terrain::effetCollisionDeuxElements(element *premierElement, element *deuxiemeElement)
{
    premierElement->effetCollision(deuxiemeElement);
    deuxiemeElement->effetCollision(premierElement);
}


int terrain::testPartieFinie() const
{
    return 0;
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
        }
    }
    return 0;
}
