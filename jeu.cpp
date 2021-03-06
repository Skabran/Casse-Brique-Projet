#include "jeu.h"


jeu::jeu() : d_terrainDeJeu{}, d_affichage{}, d_listeTerrain{}
{
    std::cout<<litTerrain("terrainParDefault");
}

jeu::~jeu() = default;


void jeu::menuPrincipal()
{
    int choix;

    std::cout << std::endl << std::endl << std::endl;
    std::cout << std::endl << "\t\t== Menu Principal == " << std::endl << std::endl;
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
            break;
        case 0:
            quitterJeu();
            break;
        default:
	        std::cout << "Entrez un nombre entre 0 et 3" << std::endl;
    }
}

void jeu::lancerPartie()
{
    opengraphsize(d_terrainDeJeu.getLongueurTerrain()+10,d_terrainDeJeu.getLargeurTerrain()); //+10 car la fenetre s'ouvre un petit peut trop a gauche pour une raison que j'ignore
    d_affichage.afficheTerrain(d_terrainDeJeu);
    int resultatPartie=0;
    while(resultatPartie==0)
    {
        d_terrainDeJeu.boucleDeJeu(d_affichage);
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


terrain jeu::getTerrain() const
{
    return d_terrainDeJeu;
}


void jeu::afficherLeTerrain() const
{
    d_affichage.afficheTerrain(getTerrain());
}

void jeu::choixTerrain()
{
    rempliListeTerrain();
    //A faire (donne le choix du terrain via un num�ro
}

int jeu::litTerrain(const std::string& nomFichier)
{
    d_listeTerrain.push_back(nomFichier);
    return d_terrainDeJeu.litTerrain(nomFichier);
}

std::vector<std::string> jeu::getListeTerrain() const
{
    return d_listeTerrain;
}

void jeu::rempliListeTerrain()
{
    //A faire
}
