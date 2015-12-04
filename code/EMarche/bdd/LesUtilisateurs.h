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
    void add(Utilisateur* u);
    void supprimer(std::string pseudo);
    Utilisateur* getUtilisateur(std::string pseudo);
    int getNbUtilisateurs();
    void affiche();



};

#endif // LESUTILISATEURS_H
