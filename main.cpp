#include <iostream>
#include "jeu.h"

using namespace std;

jeu jeuPrincipal{};


void lancerPartie()
{
    //jeuPrincipal.lancerBoucleJeu();
}

void lancerChoixParametres()
{

}

void quitter()
{

}

bool menuPrincipal() {
    cout << endl << "Menu principal : " << endl << endl;
	cout << "1\t - Lancer une partie" << endl;
	cout << "2\t - Parametres partie" << endl;
    int choix;
	cout << "0-2 : ";
    cin >> choix;
    switch (choix) {
        case 1:
            lancerPartie();
            break;
        case 2:
            lancerChoixParametres();
            break;
        case 0:
            quitter();
            return false;
        default:
	        cout << "Entrez un nombre entre 0 et 11" << endl;
    }
    return true;
}

int main()
{
    cout << "Hello " << endl;
    return 0;
}
/*
void test()
{
    balle ball{longueurFenetre / 2, largeurFenetre / 2};
    raquette rq{longueurFenetre / 2, largeurFenetre - 50};
    vector<brique> briques;

    for(int i=0; i < nbBriquesX; ++i)
        for(int j=0; j < nbBriquesY; ++iY)
            briques.emplace_back((i + 1) * (longueurBrique + 3) + 32, (j + 2) * (longueurBrique + 4));

    while(true)
    {
        clear();

        if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
            break;

        ball.miseAJour();
        rq.miseAJour();
        collision(rq, ball);
        for(auto& brique : briques)
            collision(brique, ball);
        briques.erase(remove_if(begin(briques), end(briques),[](const brique& bq)
        {
            return bq.detruite;
        }), end(briques));

        "dessiner la balle";
        "dessiner la raquette";

        for(auto& brique : briques)
            "dessiner les briques;
        "affichage";
    }
}

*/
