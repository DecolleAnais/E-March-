#include <iostream>
#include "Produit.h"

int main(int argc, char *argv[])
{
    Produit p;
    p.setQuantite(2);
    std::cout << "nom " << p.getNom() << std::endl;
    std::cout << "ref " << p.getReference() << std::endl;
    std::cout << "qt " << p.getQuantite() << std::endl;
    std::cout << "pu " << p.getPrixUnitaire() << std::endl;
    std::cout << "depot " << p.getDateDepot() << std::endl;
    std::cout << "achat " << p.getDateAchatVente() << std::endl;

    return 0;
}

