#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include "Categorie.h"
#include "EtatVente.h"
#include "VenteEnchere.h"
#include "VenteNormale.h"

class Produit {

private:
    std::string vendeur;
    Categorie *categorie;
    std::string nom;
    std::string reference;
    float prixUnitaire;
    unsigned int quantite;
    struct tm dateDepot;
    struct tm dateAchatVente;
    EtatVente *etatVente;
    std::vector<std::string> tags;

public:

    Produit(std::string n, std::string cat, float prix, unsigned int qte, bool etat) : nom(n),
        reference("ref"), prixUnitaire(prix), quantite(qte) {
        // Initialisation de l'état de vente
        if(etat == 0){ // cas d'une vente normale
            etatVente = new VenteNormale(etat);
        }else{
            etatVente = new VenteEnchere(etat);
            etatVente->setPrixActuel(prix);
        }
        // Initialisation de la catégorie
        categorie = new Categorie(cat);
        // Initialisation de la date de dépôt au jour actuel
        time_t maintenant;
        time(&maintenant);
        dateDepot = *localtime(&maintenant);
        dateDepot.tm_year = dateDepot.tm_year + 1900;
        // Initialisation de dateVenteAchat
        dateAchatVente.tm_mday = 0;
        dateAchatVente.tm_mon = 0;
        dateAchatVente.tm_year = 0;
        // Ajout des tags
        ajouterTag(n);
        ajouterTag(categorie->getNom());
    }

    Produit(std::string v, std::string n, std::string cat, float prix, unsigned int qte, bool etat) : vendeur(v), nom(n),
        reference("ref"), prixUnitaire(prix), quantite(qte) {
        // Initialisation de l'état de vente
        if(etat == 0){ // cas d'une vente normale
            etatVente = new VenteNormale(etat);
        }else{
            etatVente = new VenteEnchere(etat);
            etatVente->setPrixActuel(prix);
        }
        // Initialisation de la catégorie
        categorie = new Categorie(cat);
        // Initialisation de la date de dépôt au jour actuel
        time_t maintenant;
        time(&maintenant);
        dateDepot = *localtime(&maintenant);
        dateDepot.tm_year = dateDepot.tm_year + 1900;
        // Initialisation de dateVenteAchat
        dateAchatVente.tm_mday = 0;
        dateAchatVente.tm_mon = 0;
        dateAchatVente.tm_year = 0;
        // Ajout des tags
        ajouterTag(n);
        ajouterTag(categorie->getNom());
    }

    Produit(std::string n, std::string cat, float prix, unsigned int qte, bool etat, struct tm dateLimite) : nom(n),
        reference("ref"), prixUnitaire(prix), quantite(qte) {
        // Initialisation de l'état de vente
        if(etat == 0){ // cas d'une vente normale
            etatVente = new VenteNormale(etat);
        } else { // sinon, vente aux enchères
            etatVente = new VenteEnchere(etat);
            etatVente->setDateLimite(dateLimite);
            etatVente->setPrixActuel(prix);
        }
        // Initialisation de la catégorie
        categorie = new Categorie(cat);
        // Initialisation de la date de dépôt au jour actuel
        time_t maintenant;
        time(&maintenant);
        dateDepot = *localtime(&maintenant);
        dateDepot.tm_year = dateDepot.tm_year + 1900;
        // Initialisation de dateVenteAchat
        dateAchatVente.tm_mday = 0;
        dateAchatVente.tm_mon = 0;
        dateAchatVente.tm_year = 0;
        // Ajout des tags
        ajouterTag(n);
        ajouterTag(categorie->getNom());
    }

    /* destructeur */
    ~Produit() {}

    /* Fonctions get */
    std::string getVendeur();
    unsigned int getQuantite();
    float getPrixUnitaire();
    std::string getReference();
    std::string getNom();
    std::string getCategorie();
    std::string getDateDepot();
    std::string getDateAchatVente();
    std::string getEtatVente();
    float getPrixActuel();
    std::string getTags();
    std::vector<std::string> getTagsVector();
    std::string getDateLimite();

    /* Fonctions set */
    void setReference(std::string r);
    void setQuantite(unsigned int q);
    void setDateVenteAchat(int jour, int mois, int annee);

    /* Fonctions */
    void augmenterEnchere(int prix);
    void ajouterTag(std::string t);

    /* Fonctions d'affichage */
    void decrit(std::ostream &os) {
        os << "------Fiche produit-------\nReference : " << getReference() << "\nNom : " << getNom() << "\nCategorie : " << getCategorie()
           << "\nPrix unitaire : " << getPrixUnitaire() << "\nType de vente : " << getEtatVente() << "\nQuantite : " << getQuantite()
           << "\nDate de depot : " << getDateDepot();

        if(etatVente->venteEnCours() == true){
            os << "\nPrix actuel : " << getPrixActuel() << "\nDate limite de l'enchère : " << etatVente->getDateLimite();
        }

        os << "\nTags : " << getTags();
    }

    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    void affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif
