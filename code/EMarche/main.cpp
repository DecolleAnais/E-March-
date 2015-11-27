#include <iostream>
#include "Produit.h"
#include "Utilisateur.h"
#include "LesUtilisateurs.h"
#include "Categorie.h"
#include "LesProduits.h"
#include "VenteEnchere.h"

using namespace std;

int main()
{

    /* Test entrée caractéristiques produit

    Produit p;
    string nom = "nom";
    string categorie = "categorie";
    float prix = 2;
    unsigned int quantite = 1;
    cout << "Mise en vente de votre produit :" << endl <<"Nom : ";
    cin >> nom;
    cout << "Categorie :" << endl;
    cin >> categorie;
    cout << "Prix/Unite :" << endl;
    cin >> prix;
    cout << "Quantite :" << endl;
    cin >> quantite;*/

    /* Test affichage 1 produit */
    Produit prod("produit1", "categorieProd", 2.5, 1);
    Produit prod1("produit2", "categorieProd", 2.5, 1);
    Produit prod2("produit3", "categorieProd", 2.5, 1);
    LesProduits lesProduits;
    lesProduits.addProduit(&prod);
    lesProduits.addProduit(&prod1);
    lesProduits.addProduit(&prod2);
    lesProduits.toString();
    lesProduits.supprimerProduit("ref");
    lesProduits.supprimerProduit(&prod1);
    lesProduits.toString();
    cout << "****************getter*****************" << endl;
    lesProduits.getProduit("ref").affiche(cout);
    lesProduits.supprimerProduit("ref");

    /* Test affichage plusieurs utilisateurs */
    Utilisateur user("Graou","mdp","Decolle","Anais",18,4,1994,"graou@orange.fr","3, rue du biscuit");
    Utilisateur user2("Graou2","mdp","Mallinger","Magalie",0,0,0,"graou@orange.fr","12, rue du chocolat");
    Utilisateur user3("Graou3","mdp","Aou","Gra",18,4,1994,"graou@orange.fr","6, rue de l'hiver");

    LesUtilisateurs users;
    users.add(&user);
    users.add(&user2);
    users.add(&user3);

    users.affiche();



    return 0;
}

