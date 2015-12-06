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

/* recherche produit */
vector<Produit*> GestionBdd::rechercherProduit(string nom) {
    vector<Produit*> tab;
    //tab.push_back(produits.getProduit(nom));
    return tab;
}
