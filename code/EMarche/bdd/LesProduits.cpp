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

vector<Produit*> LesProduits::getProduitsRef(string chaine) {
    vector<Produit*> res;
    vector<Produit*>::iterator it;
    for(it = lesProduits.begin();it != lesProduits.end();it++) {
        if((*it)->getReference().find(chaine) != string::npos) {
            res.push_back(*it);
        }
    }
    return res;
}

vector<Produit*> LesProduits::getProduitsNom(string chaine) {
    vector<Produit*> res;
    vector<Produit*>::iterator it;
    for(it = lesProduits.begin();it != lesProduits.end();it++) {
        if((*it)->getNom().find(chaine) != string::npos) {
            res.push_back(*it);
        }
    }
    return res;
}

vector<Produit*> LesProduits::getProduitsCat(string chaine) {
    vector<Produit*> res;
    vector<Produit*>::iterator it;
    for(it = lesProduits.begin();it != lesProduits.end();it++) {
        if((*it)->getCategorie().find(chaine) != string::npos) {
            res.push_back(*it);
        }
    }
    return res;
}

void LesProduits::toString() {
    vector<Produit*>::iterator it;
    for (it=lesProduits.begin(); it != lesProduits.end(); it++) {
        (*it)->affiche(cout);
        //cout << " ----------------------------------------" << endl;
    }
}
