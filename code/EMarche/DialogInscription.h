#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>
#include <QMessageBox>
#include "bdd/GestionBdd.h"

/* Boîte de dialogue pour l'inscription */

namespace Ui {
class DialogInscription;
}

//!
//! \brief The DialogInscription class - Boîte de dialogue permettant d'inscrire un nouvel utilisateur
//!
class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief DialogInscription - Constructeur
    //! \param bdd - Lien vers GestionBdd qui contient toutes les données
    //! \param parent - Lien vers le widget parent
    //!
    explicit DialogInscription(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogInscription();

public slots:
    //!
    //! \brief ouvrir - Slot affichant cette boîte de dialogue
    //!
    void ouvrir();

private slots:
    //!
    //! \brief on_boutonValider_clicked - Slot validant l'inscription
    //!
    void on_boutonValider_clicked();

private:
    Ui::DialogInscription *ui;
    GestionBdd *gestionBdd;
};

#endif // DIALOGINSCRIPTION_H
