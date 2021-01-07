#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H
#include "graphics.h"
#include "terrain.h"
#include "brique.h"
#include "enveloppe.h"
#include "calculateur.h"

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
Affiche une enveloppe rectangulaire
*/
    void afficheEnveloppe(const enveloppe& env) const;


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


/**
Affiche une raquette
    @param[in] raquetteAAfficher - La raquette que l'on désire tracer
*/
    void afficheRaquette(const raquette& raquetteAAfficher) const;


/**
Affiche le terrain de Jeu
    @param[in] terrainAAfficher - Le terrain que l'on désire afficher
*/
    void afficheTerrain(const terrain& terrainAAfficher) const;

private:

    /** longueur de l'affichage */
    int d_longueurAffichage;

    /** largeur affichage */
    int d_largeurAffichage;
};

#endif // AFFICHAGEJEU_H
