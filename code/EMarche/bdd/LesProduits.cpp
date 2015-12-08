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
    int i = 0;
    for(i = 0; i < nbElems; i++) {
        if(lesProduits[i]->getReference().compare(ref) == 0) {
            lesProduits.erase(lesProduits.begin()+i);
            i = nbElems;
        }
    }
    nbElems--;
}

void LesProduits::supprimerProduit(Produit* p) {
    int i = 0;
    for(i = 0; i < nbElems; i++) {
        if(lesProduits[i]->getReference().compare(p->getReference()) == 0) {
            lesProduits.erase(lesProduits.begin()+i);
            i = nbElems;
        }
    }
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

/* Rechercher tous les produits tagués par t */
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

/* Rechercher tous les produits tagés par une liste de tags */
vector<Produit*> LesProduits::rechercherTags(vector<string> tags) {
    vector<Produit*> tab;
    vector<string>::iterator itTags;
    vector<Produit*>::iterator it;
    vector<string>::iterator itTagsProd;
    for(itTags = tags.begin(); itTags != tags.end(); itTags++) {
        string str = (*itTags);
        for (it = lesProduits.begin(); it != lesProduits.end(); it++) {
            vector<string> donno = (*it)->getTagsVector();
            for (itTagsProd = donno.begin(); itTagsProd != donno.end(); itTagsProd++) {
                // Récupération des tags du produit courant
                string s = (*itTagsProd);
                // Transformation de la chaîne des tags en miniscule
                std::transform(s.begin(), s.end(), s.begin(), ::tolower);
                std::transform(str.begin(), str.end(), str.begin(), ::tolower);
                // Recherche de str dans la chaîne des t
                if(s.compare(str) == 0) {
                    tab.push_back((*it));
                }
            }
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

void LesProduits::toString() {
    vector<Produit*>::iterator it;
    for (it=lesProduits.begin(); it != lesProduits.end(); it++) {
        (*it)->affiche(cout);
    }
}

vector<Produit*> LesProduits::triPrixCroissant (vector<Produit*> produits){
    vector<Produit*> liste = produits;
    vector<Produit*>::iterator it, it2;
    for (it = liste.begin(); it != liste.end(); it++) {
        double prix = (*it)->getPrixActuel();
        for(it2 = liste.begin(); it2 != liste.end(); it2++){
            double prix2 = (*it2)->getPrixActuel();
            if(prix2 > prix){
                swap((*it), (*it2));
            }
        }
    }
    return liste;
}
