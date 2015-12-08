#include "DialogInscription.h"
#include "ui_DialogInscription.h"

using namespace std;

DialogInscription::DialogInscription(GestionBdd *bdd, QWidget *parent) :
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
    /* récupération des valeurs nécessaires à la création d'un utilisateur */
    string pseudo = ui->valPseudo->text().toStdString();
    string mdp = ui->valMdp->text().toStdString();
    string nom = ui->valNom->text().toStdString();
    string prenom = ui->valPrenom->text().toStdString();
    string jourNaiss = ui->valDateNaissance->date().toString("dd").toStdString();
    string moisNaiss = ui->valDateNaissance->date().toString("MM").toStdString();
    string anneeNaiss = ui->valDateNaissance->date().toString("yyyy").toStdString();
    int jourNaissInt = atoi(jourNaiss.c_str());
    int moisNaissInt = atoi(moisNaiss.c_str());
    int anneeNaissInt = atoi(anneeNaiss.c_str());
    string mail = ui->valMail->text().toStdString();
    string adresse = ui->valAdresse->text().toStdString();

    gestionBdd->inscrire(pseudo, mdp, nom, prenom, jourNaissInt, moisNaissInt, anneeNaissInt, mail, adresse);

    close();
}
