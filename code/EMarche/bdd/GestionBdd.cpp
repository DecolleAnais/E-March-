#include "GestionBdd.h"

using namespace std;

GestionBdd::GestionBdd()
{

}

/* Fonctions */

/* inscription */
void GestionBdd::inscrire(string monPseudo, string monMdp, string name, string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, string mail, string adr)
{
    Utilisateur u(monPseudo, monMdp, name, firstname, jourNaiss, moisNaiss, anneeNaiss, mail, adr);
    utilisateurs.add(&u);
}

/* recherche utilisateur */
vector<Utilisateur*> GestionBdd::rechercherUtilisateur(string pseudo) {
    vector<Utilisateur*> tab;
    tab.push_back(utilisateurs.getUtilisateur(pseudo));
    return tab;
}

/* recherche produit */
vector<Produit*> GestionBdd::rechercherProduit(string nom) {
    vector<Produit*> tab;
    //tab.push_back(produits.getProduit(nom));
    return tab;
}
