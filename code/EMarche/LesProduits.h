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
    LesProduits() : lesProduits(10), nbElems(0) {}

    //LesProduits();

    std::vector<Produit*> getListProduits();
    int size();
    void addProduit(Produit* p);
    void supprimerProduit(int ref);
    Produit getProduit(int ref);
    void toString();
};

#endif // LESPRODUITS_H
