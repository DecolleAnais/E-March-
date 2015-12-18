#ifndef DIALOGAJOUTERVENTE_H
#define DIALOGAJOUTERVENTE_H

#include <QDialog>
#include "bdd/GestionBdd.h"

namespace Ui {
class DialogAjouterVente;
}

//!
//! \brief The DialogAjouterVente class - Boîte de dialoque permettant l'ajout d'un produit en vente
//!
class DialogAjouterVente : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief DialogAjouterVente - Constructeur
    //! \param bdd - Lien vers GestionBdd qui gère toutes les données
    //! \param parent- Lien vers le widget parent
    //!
    explicit DialogAjouterVente(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogAjouterVente();

private slots:
    //!
    //! \brief on_radioNormale_toggled - Slot inutilisé qui cause des problèmes à sa supression
    //! \param checked
    //!
    void on_radioNormale_toggled(bool checked);

    //!
    //! \brief on_boutonAjouterVente_clicked - Slot validant l'ajout de la vente
    //!
    void on_boutonAjouterVente_clicked();

private:
    Ui::DialogAjouterVente *ui;
    GestionBdd * gestionBdd;
};

#endif // DIALOGAJOUTERVENTE_H
