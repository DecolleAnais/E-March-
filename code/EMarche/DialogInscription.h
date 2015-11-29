#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>
#include "bdd/GestionBdd.h"

namespace Ui {
class DialogInscription;
}

class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInscription(GestionBdd bdd, QWidget *parent = 0);
    ~DialogInscription();

public slots:
    void ouvrir();

private slots:
    void on_boutonValider_clicked();

private:
    Ui::DialogInscription *ui;
    GestionBdd gestionBdd;
};

#endif // DIALOGINSCRIPTION_H
