#ifndef LESUTILISATEURS_H
#define LESUTILISATEURS_H

#include <vector>
#include "Utilisateur.h"

//!
//! \brief The LesUtilisateurs class - Gère un vector de pointeurs vers des utilisateurs
//!
class LesUtilisateurs {

private:
   std::vector<Utilisateur*> lesUtilisateurs;
   int nbUtilisateurs;

public:
   /* Constructeur */
   //!
   //! \brief LesUtilisateurs - Constructeur
   //!
    LesUtilisateurs() {

    }

    /* Destructeur */
     ~LesUtilisateurs() {
        std::vector<Utilisateur*>::iterator it;
        for(it = lesUtilisateurs.begin(); it != lesUtilisateurs.end();it++) {
            delete(*it);
        }
    }

    /* Fonctions */

    /* ajoute un pointeur vers l'utilisateur u dans le vector lesUtilisateurs */
    //!
    //! \fn void add(Utilisateur* u)
    //! \brief add - Ajoute un pointeur vers un utilisateur dans le vector lesUtilisateurs
    //! \param u - Pointeur vers l'utilisateur à ajouter
    //!
    void add(Utilisateur* u);

    /* supprime un utilisateur via son pseudo */
    //!
    //! \fn void supprimer(std::string pseudo)
    //! \brief supprimer - Supprime un utilisateur du vector lesUtilisateurs via son pseudo
    //! \param pseudo - Pseudo de l'utilisateur à supprimer
    //!
    void supprimer(std::string pseudo);

    /* retourne un pointeur vers l'utlisateur de ce pseudo */
    //!
    //! \fn Utilisateur* getUtilisateur(std::string pseudo)
    //! \brief getUtilisateur - Retourne un pointeur vers un utilisateur du vector lesUtilisateurs via son pseudo
    //! \param pseudo - Pseudo de l'utilisateur à renvoyer
    //! \return un pointeur vers l'utilisateur recherché
    //!
    Utilisateur* getUtilisateur(std::string pseudo);

    /* retourne un vector contenant les pointeurs vers tous les utilisateurs dont le pseudo contient la chaine demandée */
    //!
    //! \fn std::vector<Utilisateur*> getUtilisateurs(std::string chaine)
    //! \brief getUtilisateurs - Retourne le vector lesUtilisateurs contenant les pointeurs vers les utilisateurs recherchés
    //! \param chaine - Chaîne testée avec le pseudo des utilisateurs
    //! \return un vector contenant ls pointeurs vers les utilisateurs dont le pseudo contient la chaîne
    //!
    std::vector<Utilisateur*> getUtilisateurs(std::string chaine);

    /* retourne vrai si l'utilisateur avec ce pseudo et mot de passe existe, faux sinon */
    //!
    //! \fn bool existeUtilisateur(std::string pseudo, std::string mdp)
    //! \brief existeUtilisateur dit si l'utilisateur existe ou non via son pseudo et mot de passe
    //! \param pseudo - Pseudo de l'utilisateur recherché
    //! \param mdp - Mot de passe de l'utilisateur recherché
    //! \return true si l'utilisateur existe, false sinon
    //!
    bool existeUtilisateur(std::string pseudo, std::string mdp);

    /* retourne le nombre d'utilisateurs */
    //!
    //! \fn int getNbUtilisateurs()
    //! \brief getNbUtilisateurs
    //! \return
    //!
    int getNbUtilisateurs();

    /* affiche tous les utilisateurs */
    //!
    //! \fn void affiche()
    //! \brief affiche tous les utilisateurs
    //!
    void affiche();



};

#endif // LESUTILISATEURS_H
