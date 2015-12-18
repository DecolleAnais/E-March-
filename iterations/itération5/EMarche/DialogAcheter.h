#ifndef DIALOGACHETER_H
#define DIALOGACHETER_H

#include <QDialog>
#include "bdd/GestionBdd.h"

/*!
 * \class DialogAcheter
 * \brief Boîte de dialogue permettant d'acheter un produit
 */
namespace Ui {
class DialogAcheter;
}

class DialogAcheter : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de DialogAcheter
     * \param bdd - Lien vers GestionBdd qui gère toutes les données
     * \param parent- Lien vers le widget parent
     */
    explicit DialogAcheter(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogAcheter();

private slots:
    /*!
     * \brief Slot validant l'achat
     */
    void on_acheter_clicked();

private:
    Ui::DialogAcheter *ui;
    GestionBdd * gestionBdd;

};

#endif
