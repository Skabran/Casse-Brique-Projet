#ifndef JEU_H
#define JEU_H
#include "terrain.h"
#include "affichageJeu.h"
#include "calculateur.h"

/**
Classe du jeu
*/
class jeu{
public:
///Constructeur par default du jeu. Initialise un terrain de jeu par default
    jeu();

///Destructeur par default du jeu
    ~jeu();


/**
Lance la partie
*/
    void lancerPartie();


/**
Permet au joueur de choisir un terrain
*/
    void choixTerrain();

/**
Affiche le menu principal et permet a l'utilisateur de choisir quoi faire
*/
    void menuPrincipal();

/**
Initialise un terrain a partir d'un fichier
*/
    void litTerrain(); //lit un terrain dans un fichier texte


/**
Permet de changer les parametres de la partie.
*/
    void choixParametre(); //permet de changer les parametre du jeu


/**
Quitte le jeu
*/
    void quitterJeu();

private :
/** terrain sur lequel le jeu se passe */
    terrain d_terrainDeJeu;
/** Affichage du jeu */
    affichageJeu d_affichage;
/** Calculateur du jeu */
    calculateur d_calculBot;

};

#endif // JEU_H
