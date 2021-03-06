#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include <vector>
#include "balle.h"
#include "brique.h"
#include "raquette.h"

/**
Classe repr�sentant le terrain de jeu
*/
class terrain{
public:

///Constructeur par default, cr�� un terrain avec deux tableaux vides et de longueur 780 pour largeur 800
    terrain();
///Construit un terrain a partir d'un fichier
    terrain(const std::string& nomFichier);
///Destructeur du terrain
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
Renvoie la pr�cision souhait� pour le calcul des collisions
    @return La precision du calcul de collision souhait�
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
    void boucleDeJeu(const affichageJeu& afficheur) ;

/**
Fonction qui g�re la boucle de collision d'un elementMouvant avec le reste du tableau d'element
    @param[in] indexElemM - index de l'elementMouvant dans le tableau d'elementMouvant
*/
    void collisionElemM(int indexElemM);


/**
Appell� si il y a collision.
Fais parcourir la distance qui s�pare les deux element, calcul la distance restante a parcourir
et appelle recursivement collisionElemM pour v�rifier si il n'y a pas d'autre element en collisions
sur le chemin restant
    @param[in,out] elemM - L'elementMouvant qui en percute un autre
    @param[in,out] elem - l'element fixe qui est percut�
    @param[in,out] distanceAParcourir - distance qu'il reste a parcourir a l'elementMouvant
*/
    void approchePasAPas(elementMouvant* elemM, element* elem, double& distanceAParcourir);


/**
Test la collision entre un elementMouvant et le reste du terrain avec une pr�cision donn�e.
Renvoi l'indice de l'element avec lequel il y a collision
    @param[in] elementMouvant - element que l'on doit tester
    @param[in] precision - precision des test de collision souhait�
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionToutTableauElement(int indiceElementQuiBouge, int precision) const;


/**
Test la collision entre deux indice d'un tableau.
Permet a collisionTotal de ne pas calculer la collision de l'element avec lui m�me.
    @param[in] indiceDebut - indice de d�part des test
    @param[in] indiceFin - indice de fin des test
    @param[in] positionElementMouvant - position de l'element a tester
    @return indice du premier element en collision. -1 si pas de collision.
*/
    int collisionPartieDuTableau(int indiceDebut, int indiceFin, const element *elementQuiBouge) const;


/**
Test si deux element rentre en collision
    @param[in] premierElement - Premier element a faire entrer en collision. Si possible l'element mouvant.
    @param[in] deuxiemeElement - Second element a faire entrer en collision.
    @return True si il y a collision
*/
    bool testCollisionDeuxElement(const element *premierElement,const element *deuxiemeElement) const;


/**
Demande a une element mouvant et un element d'appliquer leurs collisions
    @param[in] premierElement - ElementMouvant qui rentre en collision
    @param[in] deuxiemeElement - element qui subit une collision
*/
    void effetCollisionDeuxElements(elementMouvant *premierElement, element *deuxiemeElement);


/**
Test si la partie est finie. C'est a dire plus de brique ou position de la balle sous la position de la raquette
    @return 0 si la partie n'est pas finie, 1 si il n'y a plus de brique, 2 si le joueur perd
*/
    int testPartieFinie() const;


/**
Deplace l'element i du tableau d'elementMouvant
    @param[in] i - index de l'element a d�placer
*/
    void deplacerElementMouvant(unsigned int i);


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
un nombre de balle correspondant au nombre de balle donn� pr�c�dement tel que :
    A x y v � d - balle{x,y,v,�,d}
diff�rents elements avec : B x y - raquette{x,y} et C x y - brique{x,y}
    @param[in] nomFichier - Nom du fichier a partir duquel on construit le terrain
    @return 0 si le fichier c'est lu correctement, 1 si le fichier ne s'est pas lu, 2 si le format du fichier est mauvais
*/
    int litTerrain(const std::string& nomFichier);

private:
/** Longueur du terrain. Par default 800. Possibilit� de changer plus tard */
    int d_longueurTerrain;

/** Largeur du terrain. Par default 800. Possibilit� de changer plus tard */
    int d_largeurTerrain;

/** Nombre de balles dans le jeu */
    int d_nbBalle;

/** Precision de souhait� pour les test de collision */
    int d_precisionCollision;

/** Tableau comprenant tout les elements du terrain */
    std::vector<element*> d_tableauElement;

/** Tableau comprenant tout les elements mouvant du terrain */
    std::vector<elementMouvant*> d_tableauElementMouvant;

};

#endif // TERRAIN_H
