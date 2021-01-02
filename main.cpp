#include <iostream>
#include "jeu.h"

using namespace std;

void quitter()
{

}

bool menuPrincipal(jeu& jeu1) {
    cout << endl << "Menu principal : " << endl << endl;
	cout << "1\t - Lance une partie" << endl;
	cout << "2\t - Parametres partie" << endl;
    int choix;
	cout << "0-2 : ";
    cin >> choix;
    switch (choix) {
        case 1:
            jeu1.lancerBoucleJeu();
            break;
        case 2:
            jeu1.choixParametre();
            break;
        case 0:
            quitter();
            return false;
        default:
	        cout << "Entrez un nombre entre 0 et 2" << endl;
    }
    return true;
}


int main()
{
    jeu jeuPrincipal{};
    menuPrincipal(jeuPrincipal);
    return 0;
}
