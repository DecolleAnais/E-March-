#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ctime>
#include <sstream>
#include "Categorie.h"

class Produit
{

private:

    std::string categorie;
    std::string nom;
    std::string reference;
    float prixUnitaire;
    unsigned int quantite;
    const std::time_t date;
    const std::time_t* dateDepot;
    const std::time_t* dateAchatVente;

public:
    Produit() : categorie("cat"), nom("truc"), reference("#0"), prixUnitaire(2), quantite(1),
        date(std::time(NULL)), dateDepot(&date), dateAchatVente(&date) {}

    Produit(std::string n, std::string cat, float prix, unsigned int qte);

    unsigned int getQuantite();
    float getPrixUnitaire();
    std::string getReference();
    std::string getNom();
    std::string getCategorie();
    std::string getDateDepot();
    std::string getDateAchatVente();
    void setQuantite(unsigned int q);
    std::string toString();

    void   decrit(std::ostream &os) {
        os << "------Fiche produit-------\nReference : " << getReference() << "\nNom : " << getNom() << "\nCategorie : " << getCategorie()
           << "\nPrix unitaire : " << getPrixUnitaire() << "\nQuantite : " << getQuantite() << "\nDate de depot : " << getDateDepot();
    }

    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif
