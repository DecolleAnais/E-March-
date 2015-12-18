#ifndef AVIS_H
#define AVIS_H

#include <string>
#include <sstream>

//!
//! \brief The Avis class - Représente un avis donné par un utilisateur sur un autre utilisateur ou un produit, avec un commentaire et une note
//!
class Avis {

protected:
    unsigned int note;
    std::string commentaire;
    std::string auteur;

public:

    /* Constructeurs */
    //!
    //! \brief Avis - Note sans commentaire
    //! \param author - Auteur de l'avis
    //! \param notation - Note donnée
    //!
    Avis(std::string author, unsigned int notation) : note(notation), commentaire(""), auteur(author) {}
    //!
    //! \brief Avis - Note et commentaire
    //! \param author - Auteur de l'avis
    //! \param notation - Note donnée
    //! \param com - Commentaire donné
    //!
    Avis(std::string author, unsigned int notation, std::string com) : note(notation), commentaire(com), auteur(author) {}

    /* Fonctions get */
    //!
    //! \brief getNote
    //! \return la note de l'avis
    //!
    unsigned int getNote();

    //!
    //! \brief getCommentaire
    //! \return le commentaire de l'avis
    //!
    std::string getCommentaire();

    //!
    //! \brief getAuteur
    //! \return l'auteur de l'avis
    //!
    std::string getAuteur();

    /* Affichage */

    //!
    //! \fn void   decrit(std::ostream &os)
    //! \brief decrit - Ecrit toutes les données de l'avis dans un flux donné en paramètre
    //! \param os - Flux
    //!
    void   decrit(std::ostream &os) {
        os << "------Avis-------\nAuteur : " << getAuteur() << "\nNote : " << getNote() << "\nCommentaire : " << getCommentaire() ;
    }

    //!
    //! \fn std::string decrit()
    //! \brief decrit - convertit un flux en string
    //! \return un string à partir d'un flux
    //!
    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    //!
    //! \fn void  affiche(std::ostream &os)
    //! \brief affiche - Ecrit toutes les données d'un avis d'un flux vers une sortie
    //! \param os - Sortie, par exemple : cout
    //!
    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif // AVIS_H
