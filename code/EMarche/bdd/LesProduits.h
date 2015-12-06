#ifndef LESPRODUITS_H
#define LESPRODUITS_H

#include "Produit.h"
#include <iostream>
#include <vector>
#include <algorithm>

class LesProduits
{
private:
    std::vector<Produit*> lesProduits;
    int nbElems;

public:
    LesProduits() : lesProduits(), nbElems(0) {}

    std::vector<Produit*> getListProduits();
    int size();
    void addProduit(Produit* p);
    void supprimerProduit(std::string ref);
    void supprimerProduit(Produit* p);
    std::vector<Produit*> getProduitsNom(std::string chaine);
    Produit* getProduit(std::string ref);
    std::vector<Produit*> rechercherTags(std::string t);
    std::vector<Produit*> rechercherCategorie(std::string t);
    void toString();
};

#endif // LESPRODUITS_H
