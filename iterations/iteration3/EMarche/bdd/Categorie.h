#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

//!
//! \brief The Categorie class - Représente une catégorie de produits
//!
class Categorie {

protected:

    std::string nom;

public:

    //!
    //! \brief Categorie
    //! \param n - Nom de la catégorie
    //!
    Categorie(std::string n) : nom(n) {}

    /* destructeur */
    virtual ~Categorie() {}

    //!
    //! \brief getNom
    //! \return le nom de la catégorie
    //!
    std::string getNom();

    //!
    //! \brief setNom
    //! \param n - nouveau nom de la catégorie
    //!
    void setNom(std::string n);

};

#endif
