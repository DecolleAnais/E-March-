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

    /* bouton ajouterVente */
    boutonAjouterVente = new QPushButton("Ajouter vente");
    QObject::connect(boutonAjouterVente, SIGNAL(clicked()), this, SLOT(ajouterVente()));

    /* label peudo de l'utilisateur connecté */
    pseudoConnecte = new QLabel("");

    /* bouton connexion */
    boutonConnexion = new QPushButton("Se connecter");     // bouton connexion
    QObject::connect(boutonConnexion, SIGNAL(clicked()), new DialogConnexion(gestionBdd), SLOT(ouvrir()));

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
    QScrollArea *defile = new QScrollArea;
    defile->setLayout(centre);

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
    clearLayout(centre);
}

/* ajouter une vente */
void maFenetre::ajouterVente() {
    if(gestionBdd->isConnecte()) {
        DialogAjouterVente ajouterVente;
    }else {
        QMessageBox::warning(this, "Ajouter une vente", "Attention, vous devez être connecté pour ajouter un produit en vente !");
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
        QHBoxLayout *box = new QHBoxLayout;
        box->setAlignment(Qt::AlignLeft);
        QString ref = QString::fromStdString((*it)->getReference());
        QString nom = QString::fromStdString((*it)->getNom());
        QString cat = QString::fromStdString((*it)->getCategorie());
        QString prix = QString::number((*it)->getPrixUnitaire());
        QString qte = QString::number((*it)->getQuantite());
        //QString vendeur = QString::fromStdString((*it)->getVendeur());
        //QString dateLimite = QString::fromStdString((*it)->getDateLimite());
        box->addWidget(new QLabel("Reference : " + ref + "   -   Nom : " + nom + "   -   Catégorie : " + cat + "\nPix Unitaire : " + prix + "    -   Quantité : " + qte));
        /* création d'un bouton pour accéder au produit concerné */
        QPushButton *voirProduit = new QPushButton("Voir produit");
        //QObject::connect(voirProduit, SIGNAL(clicked()), this, SLOT(voirProduit(string nom)));
        centre->addLayout(box);
    }
    centre->update();
}

void maFenetre::voirProfil(string pseudo) {

}

void maFenetre::update() {
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
