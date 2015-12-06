#include "GestionBdd.h"
#include <iostream>

using namespace std;

GestionBdd::GestionBdd()
{

}

/* Fonctions */

/* ajouter vue */
void GestionBdd::addVue(Vue* v) {
    vues.push_back(v);
}

/* maj vues */
void GestionBdd::update() {
    for(unsigned int i = 0;i < vues.size();i++)
        vues[i]->update();
}

/* PARTIE UTILISATEURS */

/* connexion */
void GestionBdd::connecterUtilisateur(string pseudo, string mdp) {
    bool valide = utilisateurs.existeUtilisateur(pseudo, mdp);
    if(valide) {
        utilisateurConnecte = utilisateurs.getUtilisateur(pseudo);
    }
}

/* inscription */
void GestionBdd::inscrire(string monPseudo, string monMdp, string name, string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, string mail, string adr)
{
    utilisateurs.add(new Utilisateur(monPseudo, monMdp, name, firstname, jourNaiss, moisNaiss, anneeNaiss, mail, adr));
}

/* recherche utilisateurs */
vector<Utilisateur*> GestionBdd::rechercherUtilisateurs(string pseudo) {
    return utilisateurs.getUtilisateurs(pseudo);
}

/* recherche utilisateur */
Utilisateur* GestionBdd::rechercherUtilisateur(string pseudo) {
    return utilisateurs.getUtilisateur(pseudo);
}

/* PARTIE PRODUITS */

void GestionBdd::ajouterVente(string n, string cat, float prix, unsigned int qte, bool etat) {
    produits.addProduit(new Produit(n, cat, prix, qte, etat));
}

/* recherche produit par référence */
vector<Produit*> GestionBdd::rechercherProduitRef(string ref) {
    return produits.getProduitsRef(ref);
}

/* recherche produit par nom */
vector<Produit*> GestionBdd::rechercherProduitNom(string nom) {
    return produits.getProduitsNom(nom);
}

/* recherche produit par catégorie */
vector<Produit*> GestionBdd::rechercherProduitCat(string cat) {
    return produits.getProduitsCat(cat);
}
