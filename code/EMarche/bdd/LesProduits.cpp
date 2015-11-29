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

void LesProduits::supprimerProduit(string ref) {
    int pos = 0;
    int i = 0;
    for(i = 0; i < nbElems; i++) {
        if(lesProduits[i]->getReference().compare(ref) == 0) {
            pos = i;
            i = nbElems;
        }
    }
    lesProduits.erase(lesProduits.begin()+pos);
    nbElems--;
}

void LesProduits::supprimerProduit(Produit* p) {
    int pos = 0;
    int i = 0;
    for(i = 0; i < nbElems; i++) {
        if(lesProduits[i]->getReference().compare(p->getReference()) == 0) {
            pos = i;
            i = nbElems;
        }
    }
    lesProduits.erase(lesProduits.begin()+pos);
    nbElems--;
}

Produit LesProduits::getProduit(string ref) {
    int pos = 0;
    int i = 0;
    for(i = 0; i < nbElems; i++) {
        if(lesProduits[i]->getReference().compare(ref) == 0) {
            pos = i;
            i = nbElems;
        }
    }
    return *lesProduits[pos];
}

void LesProduits::toString() {
    vector<Produit*>::iterator it;
    for (it=lesProduits.begin(); it != lesProduits.end(); it++) {
        (*it)->affiche(cout);
        //cout << " ----------------------------------------" << endl;
    }
}
