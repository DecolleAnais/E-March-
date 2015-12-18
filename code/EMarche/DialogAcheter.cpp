#include "DialogAcheter.h"
#include "ui_DialogAcheter.h"

DialogAcheter::DialogAcheter(GestionBdd *bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAcheter),
    gestionBdd(bdd)
{
    ui->setupUi(this);
    ui->qte->setMaximum(gestionBdd->getProduitCourant()->getQuantite());
    show();
}

DialogAcheter::~DialogAcheter()
{
    delete ui;
}

void DialogAcheter::on_acheter_clicked()
{
    unsigned int qte = ui->qte->value();

    gestionBdd->acheterProduit(gestionBdd->getProduitCourant(), qte);
    close();
}
