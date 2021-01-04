#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H

/**
Permet l'affichage du jeu et du terrain
*/
class affichageJeu{
public:
///Constructeur par default de l'affichage du jeu
    affichageJeu();
///Destructeur par default de l'affichage du jeu
    ~affichageJeu();


/**
Affiche un ecran de victoire au joueur
*/
    void afficheVictoire();


/**
Affiche un ecran de defaite au joueur
*/
    void afficheDefaite();

private:

    /** longueur de l'affichage */
    int d_longueurAffichage;

    /** largeur affichage */
    int d_largeurAffichage;
};

#endif // AFFICHAGEJEU_H
