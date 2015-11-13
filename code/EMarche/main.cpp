#include <iostream>
#include "Produit.h"

using namespace std;

int main(int argc, char *argv[])
{
    Produit p;
    p.setQuantite(2);
    cout << "nom " << p.getNom() << endl;
    cout << "ref " << p.getReference() << endl;
    cout << "qt " << p.getQuantite() << endl;
    cout << "pu " << p.getPrixUnitaire() << endl;
    cout << "depot " << p.getDateDepot() << endl;
    cout << "achat " << p.getDateAchatVente() << endl;

    /*cout << "Mise en vente de votre produit :" << endl <<"Nom : ";
    cin >>*/

    return 0;
}

