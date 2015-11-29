#include "FenetreHaut.h"
#include <QCoreApplication>
#include "DialogConnexion.h"

FenetreHaut::FenetreHaut(GestionBdd bdd) : gestionBdd(bdd)
{
    /* liste deroulante pour le type de recherche */
    typeRecherche = new QComboBox;
    typeRecherche->addItem("Produit");
    typeRecherche->addItem("Utilisateur");

    /* texte de la recherche */
    valRecherche = new QLineEdit;

    /* bouton rechercher */
    boutonRecherche = new QPushButton("Rechercher");

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
    addWidget(boutonConnexion);
}
