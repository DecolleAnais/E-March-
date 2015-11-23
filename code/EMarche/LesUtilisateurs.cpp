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
            delete(lesUtilisateurs[i]);
            trouve = true;
        }
        i++;
    }
}

Utilisateur* LesUtilisateurs::getUtilisateur(string pseudo) {

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


