#include "Produit.h"

using namespace std;

unsigned int Produit::getQuantite(){
    return quantite;
}

float Produit::getPrixUnitaire(){
    return prixUnitaire;
}

string Produit::getReference(){
    return reference;
}

string Produit::getNom(){
    return nom;
}

string Produit::getCategorie(){
    return categorie;
}

string Produit::getDateDepot(){
    string result;
    stringstream sstm;

    sstm << dateDepot.tm_mday << "/" << dateDepot.tm_mon << "/" << dateDepot.tm_year;
    result = sstm.str();

    return result;
}

string Produit::getDateAchatVente(){
    string result;
    stringstream sstm;

    sstm << dateAchatVente.tm_mday << "/" << dateAchatVente.tm_mon << "/" << dateAchatVente.tm_year;
    result = sstm.str();

    return result;
}

void Produit::setQuantite(unsigned int q){
    quantite = q;
}

void Produit::setDateVenteAchat(int jour, int mois, int annee){
    dateAchatVente.tm_mday = jour;
    dateAchatVente.tm_mon = mois;
    dateAchatVente.tm_year = annee;
}
