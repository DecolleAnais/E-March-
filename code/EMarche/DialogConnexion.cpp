#include "DialogConnexion.h"
#include "ui_DialogConnexion.h"
#include "DialogInscription.h"

using namespace std;

DialogConnexion::DialogConnexion( GestionBdd *bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion),
    gestionBdd(bdd)
{

    setFixedSize(550, 250);
    ui->setupUi(this);

    // Connexion clic bouton "S'inscrire" qui affiche la fenetre d'inscription
    QObject::connect(ui->boutonSInscrire, SIGNAL(clicked()), new DialogInscription(gestionBdd), SLOT(ouvrir()));
    show();
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
    delete gestionBdd;
}


/* SLOTS */

void DialogConnexion::ouvrir() {
    show();
}

void DialogConnexion::on_boutonSInscrire_clicked()
{
    close();
}

void DialogConnexion::on_boutonSeConnecter_clicked()
{
    string pseudo = ui->valPseudo->text().toStdString();
    string motDePasse = ui->valMdp->text().toStdString();
    if(pseudo != "" && motDePasse != "") {
        gestionBdd->connecterUtilisateur(pseudo, motDePasse);
        close();
    } else {
        QMessageBox::warning(this, "Connexion", "Remplissez tous les champs ou inscrivez-vous !");
    }
}
