#ifndef ETATVENTE_H
#define ETATVENTE_H

#include <string>
#include <ctime>
#include <sstream>

/*!
 * \class EtatVente
 * \brief Cette classe gère l'état d'une vente (enchère ou normale)
 */
class EtatVente {

protected:
    //! \brief Booléen qui distingue une vente normale d'une vente aux enchères
    bool typeDeVente;
    //! \brief Prix actuel
    float prixActuel;
    //! \brief Date limite avant la fin de l'enchère
    struct tm dateLimite;

public:
    /*!
     * \brief Constructeur de la classe EtatVente
     * \param b - Booléen qui donne le type de la vente
     */
    EtatVente(bool b);

    virtual ~EtatVente() {};

    /* ----- Fonctions get ----- */

    /*!
     * \fn bool typeVente()
     * \brief Cette fonction indique la type de la vente. Si elle retourne true,
     * c'est une vente aux enchères, sinon c'est une vente normale
     * \return True si c'est une vente aux enchères, false sinon
     */
    bool typeVente();

    /*!
     * \fn virtual float getPrixActuel()
     * \brief Cette fonction virtuelle retourne le prix actuel de la vente
     * \return Un float représentant le prix actuel
     */
    virtual float getPrixActuel();

    /*!
     * \fn virtual std::string getDateLimite()
     * \brief Cette fonction virtuelle retourne la date limite de l'enchère
     * \return Un string contenant la date limite de l'enchère
     */
    virtual std::string getDateLimite();

    /* ----- Fonctions get ----- */

    /*!
     * \fn virtual void setPrixActuel(float prix)
     * \brief Cette fonction virtuelle fixe le prix actuel
     * \param prix - Nouveau prix
     */
    virtual void setPrixActuel(float prix);

    /*!
     * \fn virtual void setDateLimite(struct tm date)
     * \brief Cette fonction virtuelle fixe la date limite
     * \param date - Nouvelle date
     */
    virtual void setDateLimite(struct tm date);

};

#endif
