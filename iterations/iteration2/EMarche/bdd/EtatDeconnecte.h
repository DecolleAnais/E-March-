#ifndef ETATDECONNECTE_H
#define ETATDECONNECTE_H

#include "EtatConnexion.h"

/*!
 * \class EtatDeconnecte
 * \brief Cette classe gère les utilisateurs déconnectés
 * \brief Elle hérite de la classe EtatConnexion
 */
class EtatDeconnecte : public EtatConnexion {

public:
    /*!
     * \brief Constructeur de la classe EtatDeconnecte
     * \param b - Nouvel état de connexion
     */
    EtatDeconnecte(bool b) : EtatConnexion(b) {}

    /* destructeur */
    virtual ~EtatDeconnecte() {}

};

#endif
