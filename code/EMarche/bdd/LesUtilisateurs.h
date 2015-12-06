#ifndef LESUTILISATEURS_H
#define LESUTILISATEURS_H

#include <vector>
#include "Utilisateur.h"

class LesUtilisateurs {

private:
   std::vector<Utilisateur*> lesUtilisateurs;
   int nbUtilisateurs;

public:
   /* Constructeur */
    LesUtilisateurs() {

    }

    /* Destructeur */
    virtual ~LesUtilisateurs() {}

    /* Fonctions */

    /* ajoute un pointeur vers l'utilisateur u dans le vector lesUtilisateurs */
    void add(Utilisateur* u);

    /* supprime un utilisateur via son pseudo */
    void supprimer(std::string pseudo);

    /* retourne un pointeur vers l'utlisateur de ce pseudo */
    Utilisateur* getUtilisateur(std::string pseudo);

    /* retourne un vector contenant les pointeurs vers tous les utilisateurs dont le pseudo contient la chaine demandée */
    std::vector<Utilisateur*> getUtilisateurs(std::string chaine);

    /* retourne le nombre d'utilisateurs */
    int getNbUtilisateurs();

    /* affiche tous les utilisateurs */
    void affiche();



};

#endif // LESUTILISATEURS_H
