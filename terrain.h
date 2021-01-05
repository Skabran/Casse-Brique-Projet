#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "element.h"
#include "elementMouvant.h"
#include "balle.h"
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
Renvoi le pointeur d'element de la case i du tableau d'elements
*/
    element* getElement(int i) const;


/**
Renvoi le pointeur d'element de la case i du tableau d'elements mouvant
*/
    element* getElementMouvant(int i) const;



/**
Fait passer un tour au terrain
    @return vrai si il y a collision, faux sinon
*/
    void boucleDeJeu() ;


/**
Test la collision entre un element et le reste du terrain avec une précision donnée.
Renvoi l'indice de l'element avec lequel il y a collision
    @param[in] elementMouvant - element que l'on doit tester
    @param[in] precision - precision des test de collision souhaité
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionTotale(int indiceElementQuiBouge, int precision) const;


/**
Test la collision entre deux indice d'un tableau.
Permet a collisionTotal de ne pas calculer la collision de l'element avec lui même.
    @param[in] indiceDebut - indice de départ des test
    @param[in] indiceFin - indice de fin des test
    @param[in] positionElementMouvant - position de l'element a tester
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionPartielle(int indiceDebut, int indiceFin, const element *elementQuiBouge) const;


/**
Test si deux element rentre en collision
    @param[in] premierElement - Premier element a faire entrer en collision. Si possible l'element mouvant.
    @param[in] deuxiemeElement - Second element a faire entrer en collision.
    @return True si il y a collision
*/
    bool testCollisionDeuxElement(const element *premierElement,const element *deuxiemeElement) const;


/**
Demande a deux element d'appliquer leurs effets de collision
    @param[in] premierElement - Premier element a faire entrer en collision. Si possible l'element mouvant.
    @param[in] deuxiemeElement - Second element a faire entrer en collision.
*/
    void effetCollisionDeuxElements(element *premierElement, element *deuxiemeElement);


/**
Test si la partie est finie. C'est a dire plus de brique ou position de la balle sous la position de la raquette
    @return 0 si la partie n'est pas finie, 1 si il n'y a plus de brique, 2 si le joueur perd
*/
    int testPartieFinie() const;


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
/** Longueur du terrain */
    int d_longueurTerrain;

/** Largeur du terrain */
    int d_largeurTerrain;

/** Nombre de balles dans le jeu */
    int d_nbBalle;

/** Precision de souhaité pour les test de collision */
    int d_precisionCollision;

/** Tableau comprenant tout les elements du terrain */
    std::vector<element*> d_tableauElement;

/** Tableau comprenant tout les elements mouvant du terrain */
    std::vector<elementMouvant*> d_tableauElementMouvant;
//Ajouter longueur et largeur du terrain
};

#endif // TERRAIN_H
