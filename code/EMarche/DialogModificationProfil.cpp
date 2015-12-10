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
    string nom = ui->nom->text().toStdString();
    string prenom = ui->prenom->text().toStdString();
    string mail = ui->email->text().toStdString();
    int codePostal = ui->code_postal->text().toInt();
    string ville = ui->ville->text().toStdString();
    string adresse = ui->adresse->text().toStdString();

    if(nom!="" && prenom!="" && mail!="" && !ui->code_postal->text().isEmpty() && ville!="" && adresse!="") {
        gestionBdd->modifierProfil(nom,prenom,mail,codePostal,ville,adresse);
        close();
    }
}
