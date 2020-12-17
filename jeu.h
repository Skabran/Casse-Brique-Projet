#ifndef JEU_H
#define JEU_H
#include "terrain.h"

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
Initialise un terrain a partir d'un fichier
*/
    void litTerrain(); //lit un terrain dans un fichier texte

/**
Lance la boucle de jeu
*/
    void lancerBoucleJeu(); //lance le jeu

/**
Permet de changer les parametres de la partie
*/
    void choixParametre(); //permet de changer les parametre du jeu

private :
/** terrain sur lequel le jeu se passe */
    terrain d_terrainDeJeu;

};

#endif // JEU_H
