#include "Produit.h"

using namespace std;

int Produit::getQuantite(){
    return quantite;
}

float Produit::getPrixUnitaire(){
    return prixUnitaire;
}

std::string Produit::getReference(){
    return reference;
}

std::string Produit::getNom(){
    return nom;
}

std::string Produit::getDateDepot(){
    return ctime(dateDepot);
}

std::string Produit::getDateAchatVente(){
    return ctime(dateAchatVente);
}

void Produit::setQuantite(int q){
    quantite = q;
}
