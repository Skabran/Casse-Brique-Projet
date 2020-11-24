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
