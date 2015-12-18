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

/*!
* \class Produit
* \brief Cette classe gère le stockage d'un produit
*/
class Produit {

private:
    //! \brief Nom du vendeur
    std::string vendeur;
    //! \brief Catégorie
    Categorie *categorie;
    //! \brief Nom du produit
    std::string nom;
    //! \brief Référence unique
    std::string reference;
    //! \brief Prix unitaire
    float prixUnitaire;
    //! \brief Quantité
    unsigned int quantite;
    //! \brief Date de dépôt sur le site
    struct tm dateDepot;
    //! \brief Date d'achat ou de vente
    struct tm dateAchatVente;
    //! \brief Etat du produit (enchères ou normale)
    EtatVente *etatVente;
    //! \brief Mots-clés qui identifient le produit
    std::vector<std::string> tags;

public:

    /*!
    * \brief Constructeur de la classe Produit
    * \brief Utilisé pour les ventes normales
    * \param v - Nom du vendeur
    * \param n - Nom du produit
    * \param cat - Nom de la catégorie
    * \param prix - Prix unitaire
    * \param qte - Quantité
    * \param etat - Type de la vente (enchère ou normale)
    */
    Produit(std::string v, std::string n, std::string cat, float prix,
            unsigned int qte, bool etat) : vendeur(v), nom(n),
        prixUnitaire(prix), quantite(qte) {
        // Initialisation de l'état de vente
        if(etat == 0){ // cas d'une vente normale
            etatVente = new VenteNormale(etat);
        } else {
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
        // Ajout des tags (nom et catégorie)
        ajouterTag(n);
        ajouterTag(categorie->getNom());
    }

    /*!
     * \brief Constructeur de la classe Produit
     * \brief Utilisé pour les ventes aux enchères
     * \param v - Nom du vendeur
     * \param n - Nom du produit
     * \param cat - Nom de la catégorie
     * \param prix - Prix unitaire
     * \param qte - Quantité
     * \param etat - Type de la vente (enchère ou normale)
     * \param dateLimite - Date limite de l'enchère
     */
    Produit(std::string v,std::string n, std::string cat, float prix,
            unsigned int qte, bool etat, struct tm dateLimite) : vendeur(v),
        nom(n), prixUnitaire(prix), quantite(qte) {
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
        // Ajout des tags (nom et catégorie)
        ajouterTag(n);
        ajouterTag(categorie->getNom());
    }

    /*!
     * \brief Destructeur de la classe Produit
     */
    ~Produit() {
        delete(categorie);
        delete(etatVente);
    }

    /* ----- Fonctions get ----- */

    /*!
     * \fn std::string getVendeur()
     * \brief Retourne le nom du vendeur
     * \return Un string contenant le nom du vendeur
     */
    std::string getVendeur();

    /*!
     * \fn unsigned int getQuantite()
     * \brief Retourne la quantité en stock du produit
     * \return Un entier positif représentant la quantité
     */
    unsigned int getQuantite();

    /*!
     * \fn float getPrixUnitaire()
     * \brief Retourne le prix unitaire
     * \return Un float représentant le prix unitaire
     */
    float getPrixUnitaire();

    /*!
     * \fn std::string getReference()
     * \brief Retourne la référence unique
     * \return Un string contenant la référence
     */
    std::string getReference();

    /*!
     * \fn std::string getNom()
     * \brief Retourne le nom du produit
     * \return Un string contenant le nom du produit
     */
    std::string getNom();

    /*!
     * \fn std::string getCategorie()
     * \brief Retourne la catégorie
     * \return Un string contenant la catégorie
     */
    std::string getCategorie();

    /*!
     * \fn std::string getDateDepot()
     * \brief Retourne la date de dépôt
     * \return Un string contenant la date de dépôt
     */
    std::string getDateDepot();

    /*!
     * \fn std::string getDateAchatVente()
     * \brief Retourne la date d'achat ou de vente
     * \return Un string contenant la date d'achat ou de vente
     */
    std::string getDateAchatVente();

    /*!
     * \fn std::string getEtatVente()
     * \brief Retourne le type de la vente (enchère ou normale)
     * \return Un string contenant l'état de la vente
     */
    std::string getEtatVente();

    /*!
     * \fn float getPrixActuel()
     * \brief Retourne le prix actuel
     * \return Un float représenant le prix actuel
     */
    float getPrixActuel();

    /*!
     * \fn std::string getTags()
     * \brief Retourne les mots-clés qui identifient le produit
     * \return Un string contenant les mots-clés
     */
    std::string getTags();

    /*!
     * \fn std::vector<std::string> getTagsVector(
     * \brief Retourne la liste des mots-clés
     * \return Un vector de string contenant le liste des mots-clés
     */
    std::vector<std::string> getTagsVector();

    /*!
     * \fn std::string getDateLimite()
     * \brief Retourne la date limite de l'enchère
     * \return Un string contenant la date limite de l'enchère
     */
    std::string getDateLimite();

    /* ----- Fonctions set ----- */

    /*!
     * \fn void setReference(std::string r)
     * \brief Cette fonction attribue une référence unique au produit
     * \param r Un string contenant la référence
     */
    void setReference(std::string r);

    /*!
     * \fn void setQuantite(unsigned int q)
     * \brief Cette fonction fixe la quantité disponible
     * \param q - Nouvelle quantité
     */
    void setQuantite(unsigned int q);

    /*!
     * \fn void setDateVenteAchat(int jour, int mois, int annee)
     * \brief Cette fonction fixe la date d'achat ou de vente
     * \param jour - Jour
     * \param mois - Mois
     * \param annee - Année
     */
    void setDateVenteAchat(int jour, int mois, int annee);

    /* ----- Fonctions ----- */

    /*!
     * \fn void augmenterEnchere(int prix)
     * \brief Cette fonction permet d'augenter le prix d'une enchère
     * \param prix - Nouveau prix de l'enchère
     */
    void augmenterEnchere(int prix);

    /*!
     * \fn void ajouterTag(std::string t)
     * \brief Ajouter un nouveau mot-clé pour désigner le produit
     * \param t - Nouveau mot-clé
     */
    void ajouterTag(std::string t);

    /* ----- Fonctions d'affichage ----- */

    /*!
     * \fn void decrit(std::ostream &os)
     * \brief Cette méthode permet d'écrire la description d'un produit
     * dans un flot de sortie donnée en paramètre
     * \param os - le flot de sortie dans lequel la description sera écrite
     */
    void decrit(std::ostream &os) {
        os << "------Fiche produit-------\nReference : " << getReference()
           << "\nNom : " << getNom() << "\nCategorie : " << getCategorie()
           << "\nPrix unitaire : " << getPrixUnitaire() << "\nType de vente : "
           << getEtatVente() << "\nQuantite : " << getQuantite()
           << "\nDate de depot : " << getDateDepot();

        // Si le produit est aux enchères, on ajoute les éléments spécifiques aux enchères
        if(etatVente->typeVente() == true){
            os << "\nPrix actuel : " << getPrixActuel() << "\nDate limite de l'enchère : "
               << etatVente->getDateLimite();
        }

        os << "\nTags : " << getTags();
    }

    /*!
     * \fn std::string decrit()
     * \brief Cette méthode retourne la description du produit dans
     * une chaîne de caractères
     * \return la description du produit dans une chaîne de caractères
     */
    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    /*!
     * \fn void affiche(std::ostream &os)
     * \brief Cette méthode permet d'afficher la description du produit,
     * suivie d'un passage à la ligne, dans un flot de sortie donné en paramètre
     * \param os - le flot de sortie dans lequel la description sera affichée
     */
    void affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif
