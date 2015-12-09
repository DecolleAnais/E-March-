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
#include <QGroupBox>
#include <iostream>
#include "DialogConnexion.h"
#include "DialogInscription.h"
#include "DialogAjouterVente.h"
#include "DialogModificationProfil.h"
#include "Vue.h"
#include "bdd/GestionBdd.h"

/* Fenêtre principale de l'application */

class MaFenetre : public QWidget, public Vue
{
    Q_OBJECT;

public:
    MaFenetre(int l, int h, GestionBdd *bdd);
    ~MaFenetre() {
        delete(haut);
        delete(bas);
        delete(centre);
        delete(centreProfil);
        delete(typeRecherche);
        delete(valRecherche);
        delete(boutonRecherche);
        delete(boutonAccueil);
        delete(boutonProfil);
        delete(boutonAjouterVente);
        delete(pseudoConnecte);
        delete(boutonConnexion);

        delete(titreSection);

        delete(boutonPrecedent);
        delete(boutonSuivant);
        delete(numPage);

    };

    void update();
    void clearLayout(QLayout *layout);

public slots:
    void afficherResUtilisateurs(std::vector<Utilisateur*> v);
    void afficherResProduits(std::vector<Produit*> v);
    void rechercher();
    void accueil();
    void profil();
    void statistiques();
    void ventes();
    void achats();
    void ajouterVente();
    void connexion();
    void modificationProfil();
    void voirProfil(std::string pseudo);
    void voirProduit(std::string ref);

signals:
    void signalRechercheUtilisateur(std::vector<Utilisateur*> v);
    void signalRechercheProduits(std::vector<Produit*> v);

private:
    QHBoxLayout *haut;
    QVBoxLayout *centre;
    QHBoxLayout *centreProfil;
    QHBoxLayout *bas;

    QComboBox *typeRecherche;
    QLineEdit *valRecherche;
    QPushButton *boutonRecherche;
    QPushButton *boutonAccueil;
    QPushButton *boutonProfil;
    QPushButton *boutonAjouterVente;
    QPushButton *boutonStatistiques;
    QPushButton *boutonVentes;
    QPushButton *boutonAchats;
    QPushButton *boutonCompte;
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
