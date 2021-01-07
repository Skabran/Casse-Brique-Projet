#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include <vector>
#include "balle.h"
#include "brique.h"
#include "raquette.h"

/**
Classe représentant le terrain de jeu
*/
class terrain{
public:

///Constructeur par default, créé un terrain avec deux tableaux vides et de longueur 780 pour largeur 800
    terrain();
///Construit un terrain a partir d'un fichier
    terrain(const std::string& nomFichier);
///Destructeur par default du terrain
    ~terrain();


/**
Renvoie le nombre de balle sur le terrain
    @return le nombre de balles du terrain
*/
    int getNbBalle() const;


/**
Renvoie la longueur du terrain
    @return La longueur du terrain
*/
    int getLongueurTerrain() const;


/**
Renvoie la largeur du terrain
    @return La largeur du terrain
*/
    int getLargeurTerrain() const;


/**
Renvoie la précision souhaité pour le calcul des collisions
    @return La precision du calcul de collision souhaité
*/
    int getPrecisionCollision() const;



/**
Renvoi le pointeur d'element de la case i du tableau d'elements
    @param[in] i - l'index du tableau d'element
    @return le pointeur d'element de la case i
*/
    element* getElement(int i) const;


/**
Renvoi le pointeur d'elementMouvant de la case i du tableau d'elementMouvant
    @param[in] i - l'index du tableau d'elementMouvant
    @return le pointeur d'elementMouvant de la case i
*/
    elementMouvant* getElementMouvant(int i) const;


/**
Renvoi le tableau d'elements du terrain
    @return le tableau d'element du terrain
*/
    std::vector<element*> getElement() const;


/**
Renvoi le tableau d'elementMouvants du terrain
    @return le tableau d'elementMouvants du terrain
*/
    std::vector<elementMouvant*> getElementmouvant() const;


/**
Fait passer un tour au terrain
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


/**
Modifie un terrain a partir d'un fichier.
Le format du fichier est le suivant :
nombre de balles
precision de calcul
un nombre de balle correspondant au nombre de balle donné précédement tel que :
    A x y v ° d - balle{x,y,v,°,d}
différents elements avec : B x y - raquette{x,y} et C x y - brique{x,y}
    @param[in] nomFichier - Nom du fichier a partir duquel on construit le terrain
    @return 0 si le fichier c'est lu correctement, 1 si le fichier ne s'est pas lu, 2 si le format du fichier est mauvais
*/
    int litTerrain(const std::string& nomFichier);

private:
/** Longueur du terrain. Par default 800. Possibilité de changer plus tard */
    int d_longueurTerrain;

/** Largeur du terrain. Par default 800. Possibilité de changer plus tard */
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
