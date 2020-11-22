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

private:
    std::vector<std::vector<position>> d_grille;
    std::vector<element> d_tableauElements;

};

#endif // TERRAIN_H
