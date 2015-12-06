#include "LesUtilisateurs.h"
#include <iostream>

using namespace std;

void LesUtilisateurs::add(Utilisateur* u) {
    lesUtilisateurs.push_back(u);
    nbUtilisateurs++;
}

void LesUtilisateurs::supprimer(string pseudo) {
    bool trouve = false;
    unsigned int i = 0;
    while(!trouve && i < lesUtilisateurs.size()) {
        if(pseudo == lesUtilisateurs[i]->getPseudo()) {
            /* échange de l'élément avec le dernier, puis suppression du dernier */
            Utilisateur* tmp = lesUtilisateurs[lesUtilisateurs.size()-1];
            lesUtilisateurs[lesUtilisateurs.size()-1] = lesUtilisateurs[i];
            lesUtilisateurs[i] = tmp;
            lesUtilisateurs.pop_back();
            nbUtilisateurs--;
            trouve = true;
        }
        i++;
    }
}

Utilisateur* LesUtilisateurs::getUtilisateur(string pseudo) {
    unsigned int i = 0;
    while(i < lesUtilisateurs.size()) {
        if(pseudo == lesUtilisateurs[i]->getPseudo()) {
            return lesUtilisateurs[i];
        }
        i++;
    }
    return NULL;
}

vector<Utilisateur*> LesUtilisateurs::getUtilisateurs(string chaine) {
    vector<Utilisateur*> res;
    vector<Utilisateur*>::iterator it;
    for(it = lesUtilisateurs.begin();it != lesUtilisateurs.end();it++) {
        if((*it)->getPseudo().find(chaine) != string::npos) {
            res.push_back(*it);
            cout << "+";
        }
    }
    return res;
}

int LesUtilisateurs::getNbUtilisateurs() {
    return nbUtilisateurs;
}

void LesUtilisateurs::affiche() {
    vector<Utilisateur*>::iterator it;
    for(it = lesUtilisateurs.begin();it != lesUtilisateurs.end();it++) {
        (*it)->affiche(cout);
    }
}


