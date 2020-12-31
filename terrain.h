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
Renvoi le nombre de balle sur le terrain
*/
    int getNbBalle() const;


/**
Renvoi la précision souhaité pour le calcul des collisions
*/
    int getPrecisionCollision() const;


/**
Test si la ou les balles entre en collision avec d'autre element du terrain.
Elle changent leur vecteur vitesse si c'est le cas.
    @return vrai si il y a collision, faux sinon
*/
    bool testCollision() const;


/**
Test la collision entre un element i et le reste du terrain avec une précision donnée.
Renvoi l'indice de l'element avec lequel il y a collision
    @param[in] indiceElementMouvant - Indice de l'element que l'on doit tester
    @param[in] precision - precision des test de collision souhaité
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionTotale(int indiceElementMouvant, int precision) const;


/**
Test la collision entre deux indice d'un tableau.
Permet a collisionTotal de ne pas calculer la collision de l'element avec lui même.
    @param[in] indiceDebut - indice de départ des test
    @param[in] indiceFin - indice de fin des test
    @param[in] positionElementMouvant - position de l'element a tester
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionPartielle(int indiceDebut, int indiceFin, position positionElementMouvant) const;


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
/** Nombre de balles dans le jeu */
    int d_nbBalle;

/** Precision de souhaité pour les test de collision */
    int d_precisionCollision;

/** Tableau comprenant tout les elements du terrain */
    std::vector<element*> d_tableauElement;

/** Tableau comprenant tout les elements mouvant du terrain */
    std::vector<elementMouvant*> d_tableauElementMouvant;

};

#endif // TERRAIN_H
