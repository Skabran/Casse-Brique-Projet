#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "element.h"
#include "elementMouvant.h"
#include "position.h"

class terrain{
public:
    terrain();
    terrain(int longueur, int largeur); // pas utilisé pour le moment
    ~terrain();
    void modifierGrille(int longueur, int largeur); // potentiellement d'autres variables a ajouter
    bool testCollision() const;
    bool testPartieFinie() const;
    void deplacerElementMouvant();  //Appelle deplacer dans tous les elements du tableau d'élément mouvant

private:
    std::vector<element> d_tableauElement;
    std::vector<elementMouvant> d_tableauElementMouvant;

};

#endif // TERRAIN_H
