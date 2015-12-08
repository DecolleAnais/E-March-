#include "MaFenetre.h"

using namespace std;

maFenetre::maFenetre(int l, int h, GestionBdd *bdd) : largeur(l), hauteur(h), gestionBdd(bdd)
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
    typeRecherche->addItem("Produit/nom");
    typeRecherche->addItem("Produit/tags");
    typeRecherche->addItem("Produit/catégorie");
    typeRecherche->addItem("Utilisateur");

    /* texte de la recherche */
    valRecherche = new QLineEdit;

    /* bouton rechercher */
    boutonRecherche = new QPushButton("Rechercher");

    QObject::connect(boutonRecherche, SIGNAL(clicked()), this, SLOT(rechercher()));
    QObject::connect(this,SIGNAL(signalRechercheUtilisateur(std::vector<Utilisateur*>)),this, SLOT(afficherResUtilisateurs(std::vector<Utilisateur*>)));
    QObject::connect(this,SIGNAL(signalRechercheProduits(std::vector<Produit*>)),this, SLOT(afficherResProduits(std::vector<Produit*>)));

    /* bouton accueil */
    boutonAccueil = new QPushButton("Accueil");
    QObject::connect(boutonAccueil, SIGNAL(clicked()), this, SLOT(accueil()));

    /* bouton profil */
    boutonProfil = new QPushButton("Mon profil");
    QObject::connect(boutonProfil, SIGNAL(clicked()), this, SLOT(profil()));

    /* bouton ajouterVente */
    boutonAjouterVente = new QPushButton("Ajouter vente");
    QObject::connect(boutonAjouterVente, SIGNAL(clicked()), this, SLOT(ajouterVente()));

    /* label peudo de l'utilisateur connecté */
    pseudoConnecte = new QLabel("");

    /* bouton connexion */
    boutonConnexion = new QPushButton("Se connecter");     // bouton connexion
    //QObject::connect(boutonConnexion, SIGNAL(clicked()), new DialogConnexion(gestionBdd), SLOT(ouvrir()));
    QObject::connect(boutonConnexion, SIGNAL(clicked()), this, SLOT(connexion()));

    /* Layouts */
    haut->addWidget(typeRecherche);
    haut->addWidget(valRecherche);
    haut->addWidget(boutonRecherche);
    haut->addWidget(boutonAccueil);
    haut->addWidget(boutonProfil);
    haut->addWidget(boutonAjouterVente);
    haut->addWidget(pseudoConnecte);
    haut->addWidget(boutonConnexion);

    /*********************************************
     * CENTRE                                    *
     * ******************************************/

    /* Titre de la section */
    titreSection = new QLabel("Ventes en cours", this);
    QScrollArea *defile = new QScrollArea;
    defile->setLayout(centre);
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
    vLayout->addWidget(defile);
    vLayout->addLayout(bas);

    setLayout(vLayout);


}

/************************************
 * FONCTIONS                        *
 * **********************************/
void maFenetre::rechercher() {
    /* Récupération des valeurs pour la recherche */
    string type = typeRecherche->currentText().toStdString();
    string val = valRecherche->text().toStdString();

    if(type.compare("Utilisateur") == 0) {
        /* Recherche d'un utilisateur */
        vector<Utilisateur*> v = gestionBdd->rechercherUtilisateurs(val);
        emit signalRechercheUtilisateur(v);
        titreSection->setText("Résultats de la recherche de l'utilisateur " + QString::fromStdString(val));

    }else if(type.compare("Produit/ref") == 0){
        /* Recherche d'un produit par référence*/
        //vector<Produit*> v = gestionBdd.rechercherProduitRef(val);
        vector<Produit*> v;
        v.push_back(gestionBdd->rechercherProduit(val));
        emit signalRechercheProduits(v);
        titreSection->setText("Résultats de la recherche de la référence " + QString::fromStdString(val));
    }else if(type.compare("Produit/nom") == 0){
        /* Recherche d'un produit par nom*/
        vector<Produit*> v = gestionBdd->rechercherProduitNom(val);
        emit signalRechercheProduits(v);
        titreSection->setText("Résultats de la recherche du produit " + QString::fromStdString(val));
    }else if(type.compare("Produit/tags") == 0){
        /* Recherche d'un produit par tags*/
        vector<Produit*> v = gestionBdd->rechercherProduitTags(val);
        emit signalRechercheProduits(v);
        titreSection->setText("Résultats de la recherche des tags " + QString::fromStdString(val));
    }else {
        /* Recherche d'un produit par catégorie*/
        //vector<Produit*> v = gestionBdd.rechercherProduitCat(val);
        vector<Produit*> v = gestionBdd->rechercherCategorie(val);
        emit signalRechercheProduits(v);
        titreSection->setText("Résultats de la recherche de la catégorie " + QString::fromStdString(val));
    }
}

