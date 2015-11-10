#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ctime>
#include "Categorie.h"

class Produit
{
public:
    Produit() : name("cat"), nom("truc"), reference("#0"), prixUnitaire(2), quantite(1),
        date(std::time(NULL)), dateDepot(&date), dateAchatVente(&date) {}

    int getQuantite();
    float getPrixUnitaire();
    std::string getReference();
    std::string getNom();
    std::string getDateDepot();
    std::string getDateAchatVente();
    void setQuantite(int q);

private:

    Categorie name;
    std::string nom;
    std::string reference;
    float prixUnitaire;
    int quantite;
    const std::time_t date;
    const std::time_t* dateDepot;
    const std::time_t* dateAchatVente;
};

#endif
