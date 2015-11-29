#include "maFenetre.h"
#include <QCoreApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

maFenetre::maFenetre(int l, int h, GestionBdd bdd) : largeur(l), hauteur(h), gestionBdd(bdd)
{
    setFixedSize(largeur, hauteur);    // taille fenetre

    /* layouts */
    QVBoxLayout *vLayout = new QVBoxLayout;
    FenetreHaut *haut = new FenetreHaut(gestionBdd);
    QGridLayout *gridLayout = new QGridLayout;
    FenetreBas *bas = new FenetreBas;

    /*********************************************
     * CENTRE                                    *
     * ******************************************/

    /* Titre de la section */
    titreSection = new QLabel("Ventes en cours", this);

    /* Barre de defilement */
    barreDefile = new QScrollArea;

    /* Grille de produits */
    barreDefile->setLayout(gridLayout);

    /* Alignement vertical */
    vLayout->addLayout(haut);
    vLayout->addWidget(titreSection);
    vLayout->addWidget(barreDefile);
    vLayout->addLayout(bas);

    setLayout(vLayout);


}
