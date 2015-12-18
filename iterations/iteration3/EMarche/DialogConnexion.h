#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include "bdd/GestionBdd.h"
#include <QMessageBox>

/* Boîte de dialogue pour la connexion */

namespace Ui {
class DialogConnexion;
}

//!
//! \brief The DialogConnexion class - Boîte de dialogue permettant de se connecter
//!
class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief DialogConnexion - Constructeur
    //! \param bdd - Lien vers GestionBdd qui contient toutes les données
    //! \param parent - Lien vers le widget parent
    //!
    explicit DialogConnexion(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogConnexion();

public slots:
    //!
    //! \brief ouvrir - Affiche la boîte de dialogue
    //!
    void ouvrir();

private slots:

    //!
    //! \brief on_boutonSeConnecter_clicked - Slot de validation de la connexion
    //!
    void on_boutonSeConnecter_clicked();

private:
    Ui::DialogConnexion *ui;
    GestionBdd *gestionBdd;
};

#endif // DIALOGCONNEXION_H
