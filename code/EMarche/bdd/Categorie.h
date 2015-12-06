#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

class Categorie {

private:

    std::string nom;

public:

    Categorie(std::string n) : nom(n) {}

    /* destructeur */
    virtual ~Categorie() {}

    std::string getNom();
    void setNom(std::string n);

};

#endif
