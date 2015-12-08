#include "DialogAjouterVente.h"
#include "ui_DialogAjouterVente.h"

DialogAjouterVente::DialogAjouterVente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterVente)
{
    ui->setupUi(this);
}

DialogAjouterVente::~DialogAjouterVente()
{
    delete ui;
}
