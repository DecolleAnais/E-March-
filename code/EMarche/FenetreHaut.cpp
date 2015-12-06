#include "FenetreHaut.h"
#include <QCoreApplication>
#include "DialogConnexion.h"

using namespace std;

FenetreHaut::FenetreHaut(GestionBdd bdd) : gestionBdd(bdd)
{
    gestionBdd.addVue(this);
    /* liste deroulante pour le type de recherche */
    typeRecherche = new QComboBox;
    typeRecherche->addItem("Produit");
    typeRecherche->addItem("Utilisateur");

    /* texte de la recherche */
    valRecherche = new QLineEdit;

    /* bouton rechercher */
    boutonRecherche = new QPushButton("Rechercher");

    QObject::connect(boutonRecherche, SIGNAL(clicked()), this, SLOT(rechercher()));

    /* label peudo de l'utilisateur connecté */
    pseudoConnecte = new QLabel("Graou");

    /* bouton connexion */
    boutonConnexion = new QPushButton("Se connecter");     // bouton connexion
    boutonConnexion->setToolTip("connexion");     // tooltip
    boutonConnexion->setFont(QFont("Comic Sans MS",12));  // changer police
    boutonConnexion->setCursor(Qt::PointingHandCursor);   // curseur
    boutonConnexion->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/connexion.png"));   // icone
    boutonConnexion->setIconSize(QSize(25,25));     // changer taille icone
    boutonConnexion->move(1000,0);    // deplacer bouton

    // Connexion clic bouton "Se connecter" qui affiche la fenetre de connexion
    QObject::connect(boutonConnexion, SIGNAL(clicked()), new DialogConnexion(gestionBdd), SLOT(ouvrir()));

    /* Layouts */
    addWidget(typeRecherche);
    addWidget(valRecherche);
    addWidget(boutonRecherche);
    addWidget(pseudoConnecte);
    addWidget(boutonConnexion);
}

void FenetreHaut::rechercher() {
    gestionBdd.update();

    /* Récupération des valeurs pour la recherche */
    string type = typeRecherche->currentText().toStdString();
    string val = valRecherche->text().toStdString();

    if(type.compare("Utilisateur") == 0) {
        /* Recherche d'un utilisateur */
        gestionBdd.rechercherUtilisateur(val);

    }else {
        /* Recherche d'un produit */
        gestionBdd.rechercherProduit(val);
    }
}

void FenetreHaut::update() {
pseudoConnecte->setText("Blp");
pseudoConnecte->repaint();
}
