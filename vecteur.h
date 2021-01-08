#ifndef VECTEUR_H
#define VECTEUR_H

/**
Classe représentant le vecteur vitesse
*/
class vecteur{
public :
///Constructeur de base du vecteur vitesse = 1 et angle = 0
    vecteur();
///Constructeur du vecteur vitesse = vitesse et angle = angle
    vecteur(double vitesse, double angle);
///Destructeur par default du vecteur
    ~vecteur();

/**
Retourne la norme du vecteur vitesse
    @return d_vitesse - norme du vecteur
*/
    double getVitesse() const;

/**
Retourne la valeur de l'angle du vecteur
    @return d_angle - valeur de l'angle
*/
    double getAngle() const;


/**
Change la vitesse du vecteur
    @param[in] vitesse - nouvelle vitesse
*/
    void changeVitesse(double vitesse);

/**
Change l'angle du vecteur
    @param[in] angle - nouvel angle
*/
    void changeAngle(double angle);

/**
Multiplie la norme du vecteur vitesse par un coeficient coef
    @param[in] coef - coefficient multiplicateur
*/
    void multiplieVitesse(double coef);

/**
Inverse l'angle du vecteur horizontalement
*/
    void inverseHorizontale();

/**
Inverse l'angle du vecteur verticalement
*/
    void inverseVertical();

/**
Operateur * : multiplie un vecteur par une valeur coef. Multiplie en fait uniquement la vitesse
    @param[in] coef - valeur multiplicative
    @return le vecteur dont la vitesse a été multiplié par le coef
*/
    vecteur operator*(double coef);


/**
Operateur = : remplace les la vitesse et l'angle du premier vecteur par ceux du second
    @param[in] vect - vecteur a copier
    @return le vecteur vitesse dont les parametres sont changés
*/
    vecteur& operator=(const vecteur& vect);

private :
/** Valeur de la vitesse du vecteur */
    double d_vitesse;
/** Valeur de l'angle du vecteur */
    double d_angle;

};

/**
Operateur * : multiplie un coef par un vecteur
    @param[in] coef - valeur multiplicative
    @param[in] vect - vecteur à multiplier
    @return le vecteur dont la vitesse a été multiplié par le coef
*/
vecteur operator*(double coef,vecteur& vect);

#endif // VECTEUR_H
