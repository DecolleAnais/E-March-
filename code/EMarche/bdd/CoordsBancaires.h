#ifndef COORDSBANCAIRES_H
#define COORDSBANCAIRES_H

#include <string>

/*!
 * \class CoordsBancaires
 * \brief Cette classe contient les données bancaires d'un utilisateur
 */
class CoordsBancaires {

public:
    /*!
     * \brief Constructeur de coordonnées bancaires
     */
    CoordsBancaires();

private:
    //! \brief Type de carte bancaire
    std::string type;
    //! \brief Numéro de carte bancaire
    int numero;
    //! \brief Cryptogramme de la carte
    int cryptogramme;
    //! \brief Date d'expiration de la carte
    struct tm dateExpiration;
    //! \brief Adresse de facturation
    std::string adresseFacturation;
    //! \brief Adresse de livraison
    std::string adresseLivraison;

};

#endif
