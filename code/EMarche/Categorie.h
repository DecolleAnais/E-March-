#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

class Categorie {
public :

    Categorie(std::string n);

    std::string getNom();

private:

    std::string nom;
};

#endif
