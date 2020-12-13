#ifndef JEU_H
#define JEU_H
#include "terrain.h"

class jeu{
public:
    jeu();
    ~jeu();
    void litTerrain(); //lit un terrain dans un fichier texte
    void lancerBoucleJeu(); //lance le jeu
    void choixParametre(); //permet de changer les parametre du jeu

private :
    terrain d_terrainDeJeu;

};

#endif // JEU_H
