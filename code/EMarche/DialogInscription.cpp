#include "DialogInscription.h"
#include "ui_DialogInscription.h"

DialogInscription::DialogInscription(GestionBdd bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInscription),
    gestionBdd(bdd)
{
    ui->setupUi(this);
}

DialogInscription::~DialogInscription()
{
    delete ui;
}

/* SLOTS */

void DialogInscription::ouvrir() {
    show();
}

void DialogInscription::on_boutonValider_clicked()
{
    std::string pseudo = ui->valPseudo->text().toStdString();
    std::string mdp = ui->valMdp->text().toStdString();
    std::string nom = ui->valNom->text().toStdString();
    std::string prenom = ui->valPrenom->text().toStdString();
    /*std::string jourNaiss = ui->valDateNaissance->date().toString("dd");
    std::string moisNaiss = ui->valDateNaissance->date().toString("MM");
    std::string anneeNaiss = ui->valDateNaissance->date().toString("yyyy");
    int jourNaissInt = atoi(jourNaiss.c_str());
    int moisNaissInt = atoi(moisNaiss.c_str());
    int anneeNaissInt = atoi(anneeNaiss.c_str());*/
    std::string mail = ui->valMail->text().toStdString();
    std::string adresse = ui->valAdresse->text().toStdString();

    gestionBdd.inscrire(pseudo, mdp, nom, prenom, 18, 04, 1994, mail, adresse);
}
