#include "MaFenetre.h"

using namespace std;

MaFenetre::MaFenetre(int l, int h, GestionBdd *bdd) : largeur(l), hauteur(h), gestionBdd(bdd)
{
    gestionBdd->addVue(this);
    setFixedSize(largeur, hauteur);    // taille fenetre

    /* layouts */
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->setAlignment(Qt::AlignTop);
    haut = new QHBoxLayout();
    centre = new QVBoxLayout();
    centre->setAlignment(Qt::AlignTop);
    bas = new QHBoxLayout();

    /*********************************************
     * HAUT                                      *
     * ******************************************/

    /* liste deroulante pour le type de recherche */
    typeRecherche = new QComboBox;
    typeRecherche->addItem("Produit");

    /* texte de la recherche */
    valRecherche = new QLineEdit;

    /* bouton rechercher */
    boutonRecherche = new QPushButton("Rechercher");

    QObject::connect(boutonRecherche, SIGNAL(clicked()), this, SLOT(rechercher()));
    QObject::connect(this,SIGNAL(signalRechercheProduits(std::vector<Produit*>)),this, SLOT(afficherResProduits(std::vector<Produit*>)));

    /* bouton accueil */
    boutonAccueil = new QPushButton("Accueil");
    QObject::connect(boutonAccueil, SIGNAL(clicked()), this, SLOT(accueil()));

    /* bouton ajouterVente */
    boutonAjouterVente = new QPushButton("Ajouter vente");
    QObject::connect(boutonAjouterVente, SIGNAL(clicked()), this, SLOT(ajouterVente()));

    /* label peudo de l'utilisateur connecté */
    pseudoConnecte = new QLabel("");

    /* bouton connexion */
    boutonConnexion = new QPushButton("Se connecter");     // bouton connexion
    QObject::connect(boutonConnexion, SIGNAL(clicked()), this, SLOT(connexion()));

    /* Layouts */
    haut->addWidget(typeRecherche);
    haut->addWidget(valRecherche);
    haut->addWidget(boutonRecherche);
    haut->addWidget(boutonAccueil);
    haut->addWidget(boutonAjouterVente);
    haut->addWidget(pseudoConnecte);
    haut->addWidget(boutonConnexion);

    /*********************************************
     * CENTRE                                    *
     * ******************************************/

    /* Titre de la section */
    titreSection = new QLabel("Ventes en cours", this);
    barreDefile = new QScrollArea;
    barreDefile->setLayout(centre);
    emit signalRechercheProduits(gestionBdd->ventesEnCours());

    /*********************************************
     * BAS                                       *
     * ******************************************/

    /* Boutons de changement de page */
    boutonPrecedent = new QPushButton("<");
    boutonSuivant = new QPushButton(">");
    numPage = new QLabel("1");
    bas->addWidget(boutonPrecedent);
    bas->addWidget(numPage);
    bas->addWidget(boutonSuivant);
    bas->setAlignment(Qt::AlignHCenter);


    /* Alignement vertical */
    vLayout->addLayout(haut);
    vLayout->addWidget(titreSection);
    vLayout->addWidget(barreDefile);
    vLayout->addLayout(bas);

    setLayout(vLayout);


}

/************************************
 * FONCTIONS                        *
 * **********************************/

void MaFenetre::rechercher() {
    /* Récupération des valeurs pour la recherche */
    string type = typeRecherche->currentText().toStdString();
    string val = valRecherche->text().toStdString();
    /* Recherche d'un produit */
    vector<Produit*> v = gestionBdd->rechercherTags(val);
    emit signalRechercheProduits(v);
    titreSection->setText("Résultats de la recherche de la référence " + QString::fromStdString(val));
}

/* retour à l'accueil avec l'affichage des ventes en cours */
void MaFenetre::accueil() {
    titreSection->setText("Ventes en cours");
    emit signalRechercheProduits(gestionBdd->ventesEnCours());
}

/* ajouter une vente */
void MaFenetre::ajouterVente() {
    if(gestionBdd->isConnecte()) {
        ajouterVentes = new DialogAjouterVente(gestionBdd);
    }else {
        QMessageBox::warning(this, "Ajouter une vente", "Attention, vous devez être connecté pour ajouter un produit en vente !");
    }
}

/* connexion */
void MaFenetre::connexion() {
    if(gestionBdd->isConnecte()) {
        gestionBdd->deconnecterUtilisateur();
        pseudoConnecte->setText("");
        boutonConnexion->setText("Se connecter");
    } else {
        connexions = new DialogConnexion(gestionBdd);
    }
}

/* affichage du résultat d'une recherche de produits */
void MaFenetre::afficherResProduits(vector<Produit*> v) {
    clearLayout(centre);
    vector<Produit*>::iterator it;
    int i = 0;
    for(it = v.begin();it != v.end();it++) {
        /* création d'une grille pour chaque produit */
        QGroupBox *box = new QGroupBox;
        QGridLayout *grille = new QGridLayout();

        /* conversion des champs string du produit en QString */
        QString ref = QString::fromStdString((*it)->getReference());
        QString nom = QString::fromStdString((*it)->getNom());
        QString cat = QString::fromStdString((*it)->getCategorie());
        QString prix = QString::number((*it)->getPrixActuel());
        QString qte = QString::number((*it)->getQuantite());
        QString vendeur = QString::fromStdString((*it)->getVendeur());
        QString dateDepot = QString::fromStdString((*it)->getDateDepot());

        /* agencement dans le GridLayout */
        grille->addWidget(new QLabel("<b>Nom : </b>" + nom), 0, 0);
        grille->addWidget(new QLabel("<b>Référence : </b>" + ref), 0, 1);
        grille->addWidget(new QLabel("<b>Catégorie : </b>" + cat), 1, 0);
        grille->addWidget(new QLabel("<b>Date du dépôt : </b>" + dateDepot), 2, 0);
        grille->addWidget(new QLabel("<b>Quantité : </b>" + qte), 3, 0);
        grille->addWidget(new QLabel("<b>Vendeur : </b>" + vendeur), 4, 0);

        /* affichages spécifiques aux enchères ou ventes normales */
        if((*it)->getEtatVente() == "Vente aux enchères") {
            QString dateLimite = QString::fromStdString((*it)->getDateLimite());
            grille->addWidget(new QLabel("<b>Date limite : </b>" + dateLimite));
            grille->addWidget(new QLabel("<b>Prix actuel : </b>" + prix + " euros"), 0, 4);
            grille->addWidget(new QLabel("<b>Type de vente : </b>Vente aux enchères"), 2, 4);
        }else {
            grille->addWidget(new QLabel("<b>Prix unitaire : </b>" + prix + " euros"), 0, 4);
            grille->addWidget(new QLabel("<b>Type de vente : </b>Vente normale"), 2, 4);
        }
        i++;

        box->setLayout(grille);
        centre->addWidget(box);
    }
    centre->update();
}

void MaFenetre::update() {
    if(gestionBdd->isConnecte()) {
        /* mets à jour l'interface à la connexion */
        pseudoConnecte->setText(QString::fromStdString(gestionBdd->getUtilisateurConnecte()->getPseudo()));
        boutonConnexion->setText("Se déconnecter");
    }
    if(titreSection->text() == "Ventes en cours") {
        /* mets à jour l'affichage des ventes en cours en cas d'ajout */
        emit signalRechercheProduits(gestionBdd->ventesEnCours());
    }
}

/* vide le layout */
void MaFenetre::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)))
    {
        if (item->layout())
        {
            clearLayout(item->layout());
        }

        layout -> removeItem(item);
        delete item->widget();
        delete item;
    }
}
