#ifndef ETATCONNECTE_H
#define ETATCONNECTE_H

#include "EtatConnexion.h"

/*!
 * \class EtatConnecte
 * \brief Cette classe gère les utilisateurs connectés
 * \brief Elle hérite de la classe EtatConnexion
 */
class EtatConnecte : public EtatConnexion {

public:
    /*!
     * \brief Constructeur de la classe EtatConnecte
     * \param b - Nouvel état de connexion
     */
    EtatConnecte(bool b) : EtatConnexion(b) {}

    /* destructeur */
    virtual ~EtatConnecte() {}

};

#endif
