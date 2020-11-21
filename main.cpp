#include jeu.h
#include <iostream>

using namespace std;

jeu jeuPrincipal{};


void lancerPartie()
{

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
    cin >> i;
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
    cout << "Hello world!" << endl;
    return 0;
}
