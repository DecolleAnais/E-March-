#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QCoreApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <iostream>
#include "DialogConnexion.h"
#include "DialogInscription.h"
#include "DialogAjouterVente.h"
#include "Vue.h"
#include "bdd/GestionBdd.h"

/* Fenêtre principale de l'application */

class maFenetre : public QWidget, public Vue
{
    Q_OBJECT;

public:
    maFenetre(int l, int h, GestionBdd *bdd);

    void update();
    void clearLayout(QLayout *layout);

public slots:
    void afficherResUtilisateurs(std::vector<Utilisateur*> v);
    void afficherResProduits(std::vector<Produit*> v);
    void rechercher();
    void accueil();
    void profil();
    void ajouterVente();
    void connexion();
    void voirProfil(std::string pseudo);

signals:
    void signalRechercheUtilisateur(std::vector<Utilisateur*> v);
    void signalRechercheProduits(std::vector<Produit*> v);

private:
    QHBoxLayout *haut;
    QVBoxLayout *centre;
    QHBoxLayout *bas;

    QComboBox *typeRecherche;
    QLineEdit *valRecherche;
    QPushButton *boutonRecherche;
    QPushButton *boutonAccueil;
    QPushButton *boutonProfil;
    QPushButton *boutonAjouterVente;
    QLabel *pseudoConnecte;
    QPushButton *boutonConnexion;

    QLabel *titreSection;
    QScrollArea *barreDefile;

    QPushButton *boutonPrecedent;
    QPushButton *boutonSuivant;
    QLabel *numPage;

    int largeur;
    int hauteur;
    GestionBdd *gestionBdd;

};

#endif // MAFENETRE_H
