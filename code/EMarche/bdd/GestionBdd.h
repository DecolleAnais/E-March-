#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include <string>
#include <vector>
#include "LesUtilisateurs.h"
#include "LesProduits.h"
#include "Vue.h"

class GestionBdd
{

private:
    LesUtilisateurs utilisateurs;
    LesProduits produits;
    std::vector<Vue*> vues;


public:
    GestionBdd();

    /* Fonctions */

    /* ajouter vue */
    void addVue(Vue* v);

    /* maj vues */
    void update();

    /* inscrire */
    void inscrire(std::string monPseudo, std::string monMdp, std::string name, std::string firstname,
                  int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr);

    std::vector<Utilisateur*> rechercherUtilisateurs(std::string pseudo);

    /* recherche utilisateur */
    Utilisateur* rechercherUtilisateur(std::string pseudo);

    std::vector<Produit*> rechercherProduit(std::string nom);

};

#endif // GESTIONBDD_H
