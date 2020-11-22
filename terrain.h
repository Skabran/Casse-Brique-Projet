#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "element.h"
#include "position.h"

class terrain{
public:
    terrain();
    terrain(int longueur, int largeur); // pas utilisé pour le moment
    ~terrain();
    void modifierGrille(int longueur, int largeur); // potentiellmeent d'autres variables a ajouter
    bool testCollision();
    bool testPartieFinie();

private:
    std::vector<std::vector<elements>> d_grille;

};

#endif // TERRAIN_H
