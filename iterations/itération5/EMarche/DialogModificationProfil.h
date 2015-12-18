#ifndef DIALOGMODIFICATIONPROFIL_H
#define DIALOGMODIFICATIONPROFIL_H

#include <QDialog>
#include "bdd/GestionBdd.h"

namespace Ui {
class DialogModificationProfil;
}

//!
//! \brief The DialogModificationProfil class - Boîte de dialogue permettant de modifier les données du profil utilisateur
//!
class DialogModificationProfil : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief DialogModificationProfil - Constructeur
    //! \param bdd - Lien vers GestionBdd qui contient toutes les données
    //! \param parent - Lien vers le widget parent
    //!
    explicit DialogModificationProfil(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogModificationProfil();

private slots:
    //!
    //! \brief on_boutonValider_clicked - Slot de validation des modifications
    //!
    void on_boutonValider_clicked();

private:
    Ui::DialogModificationProfil *ui;
    GestionBdd *gestionBdd;
};

#endif // DIALOGMODIFICATIONPROFIL_H
