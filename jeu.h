#ifndef JEU_H
#define JEU_H
#include "terrain.h"

class jeu{
public:
    jeu();
    ~jeu();
    void iniTerrain();
    void lancerPartie(); //boucle de jeu

private :
    terrain terrainDeJeu;

};

#endif // JEU_H
