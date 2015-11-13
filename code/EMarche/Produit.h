#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ctime>
#include "Categorie.h"

class Produit
{
public:
    Produit() : categorie("cat"), nom("truc"), reference("#0"), prixUnitaire(2), quantite(1),
        date(std::time(NULL)), dateDepot(&date), dateAchatVente(&date) {}

    Produit(std::string n, Categorie cat, float prix, unsigned int qte);

    unsigned int getQuantite();
    float getPrixUnitaire();
    std::string getReference();
    std::string getNom();
    std::string getDateDepot();
    std::string getDateAchatVente();
    void setQuantite(unsigned int q);

private:

    Categorie categorie;
    std::string nom;
    std::string reference;
    float prixUnitaire;
    unsigned int quantite;
    const std::time_t date;
    const std::time_t* dateDepot;
    const std::time_t* dateAchatVente;
};

#endif
