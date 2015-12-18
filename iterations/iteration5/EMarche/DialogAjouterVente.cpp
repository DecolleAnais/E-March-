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
    delete gestionBdd;
}

void DialogAjouterVente::on_radioNormale_toggled(bool checked)
{

}

void DialogAjouterVente::on_boutonAjouterVente_clicked()
{
    string nom = ui->valNom->text().toStdString();
    string categorie = ui->valCat->text().toStdString();
    float prix = ui->valPrix->value();
    unsigned int qte = ui->valQte->text().toUInt();
    string etat = ui->buttonGroup->checkedButton()->text().toStdString();

    if(nom != "" && categorie != "" && prix > 0.00 && qte > 0) {
        if(etat == "Vente aux enchères") {
            QDate date = ui->valDateLimite->date();
            int year = date.year();
            int month = date.month();
            int day = date.day();
            struct tm dateLimite;
            dateLimite.tm_mday = day;
            dateLimite.tm_mon = month;
            dateLimite.tm_year = year;
            gestionBdd->ajouterVente(nom, categorie, prix, qte, true, dateLimite);
            close();
        } else {
            gestionBdd->ajouterVente(nom, categorie, prix, qte, false);
            close();
        }
    }
}
