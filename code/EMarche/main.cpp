#include <iostream>
#include "Produit.h"

using namespace std;


int main(int argc, char *argv[])
{
    string nom = "";
    string categorie = "";
    float prix = 0;
    unsigned int quantite = 1;
    cout << "Mise en vente de votre produit :" << endl <<"Nom : ";
    cin >> nom;
    cout << "Categorie :";
    cin >> categorie;
    cout << "Prix/Unite :";
    cin >> prix;
    cout << "Quantite :";
    cin >> quantite;

    Produit prod(nom, categorie, prix, quantite);
    prod.affiche(cout);

    return 0;
}

