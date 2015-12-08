#include "GestionBdd.h"
#include <iostream>

using namespace std;

GestionBdd::GestionBdd() : utilisateurConnecte(new Utilisateur())
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
        update();
    }
}

/* déconnexion */
void GestionBdd::deconnecterUtilisateur() {
    utilisateurConnecte = NULL;
}

/* savoir si on est connecté */
bool GestionBdd::isConnecte() {
    return utilisateurConnecte->getPseudo() != "" ? true : false;
}

/* retourner un pointeur vers l'utilisateur connecté */
Utilisateur* GestionBdd::getUtilisateurConnecte() {
    return utilisateurConnecte;
}

/* inscription */
void GestionBdd::inscrire(string monPseudo, string monMdp, string name, string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, string mail, string adr)
{
    utilisateurs.add(new Utilisateur(monPseudo, monMdp, name, firstname, jourNaiss, moisNaiss, anneeNaiss, mail, adr));
}

/* Ajouter un nouveau produit */
void GestionBdd::nouveauProduit(Produit *p){
    produits.addProduit(p);
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

/* ajouter produit en vente */
void GestionBdd::ajouterVente(string n, string cat, float prix, unsigned int qte, bool etat) {
    string vendeur = utilisateurConnecte->getPseudo();
    Produit *p = new Produit(vendeur, n, cat, prix, qte, etat);
    utilisateurConnecte->addVente(p);
    produits.addProduit(p);
    update();
}

/* ventes en cours */
vector<Produit*> GestionBdd::ventesEnCours() {
    return produits.getListProduits();
}

/* recherche produit par nom */
vector<Produit*> GestionBdd::rechercherProduitNom(string nom) {
    return produits.getProduitsNom(nom);
}

/* Rechercher un produit par référence */
Produit* GestionBdd::rechercherProduit(string ref) {
    return produits.getProduit(ref);
}

/* Rechercher les tags d'un produit */
vector<Produit*> GestionBdd::rechercherTags(string t){
    // Transformation des caractères du tag en minuscules
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    return produits.rechercherTags(t);
}

/* Rechercher tous les produits d'une catégorie */
vector<Produit*> GestionBdd::rechercherCategorie(string c){
    // Transformation des caractères de la catégorie en minuscules
    std::transform(c.begin(), c.end(), c.begin(), ::tolower);
    return produits.rechercherCategorie(c);
}
