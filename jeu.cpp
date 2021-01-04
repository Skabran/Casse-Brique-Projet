#include "jeu.h"
#include "terrain.h"
#include "affichageJeu.h"

jeu::jeu() : d_terrainDeJeu{}, d_affichage{} {}

jeu::~jeu() = default;


void jeu::menuPrincipal()
{
    int choix;

    std::cout << std::endl << "Menu principal : " << std::endl << std::endl;
	std::cout << "1\t - Lancer une partie" << std::endl;
	std::cout << "2\t - Changer les parametres partie" << std::endl;
	std::cout << "3\t - Choisir un terrain" << std::endl;
	std::cout << "0\t - Quitter" << std::endl << std::endl;
	std::cout << "0-3 : ";
    std::cin >> choix;
    switch (choix) {
        case 1:
            lancerPartie();
            break;
        case 2:
            choixParametre();
            break;
        case 3:
            choixTerrain();
        case 0:
            quitterJeu();
        default:
	        std::cout << "Entrez un nombre entre 0 et 3" << std::endl;
    }
}

void jeu::lancerPartie()
{
    int resultatPartie=0;
    while(resultatPartie==0)
    {

        d_terrainDeJeu.boucleDeJeu();
        resultatPartie=d_terrainDeJeu.testPartieFinie();
    }
    if(resultatPartie==1)
    {
        d_affichage.afficheVictoire();
    }
    else
    {
        d_affichage.afficheDefaite();
    }

    quitterJeu();
}


void jeu::choixParametre()
{

}


void jeu::quitterJeu()
{

}

void jeu::choixTerrain()
{

}
