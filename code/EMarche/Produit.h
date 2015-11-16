#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ctime>
#include <sstream>
#include "Categorie.h"

class Produit {

private:
    std::string categorie;
    std::string nom;
    std::string reference;
    float prixUnitaire;
    unsigned int quantite;
    struct tm dateDepot;
    struct tm dateAchatVente;

public:
    Produit() : categorie("cat"), nom("truc"), reference("#0"), prixUnitaire(2), quantite(1) {
        // Initialisation de la date de dépôt au jour actuel
        time_t maintenant;
        time(&maintenant);
        dateDepot = *localtime(&maintenant);
        dateDepot.tm_year = dateDepot.tm_year + 1900;
        // Initialisation de dateVenteAchat
        dateAchatVente.tm_mday = 0;
        dateAchatVente.tm_mon = 0;
        dateAchatVente.tm_year = 0;
    }

    Produit(std::string n, std::string cat, float prix, unsigned int qte) : categorie(cat),
        nom(n), reference("ref"), prixUnitaire(prix), quantite(qte) {
        // Initialisation de la date de dépôt au jour actuel
        time_t maintenant;
        time(&maintenant);
        dateDepot = *localtime(&maintenant);
        dateDepot.tm_year = dateDepot.tm_year + 1900;
        // Initialisation de dateVenteAchat
        dateAchatVente.tm_mday = 0;
        dateAchatVente.tm_mon = 0;
        dateAchatVente.tm_year = 0;
    }

    unsigned int getQuantite();
    float getPrixUnitaire();
    std::string getReference();
    std::string getNom();
    std::string getCategorie();
    std::string getDateDepot();
    std::string getDateAchatVente();
    void setQuantite(unsigned int q);
    void setDateVenteAchat(int jour, int mois, int annee);
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
