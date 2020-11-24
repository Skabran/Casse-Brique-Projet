#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "element.h"
#include "elementMouvant.h"
#include "position.h"

class terrain{
public:
    terrain();
    ~terrain();
    bool testCollision() const;
    bool testPartieFinie() const;
    void deplacerElementMouvant();  //Appelle deplacer dans tous les elements du tableau d'élément mouvant

private:
    std::vector<element> d_tableauElement;
    std::vector<elementMouvant> d_tableauElementMouvant;

};

#endif // TERRAIN_H
