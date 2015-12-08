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
     ~LesUtilisateurs() {
        std::vector<Utilisateur*>::iterator it;
        for(it = lesUtilisateurs.begin(); it != lesUtilisateurs.end();it++) {
            delete(*it);
        }
    }

    /* Fonctions */

    /* ajoute un pointeur vers l'utilisateur u dans le vector lesUtilisateurs */
    void add(Utilisateur* u);

    /* supprime un utilisateur via son pseudo */
    void supprimer(std::string pseudo);

    /* retourne un pointeur vers l'utlisateur de ce pseudo */
    Utilisateur* getUtilisateur(std::string pseudo);

    /* retourne un vector contenant les pointeurs vers tous les utilisateurs dont le pseudo contient la chaine demandée */
    std::vector<Utilisateur*> getUtilisateurs(std::string chaine);

    /* retourne vrai si l'utilisateur avec ce pseudo et mot de passe existe, faux sinon */
    bool existeUtilisateur(std::string pseudo, std::string mdp);

    /* retourne le nombre d'utilisateurs */
    int getNbUtilisateurs();

    /* affiche tous les utilisateurs */
    void affiche();



};

#endif // LESUTILISATEURS_H
