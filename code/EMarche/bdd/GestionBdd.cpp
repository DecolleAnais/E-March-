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

/* inscription */
void GestionBdd::inscrire(string monPseudo, string monMdp, string name, string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, string mail, string adr)
{
    Utilisateur u(monPseudo, monMdp, name, firstname, jourNaiss, moisNaiss, anneeNaiss, mail, adr);
    utilisateurs.add(&u);
    utilisateurs.affiche();
}

/* Ajouter un nouveau produit */
void GestionBdd::nouveauProduit(Produit *p){
    produits.addProduit(p);
}

/* recherche utilisateurs */
vector<Utilisateur*> GestionBdd::rechercherUtilisateurs(string pseudo) {
    //vector<Utilisateur*> tab;
    cout << "recherche";
    return utilisateurs.getUtilisateurs(pseudo);
    //return tab;
}

/* recherche utilisateur */
Utilisateur* GestionBdd::rechercherUtilisateur(string pseudo) {
    return utilisateurs.getUtilisateur(pseudo);
}

/* Rechercher un produit */
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
