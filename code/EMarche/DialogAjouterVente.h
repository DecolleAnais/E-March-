#ifndef DIALOGAJOUTERVENTE_H
#define DIALOGAJOUTERVENTE_H

#include <QDialog>
#include "bdd/GestionBdd.h"

namespace Ui {
class DialogAjouterVente;
}

class DialogAjouterVente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterVente(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogAjouterVente();

private slots:
    void on_radioNormale_toggled(bool checked);

    void on_boutonAjouterVente_clicked();

private:
    Ui::DialogAjouterVente *ui;
    GestionBdd * gestionBdd;
};

#endif // DIALOGAJOUTERVENTE_H
