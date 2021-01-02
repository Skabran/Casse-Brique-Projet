#include "terrain.h"
#include "element.h"
#include "elementMouvant.h"
#include "balle.h"
#include <vector>

terrain::terrain():d_nbBalle{0}, d_precisionCollision{1},
 d_tableauElement{}, d_tableauElementMouvant{} {}

terrain::~terrain() = default;


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

element* terrain::getElementMouvant(int i) const
{
    return d_tableauElementMouvant[i];
}


//  A changer a déplacer dans le jeu !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool terrain::testCollision()
{
    bool collisionStatus = false;
    for(int i = 0; i<d_nbBalle;i++)
    {
        int elementCollision = collisionTotale(i, d_precisionCollision);
        if(elementCollision!=-1)    //Si il n'y a pas eu de collision, on ne fais rien
        {
            effetCollisionDeuxElements(d_tableauElement[i], d_tableauElement[elementCollision] ); //on applique l'effet de la collision entre la balle et l'element qu'elle rencontre
        }
    }
    return false;
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
