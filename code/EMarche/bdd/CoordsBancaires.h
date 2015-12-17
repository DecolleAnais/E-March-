#ifndef COORDSBANCAIRES_H
#define COORDSBANCAIRES_H

#include <string>

//!
//! \brief The CoordsBancaires class - Contient les données bancaires d'un utilisateur
//!
class CoordsBancaires
{
public:
    CoordsBancaires();

private:
    std::string type;
    int numero;
    int cryptogramme;
    struct tm dateExpiration;
    std::string adresseFacturation;
    std::string adresseLivraison;

};

#endif // COORDSBANCAIRES_H
