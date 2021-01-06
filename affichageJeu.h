#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H
#include "graphics.h"
#include "balle.h"
#include "brique.h"

/**
Classe permettant l'affichage du jeu et du terrain
*/
class affichageJeu{
public:
///Constructeur par default de l'affichage du jeu
    affichageJeu();
///Destructeur par default de l'affichage du jeu
    ~affichageJeu();


/**
Affiche un ecran de victoire au joueur
*/
    void afficheVictoire() const;


/**
Affiche un ecran de defaite au joueur
*/
    void afficheDefaite() const;

/**
Affiche une balle
    @param[in] balleAAfficher - La balle que l'on désire tracer
*/
    void afficheBalle(const balle& balleAAfficher) const;


/**
Affiche une brique
    @param[in] briqueAAfficher - La brique que l'on désire tracer
*/
    void afficheBrique(const brique& briqueAAfficher) const;

private:

    /** longueur de l'affichage */
    int d_longueurAffichage;

    /** largeur affichage */
    int d_largeurAffichage;
};

#endif // AFFICHAGEJEU_H
