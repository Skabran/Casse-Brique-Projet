#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "element.h"
#include "elementMouvant.h"
#include "position.h"
/**
Classe représentant le terrain de jeu
*/
class terrain{
public:

///Constructeur par default, créé un terrain avec deux tableaux vides.
    terrain();

///Destructeur par default du terrain
    ~terrain();

/**
Test si l'élément mouvant numéro numeroElement entre en collision avec un element du tableau d'element
    @param[in] numeroElement _ Numero de l'element dont on veut tester les collisions (la balle)
    @return vrai si il y a collision, faux sinon
*/
    bool testCollision(int numeroElement) const;

/**
Test si la partie est finie. C'est a dire plus de brique ou position de la balle sous la position de la raquette
    @return vrai si la partie est finie, faux sinon
*/
    bool testPartieFinie() const;

/**
Deplace tout les element mouvant du terrain en appelant la fonction deplacer de chaque element mouvant
*/
    void deplacerElementMouvant();

/**
Ajoute un element au tableau d'element du terrain
*/
    void ajouterElementFixe();

/**
Ajoute un element mouvant dans le tableau d'element mouvant et dans le tableau d'element du terrain
*/
    void ajouterElementMouvant();

private:
/** Tableau comprenant tout les elements du terrain */
    std::vector<element*> d_tableauElement;

/** Tableau comprenant tout les elements mouvant du terrain */
    std::vector<elementMouvant*> d_tableauElementMouvant;

};

#endif // TERRAIN_H
