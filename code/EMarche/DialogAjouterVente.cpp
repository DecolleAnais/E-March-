#include "DialogAjouterVente.h"
#include "ui_DialogAjouterVente.h"

using namespace std;

DialogAjouterVente::DialogAjouterVente(GestionBdd *bdd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterVente),
    gestionBdd(bdd)
{
    ui->setupUi(this);

    show();
}

DialogAjouterVente::~DialogAjouterVente()
{
    delete ui;
}

void DialogAjouterVente::on_radioNormale_toggled(bool checked)
{

}

void DialogAjouterVente::on_boutonAjouterVente_clicked()
{
    string nom = ui->valNom->text().toStdString();
    string categorie = ui->valCat->text().toStdString();
    float prix = ui->valPrix->text().toFloat();
    unsigned int qte = ui->valQte->text().toUInt();
    bool etat = ui->buttonGroup->checkedButton();
    gestionBdd->ajouterVente(nom, categorie, prix, qte, etat);
    close();
}
