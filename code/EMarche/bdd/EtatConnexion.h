#ifndef ETATCONNEXION_H
#define ETATCONNEXION_H

/*!
 * \class EtatConnexion
 * \brief Cette classe gère les états de connexion d'un utilisateur (connecté ou déconnecté)
 */
class EtatConnexion {

private :
    //! Booléen qui indique si un utilisateur est connecté ou non
    bool estConnecte;

public :
    /*!
     * \brief Constructeur de la classe EtatConnexion
     * \param b - Nouvel état de connexion
     */
    EtatConnexion(bool b);

    /*!
     * \brief Cette fonction indique l'état de connexion d'un utilisateur
     * \return true si l'utilisateur est connecté, false sinon
     */
    bool connexionEnCours();

    /* destructeur */
    virtual ~EtatConnexion() {}

};

#endif
