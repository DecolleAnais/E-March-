#ifndef DIALOGMODIFICATIONPROFIL_H
#define DIALOGMODIFICATIONPROFIL_H

#include <QDialog>
#include "bdd/GestionBdd.h"

namespace Ui {
class DialogModificationProfil;
}

class DialogModificationProfil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModificationProfil(GestionBdd *bdd, QWidget *parent = 0);
    ~DialogModificationProfil();

private slots:
    void on_boutonValider_clicked();

private:
    Ui::DialogModificationProfil *ui;
    GestionBdd *gestionBdd;
};

#endif // DIALOGMODIFICATIONPROFIL_H
