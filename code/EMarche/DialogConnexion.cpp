#include "DialogConnexion.h"
#include "ui_DialogConnexion.h"
#include "DialogInscription.h"

DialogConnexion::DialogConnexion( GestionBdd bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion),
    gestionBdd(bdd)
{

    setFixedSize(550, 250);
    ui->setupUi(this);

    // Connexion clic bouton "S'inscrire" qui affiche la fenetre d'inscription
    QObject::connect(ui->boutonSInscrire, SIGNAL(clicked()), new DialogInscription(gestionBdd), SLOT(ouvrir()));
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}


/* SLOTS */

void DialogConnexion::ouvrir() {
    show();
}

void DialogConnexion::on_boutonSInscrire_clicked()
{
    close();
}
