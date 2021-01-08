#include <iostream>
#include "jeu.h"
#include "affichageJeu.h"

using namespace std;


void testGraphics()
{
    opengraphsize(780,800);
    affichageJeu aff{};
//    balle bal{400,600,10,90,30};
//    brique briq{400,200};
//    raquette raq{400,780};
//    bal.afficheElement(aff);
//    briq.afficheElement(aff);
//    raq.afficheElement(aff);
//    jeu j{};
//    j.afficherLeTerrain();
    terrain t{};
    t.litTerrain("terrainParDefault");
   aff.afficheTerrain(t);
    //t.boucleDeJeu(aff);
   getch();
    closegraph();


}

int main()
{
    jeu jeuPrincipal{};
    testGraphics();
    jeuPrincipal.menuPrincipal();
    return 0;
}
