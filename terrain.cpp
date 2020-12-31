#include "terrain.h"
#include <vector>

terrain::terrain():d_nbBalle{0}, d_precisionCollision{1},
 d_tableauElement{}, d_tableauElementMouvant{} {}

terrain::~terrain() = default;


bool terrain::testCollision() const
{
    bool collisionTrue = false;
    for(int i = 0; i<d_nbBalle;i++)
    {
        int elementCollision = collisionTotale(i, d_precisionCollision);
    }
}



int terrain::collisionTotale(int indiceElementMouvant, int precision) const
{
    int elementCollision;
    int j = precision;          //Pas obligatoire mais plus claire pour les iterations
    position positionElementMouvant = d_tableauElementMouvant[indiceElementMouvant]->getPosition();
    vecteur vecteurElementMouvant = d_tableauElementMouvant[indiceElementMouvant]->getVecteur();

    while(j>0&&elementCollision==-1)
    {
        vecteur vecteurtemp = vecteurElementMouvant*(1/precision);   //Meilleur façon de faire avec Lambda*M + (1-lambda)*M' a faire plus tard
        position positionTemp = positionElementMouvant+vecteurtemp;
        elementCollision = collisionPartielle(0, indiceElementMouvant, positionTemp);
        if(elementCollision==-1)
        {
            elementCollision=collisionPartielle(indiceElementMouvant+1, d_tableauElement.size(), positionTemp);
        }
        j--;
    }
    return elementCollision;
}


int terrain::collisionPartielle(int indiceDebut, int indiceFin, position positionElementMouvant) const
{
    int elementCollision;
    int h = indiceDebut;
    while(h<indiceFin&&elementCollision==-1)
    {
        if(d_tableauElement[h]->collision(positionElementMouvant))
        {
            elementCollision=h;
        }
        h++;
    }
    return elementCollision;
}
