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
    Utilisateur* utilisateurConnecte;


public:
    GestionBdd();

    /* Fonctions */

    /* ajouter vue */
    void addVue(Vue* v);

    /* maj vues */
    void update();

    /* connexion */
    void connecterUtilisateur(std::string pseudo, std::string mdp);

    /* inscrire */
    void inscrire(std::string monPseudo, std::string monMdp, std::string name, std::string firstname,
                  int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr);

    std::vector<Utilisateur*> rechercherUtilisateurs(std::string pseudo);

    /* recherche utilisateur */
    Utilisateur* rechercherUtilisateur(std::string pseudo);

    /* ajouter vente */
    void ajouterVente(std::string n, std::string cat, float prix, unsigned int qte, bool etat);

    /* recherche produit */
    std::vector<Produit*> rechercherProduitRef(std::string ref);

    std::vector<Produit*> rechercherProduitNom(std::string nom);

    std::vector<Produit*> rechercherProduitCat(std::string cat);

};

#endif // GESTIONBDD_H
