#include "Produit.h"

using namespace std;


Produit::Produit(string n, Categorie cat, float prix, unsigned int qte) :
categorie(cat), nom(n), prixUnitaire(prix), quantite(qte), reference("ref"), date(time(NULL)) {

}

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

string Produit::getDateDepot(){
    return ctime(dateDepot);
}

string Produit::getDateAchatVente(){
    return ctime(dateAchatVente);
}

void Produit::setQuantite(unsigned int q){
    quantite = q;
}
