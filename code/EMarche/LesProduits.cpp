#include "LesProduits.h"

using namespace std;

vector<Produit*> LesProduits::getListProduits() {
    return lesProduits;
}

int LesProduits::size() {
    return nbElems;
}

void LesProduits::addProduit(Produit* p) {
    lesProduits.push_back(p);
    nbElems++;
}

void LesProduits::supprimerProduit(int ref) {

}

Produit LesProduits::getProduit(int ref) {

}

void LesProduits::toString() {
    vector<Produit*>::iterator it;
    cout << "Liste de produits :" << endl;
    for (it=lesProduits.begin(); it != lesProduits.end(); ++it) {
        (*it)->affiche(cout);
        cout << ' ';
        cout << "----------------------------------------" << endl;
    }
    if(it == lesProduits.end()) {
        cout << "hello" << endl;
    }
    cout << "hum" << endl;
}
