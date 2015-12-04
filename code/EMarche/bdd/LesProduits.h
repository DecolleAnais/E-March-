#ifndef LESPRODUITS_H
#define LESPRODUITS_H

#include "Produit.h"
#include <iostream>
#include <vector>

class LesProduits
{
private:
    std::vector<Produit*> lesProduits;
    int nbElems;

public:
    LesProduits() : lesProduits(), nbElems(0) {}

    //LesProduits();

    std::vector<Produit*> getListProduits();
    int size();
    void addProduit(Produit* p);
    void supprimerProduit(std::string ref);
    void supprimerProduit(Produit* p);
    Produit getProduit(std::string ref);
    void toString();
};

#endif // LESPRODUITS_H
