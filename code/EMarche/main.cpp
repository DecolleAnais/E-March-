#include <iostream>
#include "Produit.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*Produit p;
    p.setQuantite(2);
    cout << "nom " << p.getNom() << endl;
    cout << "ref " << p.getReference() << endl;
    cout << "qt " << p.getQuantite() << endl;
    cout << "pu " << p.getPrixUnitaire() << endl;
    cout << "depot " << p.getDateDepot() << endl;
    cout << "achat " << p.getDateAchatVente() << endl;*/
    string nom = "";
    string categorie = "";
    float prix = 0;
    unsigned int quantite = 1;
    cout << "Mise en vente de votre produit :" << endl <<"Nom : ";
    cin >> nom;
    cout << "Categorie :" << endl;
    cin >> categorie;
    cout << "Prix/Unite :" << endl;
    cin >> prix;
    cout << "Quantite :" << endl;
    cin >> quantite;

    Produit prod(nom, categorie, prix, quantite);
    prod.affiche(cout);

    return 0;
}

