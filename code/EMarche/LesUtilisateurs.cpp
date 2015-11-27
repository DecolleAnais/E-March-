#include "LesUtilisateurs.h"
#include <iostream>

using namespace std;

void LesUtilisateurs::add(Utilisateur* u) {
    lesUtilisateurs.push_back(u);
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

int LesUtilisateurs::getNbUtilisateurs() {
    return lesUtilisateurs.size();
}

void LesUtilisateurs::affiche() {
    vector<Utilisateur*>::iterator it;
    for(it = lesUtilisateurs.begin();it != lesUtilisateurs.end();it++) {
        (*it)->Utilisateur::affiche(cout);
    }
}


