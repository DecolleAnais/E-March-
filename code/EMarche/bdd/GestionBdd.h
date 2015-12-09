#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include <string>
#include <vector>
#include <algorithm>
#include "LesUtilisateurs.h"
#include "LesProduits.h"
#include "Vue.h"

class GestionBdd
{

private:
    LesUtilisateurs utilisateurs;
    LesProduits produits;
    std::vector<Vue*> vues;
    Utilisateur *utilisateurConnecte;
    std::string ref;

public:
    GestionBdd();

    ~GestionBdd() {
        std::vector<Vue*>::iterator it;
        for(it = vues.begin(); it != vues.end();it++) {
            delete(*it);
        }
        delete(utilisateurConnecte);
    }

    /* FONCTIONS */


    /* incrémenter ref servant de référence unique aux produits */
    void incrementerRef();

    /* nouvelle référence */
    std::string generateReference();

    /* ajouter vue */
    void addVue(Vue* v);

    /* maj vues */
    void update();

    /* connexion */
    void connecterUtilisateur(std::string pseudo, std::string mdp);

    /* déconnexion */
    void deconnecterUtilisateur();

    /* savoir si on est connecté */
    bool isConnecte();

    /* retourner un pointeur vers l'utilisateur connecté */
    Utilisateur* getUtilisateurConnecte();

    /* inscrire */
    void inscrire(std::string monPseudo, std::string monMdp, std::string name, std::string firstname,
                  int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr);

    /*modifier profil */
    void modifierProfil(std::string pseudo, std::string nom, std::string prenom, std::string mail, std::string codePostal, std::string ville);

    /* recherche utilisateur */
    Utilisateur* rechercherUtilisateur(std::string pseudo);

    std::vector<Utilisateur*> rechercherUtilisateurs(std::string pseudo);

    /* Ajouter un produit */
    void nouveauProduit(Produit *p);

    /* ajouter vente */
    void ajouterVente(std::string n, std::string cat, float prix, unsigned int qte, bool etat);
    void ajouterVente(std::string n, std::string cat, float prix, unsigned int qte, bool etat, struct tm date);

    /* ventes en cours */
    std::vector<Produit*> ventesEnCours();

    /* recherche produit */

    Produit* rechercherProduit(std::string ref);

    std::vector<Produit*> rechercherTags(std::string t);

};

#endif // GESTIONBDD_H
