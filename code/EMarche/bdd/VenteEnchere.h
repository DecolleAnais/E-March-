#ifndef VENTEENCHERE_H
#define VENTEENCHERE_H

#include "EtatVente.h"

/*!
 * \class VenteEnchere
 * \brief Cette classe gère une vente aux enchères
 */
class VenteEnchere : public EtatVente {

public:
    /*!
     * \brief Constructeur de la classe VenteEnchere
     * \param b - Booléen qui donne le type de la vente
     */
    VenteEnchere(bool b);

    /* ----- Fonctions get ----- */

    /*!
     * \fn float getPrixActuel()
     * \brief Retourne le prix actuel de la vente
     * \return Un float représentant le prix actuel
     */
    float getPrixActuel();

    /*!
     * \fn std::string getDateLimite()
     * \brief Retourne la date limite de l'enchère
     * \return Un string contenant la date limite de l'enchère
     */
    std::string getDateLimite();

    /* ----- Fonctions set ----- */

    /*!
     * \fn void setPrixActuel(float prix)
     * \brief Cette fonction fixe le prix actuel
     * \param prix - Nouveau prix
     */
    void setPrixActuel(float prix);

    /*!
     * \fn void setDateLimite(struct tm date)
     * \brief Cette fonction fixe la date limite
     * \param date - Nouvelle date
     */
    void setDateLimite(struct tm date);

};

#endif