/* retour à l'accueil avec l'affichage des ventes en cours */
void maFenetre::accueil() {
    titreSection->setText("Ventes en cours");
    emit signalRechercheProduits(gestionBdd->ventesEnCours());
}

/* voir mon profil */
void maFenetre::profil() {
    titreSection->setText("Mon profil");
    clearLayout(centre);
}

/* ajouter une vente */
void maFenetre::ajouterVente() {
    if(gestionBdd->isConnecte()) {
        DialogAjouterVente *ajouterVente = new DialogAjouterVente(gestionBdd);
    }else {
        QMessageBox::warning(this, "Ajouter une vente", "Attention, vous devez être connecté pour ajouter un produit en vente !");
    }
}

/* connexion */
void maFenetre::connexion() {
    if(gestionBdd->isConnecte()) {
        gestionBdd->deconnecterUtilisateur();
        pseudoConnecte->setText("");
        boutonConnexion->setText("Se connecter");
    }else {
        DialogConnexion *connexion = new DialogConnexion(gestionBdd);
    }
}

/* affichage du résultat d'une recherche d'utilisateurs */
void maFenetre::afficherResUtilisateurs(vector<Utilisateur*> v) {
    clearLayout(centre);
    /* pour chaque utilisateur correspondant */
    vector<Utilisateur*>::iterator it;
    for(it = v.begin();it != v.end();it++) {
        QHBoxLayout *box = new QHBoxLayout;
        box->setAlignment(Qt::AlignLeft);
        string pseudoStr = (*it)->getPseudo();
        QString pseudo = QString::fromStdString(pseudoStr);
        QString note = QString::number((*it)->getNote());
        /* affichage du pseudo et de la note */
        box->addWidget(new QLabel("Pseudo : " + pseudo + "  -   Note : " + note));
        /* création d'un bouton pour accéder au profil concerné */
        QPushButton *voirProfil = new QPushButton("Voir profil");
        //QObject::connect(voirProfil, SIGNAL(clicked()), this, SLOT(voirProfil(string pseudoStr)));
        box->addWidget(voirProfil);
        centre->addLayout(box);
    }
    centre->update();
}

/* affichage du résultat d'une recherche de produits */
void maFenetre::afficherResProduits(vector<Produit*> v) {
    clearLayout(centre);
    vector<Produit*>::iterator it;
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
        grille->addWidget(new QLabel("Nom : " + nom), 0, 0);
        grille->addWidget(new QLabel("Référence : " + ref), 0, 1);
        grille->addWidget(new QLabel("Catégorie : " + cat), 1, 0);
        grille->addWidget(new QLabel("Date du dépôt : " + dateDepot), 2, 0);
        grille->addWidget(new QLabel("Quantité : " + qte), 3, 0);
        grille->addWidget(new QLabel("Vendeur : " + vendeur), 4, 0);

        /* affichages spécifiques aux enchères ou ventes normales */
        /* PROBLEME LE PRODUIT TABLE CREE DANS LE MAIN NE PASSE PAS DANS LES ENCHERES, MAUVAIS AFFICHAGE*/
        if((*it)->getEtatVente() == "Vente aux enchères") {
            QString dateLimite = QString::fromStdString((*it)->getDateLimite());
            grille->addWidget(new QLabel("Date Limite : " + dateLimite));
            grille->addWidget(new QLabel("Prix Actuel : " + prix), 0, 4);
            grille->addWidget(new QLabel("Vente aux Enchères"), 2, 4);
        }else {
            grille->addWidget(new QLabel("Prix Unitaire : " + prix), 0, 4);
            grille->addWidget(new QLabel("Vente Normale"), 2, 4);
        }

        /* création d'un bouton pour accéder au produit concerné */
        QPushButton *voirProduit = new QPushButton("Voir produit");
        grille->addWidget(voirProduit, 2, 5);
        //QObject::connect(voirProduit, SIGNAL(clicked()), this, SLOT(voirProduit(string nom)));

        box->setLayout(grille);
        centre->addWidget(box);
    }
    centre->update();
}

void maFenetre::voirProfil(string pseudo) {

}

void maFenetre::update() {
    if(gestionBdd->isConnecte()) {
        pseudoConnecte->setText(QString::fromStdString(gestionBdd->getUtilisateurConnecte()->getPseudo()));
        boutonConnexion->setText("Se déconnecter");
    }
}

/* vide le layout */
void maFenetre::clearLayout(QLayout *layout)
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
