#include "maFenetre.h"
#include <QCoreApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

maFenetre::maFenetre(int l, int h, GestionBdd bdd) : largeur(l), hauteur(h), gestionBdd(bdd)
{
    gestionBdd.addVue(this);
    setFixedSize(largeur, hauteur);    // taille fenetre

    /* layouts */
    QVBoxLayout *vLayout = new QVBoxLayout;
    QVBoxLayout *centre = new QVBoxLayout;
    FenetreHaut *haut = new FenetreHaut(gestionBdd);
    FenetreBas *bas = new FenetreBas;

    /*********************************************
     * CENTRE                                    *
     * ******************************************/

    /* Titre de la section */
    titreSection = new QLabel("Ventes en cours", this);

    /* Barre de defilement */
    barreDefile = new QScrollArea;

    /* Grille de produits */
    barreDefile->setLayout(centre);
    /*Utilisateur* u = gestionBdd.rechercherUtilisateur("graou");
    QLabel *lab = new QLabel;
    QString qs = QString::fromStdString(u->toString());
    lab->setText(qs);
    gridLayout->addWidget(lab);
    vector<Utilisateur*>::iterator it;
    QVBoxLayout *box = new QVBoxLayout;
    QLabel *lab = new QLabel;
    if(v.empty()) cout << "vide";
    for(it = v.begin();it != v.end();it++) {
        string str = (*it)->getPseudo();
        QString s = QString::fromStdString(str);
        lab->setText(s);
        box->addWidget(lab);
        gridLayout->addLayout(box);
    }*/


    /* Alignement vertical */
    vLayout->addLayout(haut);
    vLayout->addWidget(titreSection);
    vLayout->addWidget(barreDefile);
    vLayout->addLayout(bas);

    setLayout(vLayout);


}

void maFenetre::update() {

}
