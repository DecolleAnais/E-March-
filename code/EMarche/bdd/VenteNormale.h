#ifndef VENTENORMALE_H
#define VENTENORMALE_H

#include "EtatVente.h"

/*!
 * \class VenteNormale
 * \brief Cette classe gère une vente normale
 */
class VenteNormale : public EtatVente {

public :
    /*!
     * \brief Constructeur de la classe VenteNormale
     * \param b - Booléen qui donne le type de la vente
     */
    VenteNormale(bool b);

    ~VenteNormale() {};
};

#endif
