#ifndef LESPRODUITS_H
#define LESPRODUITS_H

#include "Produit.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdarg>

/*!
 * \class LesProduits
 * \brief Cette classe gère la liste des produits
 */
class LesProduits {

private:
    //! Liste des produits
    std::vector<Produit*> lesProduits;
    //! Nombre de produits
    int nbElems;

public:
    /*!
     * \brief Constructeur de la classe LesProduits
     */
    LesProduits() : lesProduits(), nbElems(0) {}

    /*!
     * Destructeur de la classe LesProduis
     */
    ~LesProduits() {
        std::vector<Produit*>::iterator it;
        for(it = lesProduits.begin(); it != lesProduits.end();it++) {
            delete(*it);
        }
    }

    /*!
     * \brief Cette fonction retourne le liste des produits
     * \return Un vector contenant la liste des produits
     */
    std::vector<Produit*> getListProduits();

    /*!
     * \brief Cette fonction retourne la taille de la liste
     * \brief Elle correspond également au nombre de produits
     * \return
     */
    int size();

    /*!
     * \brief Cette fonction permet d'ajouter un produit à la lfin de la liste
     * \param p - Nouveau produit à ajouter
     */
    void addProduit(Produit* p);

    /*!
     * \brief Cette fonction permet de supprimer un produit selon sa référence
     * \param ref - Référence du produit à supprimer
     */
    void supprimerProduit(std::string ref);

    /*!
     * \brief Cette fonction permet de supprimer un produit
     * \param p - Produit à supprimer
     */
    void supprimerProduit(Produit* p);

    /*!
     * \brief Cette fonction retourne une liste de produits dont le nom contient chaine
     * \param chaine - Nom du produit à rechercher
     * \return Un vector de produits
     */
    std::vector<Produit*> getProduitsNom(std::string chaine);

    /*!
     * \brief Retourne le produit dont la référence est passée en paramètre
     * \param ref - Référence du produit à rechercher
     * \return Un produit
     */
    Produit* getProduit(std::string ref);

    /*!
     * \brief Cette fonction retourne une liste de produits tagués par t
     * \param t - Tags à rechercher
     * \return Un vector de produits
     */
    std::vector<Produit*> rechercherTags(std::string t);

    /*!
     * \brief Cette fonction retourne une liste de produits de la catégorie c
     * \param t - Catégorie à rechercher
     * \return Un vector de produits
     */
    std::vector<Produit*> rechercherCategorie(std::string t);

    /*!
     * \brief Cette fonction retourne une liste de produits tagués par plusieurs mots-clés
     * \param t - Liste de tags à rechercher
     * \return Un vector de produits
     */
    std::vector<Produit*> rechercherTags(std::vector<std::string>);

    /*!
     * \brief Cette fonction tri les produits par prix croissant
     */
    void triPrixCroissant ();

    /*!
     * \brief Cette fonction permet d'afficher la liste des produits
     */
    void toString();
};

#endif
