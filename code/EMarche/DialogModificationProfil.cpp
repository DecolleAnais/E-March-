#include "DialogModificationProfil.h"
#include "ui_DialogModificationProfil.h"

using namespace std;

DialogModificationProfil::DialogModificationProfil(GestionBdd *bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModificationProfil),
    gestionBdd(bdd)
{
    ui->setupUi(this);

    show();
}

DialogModificationProfil::~DialogModificationProfil()
{
    delete ui;
    delete gestionBdd;
}

void DialogModificationProfil::on_boutonValider_clicked()
{
    /* récupération des valeurs nécessaires à la création d'un utilisateur */
    string pseudo = ui->lineEdit->text().toStdString();
    string nom = ui->lineEdit_2->text().toStdString();
    string prenom = ui->lineEdit_3->text().toStdString();
    string mail = ui->lineEdit_4->text().toStdString();
    string codePostal = ui->lineEdit_5->text().toStdString();
    string ville = ui->lineEdit_6->text().toStdString();

    gestionBdd->modifierProfil(pseudo,nom,prenom,mail,codePostal,ville);

    close();
}
