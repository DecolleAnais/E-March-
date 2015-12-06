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

/* Rechercher un produit avec sa référence */
Produit* LesProduits::getProduit(string ref) {
    int i = 0;
    while(i < nbElems) {
        if(lesProduits[i]->getReference().compare(ref) == 0) {
            return lesProduits[i];
        }
        i++;
    }
    return NULL;
}

/* Rechercher tous les produits tagés par t */
vector<Produit*> LesProduits::rechercherTags(string t){
    vector<Produit*> tab;
    vector<Produit*>::iterator it;
    for (it = lesProduits.begin(); it != lesProduits.end(); it++) {
        // Récupération des tags du produit courant
        string tags = (*it)->getTags();
        // Transformation de la chaîne des tags en miniscule
        std::transform(tags.begin(), tags.end(), tags.begin(), ::tolower);
        // Recherche de t dans la chaîne des tags
        if(tags.find(t) != string::npos) {
            tab.push_back((*it));
        }
    }
    return tab;
}

/* Rechercher tous les produits d'une catégorie */
vector<Produit*> LesProduits::rechercherCategorie(string c){
    vector<Produit*> tab;
    vector<Produit*>::iterator it;
    for (it = lesProduits.begin(); it != lesProduits.end(); it++) {
        // Récupération de la categorie du produit courant
        string categorie = (*it)->getCategorie();
        // Transformation de la catégorie récupérée en miniscule
        std::transform(categorie.begin(), categorie.end(), categorie.begin(), ::tolower);
        // Recherche de c
        if(categorie.find(c) != string::npos) {
            tab.push_back((*it));
        }
    }
    return tab;
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
    }
}
