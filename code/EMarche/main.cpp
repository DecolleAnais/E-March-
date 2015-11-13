#include <iostream>
#include <list>
#include "Produit.h"

using namespace std;

int main(void)
{
    /*Produit p;
    p.setQuantite(2);
    cout << "nom " << p.getNom() << endl;
    cout << "ref " << p.getReference() << endl;
    cout << "qt " << p.getQuantite() << endl;
    cout << "pu " << p.getPrixUnitaire() << endl;
    cout << "depot " << p.getDateDepot() << endl;
    cout << "achat " << p.getDateAchatVente() << endl;*/
//    string nom = "";
//    string categorie = "";
//    float prix = 0;
//    unsigned int quantite = 1;
//    cout << "Mise en vente de votre produit :" << endl <<"Nom : ";
//    cin >> nom;
//    cout << "Categorie :" << endl;
//    cin >> categorie;
//    cout << "Prix/Unite :" << endl;
//    cin >> prix;
//    cout << "Quantite :" << endl;
//    cin >> quantite;

//    Produit prod(nom, categorie, prix, quantite);

      list<Produit> mylist;
      Produit p("fdf",string("fdg"),5.6,5);
      mylist.push_front(p);
      mylist.push_front(p);
      mylist.push_front(p);
      mylist.push_front(p);
      mylist.push_front(p);
      mylist.push_front(p);
      cout << "Liste de produits :\n";
      for (list<Produit>::iterator it=mylist.begin(); it != mylist.end(); ++it) {
          it->affiche(cout);
          cout << ' ';
          cout << "----------------------------------------\n";
      }
      cout << "----------------------------------------\n";

    return 0;
}

