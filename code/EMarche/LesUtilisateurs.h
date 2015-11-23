#ifndef LESUTILISATEURS_H
#define LESUTILISATEURS_H

#include <vector>
#include "Utilisateur.h"

class LesUtilisateurs {

private:
   std::vector<Utilisateur*> lesUtilisateurs;

public:
   /* Constructeur */
    LesUtilisateurs() {

    }

    LesUtilisateurs(const LesUtilisateurs &other);
    LesUtilisateurs &operator= (const LesUtilisateurs &other) {

    }

    /* Destructeur */
    virtual ~LesUtilisateurs() {
        for(size_t i = 0; i < lesUtilisateurs.size(); i++) {
            lesUtilisateurs[i] = 0;
             delete(lesUtilisateurs[i]);
        }
    }

    /* Fonctions */
    void add(Utilisateur* u);
    void supprimer(std::string pseudo);
    Utilisateur* getUtilisateur(std::string pseudo);
    int getNbUtilisateurs();
    void affiche();



};

#endif // LESUTILISATEURS_H
