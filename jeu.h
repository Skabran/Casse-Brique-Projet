#ifndef JEU_H
#define JEU_H
#include "terrain.h"
#include "affichageJeu.h"
#include "calculateur.h"

/**
Classe du jeu
*/
class jeu{
public:
///Constructeur par default du jeu. Initialise un terrain de jeu par default
    jeu();
///Destructeur par default du jeu
    ~jeu();


/**
Lance la partie
*/
    void lancerPartie();


/**
Permet au joueur de choisir un terrain
*/
    void choixTerrain();

/**
Affiche le menu principal et permet a l'utilisateur de choisir quoi faire
*/
    void menuPrincipal();

/**
Initialise le terrain du jeu a partir d'un fichier et l'ajoute a la liste des terrains
    @param[in] nomFichier - Nom du fichier a lire
    return 0 si le fichier c'est lu correctement, 1 si le fichier ne s'est pas lu, 2 si le format du fichier est mauvais
*/
    int litTerrain(const std::string& nomFichier); //lit un terrain dans un fichier texte


/**
Permet de changer les parametres de la partie.
*/
    void choixParametre(); //permet de changer les parametre du jeu


/**
Quitte le jeu
*/
    void quitterJeu();


/**
Renvoie le terrain de jeu
    @return Le terrain de jeu
*/
    terrain getTerrain() const;


/**
Demande à l'afficheur d'afficher le terrain
*/
    void afficherLeTerrain() const;


/**
Renvoie la liste des noms de fichiers de terrains de jeu
    @return La liste des terrains de jeu
*/
    std::vector<std::string> getListeTerrain() const;


/**
Regarde dans le dossier du projet si il y a d'autre fichier .txt et les ajoute a la liste de terrain
*/
    void rempliListeTerrain();


private :
/** terrain sur lequel le jeu se passe */
    terrain d_terrainDeJeu;
/** Affichage du jeu */
    affichageJeu d_affichage;
/** Liste des terrains disponible. d_listeTerrain[0] est le terrain par default */
    std::vector<std::string> d_listeTerrain;
};

#endif // JEU_H
