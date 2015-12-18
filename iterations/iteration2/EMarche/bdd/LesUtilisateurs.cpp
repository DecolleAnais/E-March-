#include "LesUtilisateurs.h"
#include <iostream>

using namespace std;

void LesUtilisateurs::add(Utilisateur* u) {
    lesUtilisateurs.push_back(u);
    nbUtilisateurs++;
}

void LesUtilisateurs::supprimer(string pseudo) {
    bool trouve = false;
    int i = 0;
    while(!trouve && i < nbUtilisateurs) {
        if(pseudo == lesUtilisateurs[i]->getPseudo()) {
            /* échange de l'élément avec le dernier, puis suppression du dernier */
            Utilisateur* tmp = lesUtilisateurs[nbUtilisateurs-1];
            lesUtilisateurs[nbUtilisateurs-1] = lesUtilisateurs[i];
            lesUtilisateurs[i] = tmp;
            lesUtilisateurs.pop_back();
            nbUtilisateurs--;
            trouve = true;
        }
        i++;
    }
}

Utilisateur* LesUtilisateurs::getUtilisateur(string pseudo) {
    int i = 0;
    while(i < nbUtilisateurs) {
        if(pseudo == lesUtilisateurs[i]->getPseudo()) {
            return lesUtilisateurs[i];
        }
        i++;
    }
    return NULL;
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

bool LesUtilisateurs::existeUtilisateur(string pseudo, string mdp) {
    bool existe = false;
    vector<Utilisateur*>::iterator it;
    for(it = lesUtilisateurs.begin();it != lesUtilisateurs.end();it++) {
        if((*it)->getPseudo().compare(pseudo) == 0 && (*it)->getMdp().compare(mdp) == 0)
            existe = true;
    }
    return existe;
}


