#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include "bdd/GestionBdd.h"

/* Boîte de dialogue pour la connexion */

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(GestionBdd bdd, QWidget *parent = 0);
    ~DialogConnexion();

public slots:
    void ouvrir();

private slots:
    void on_boutonSInscrire_clicked();

private:
    Ui::DialogConnexion *ui;
    GestionBdd gestionBdd;
};

#endif // DIALOGCONNEXION_H
