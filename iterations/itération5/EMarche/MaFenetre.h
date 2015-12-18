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
#include <QSpinBox>
#include <QTimer>
#include <QSignalMapper>
#include <iostream>
#include "DialogConnexion.h"
#include "DialogInscription.h"
#include "DialogAjouterVente.h"
#include "DialogModificationProfil.h"
#include "DialogAcheter.h"
#include "Vue.h"
#include "bdd/GestionBdd.h"
#include "bdd/LesUtilisateurs.h"

/* Fenêtre principale de l'application */

//!
//! \brief The MaFenetre class - Affichage principal de l'application
//!
class MaFenetre : public QWidget, public Vue
{
    Q_OBJECT

public:
    //!
    //! \brief MaFenetre - Constructeur
    //! \param l - largeur
    //! \param h - hauteur
    //! \param bdd - Lien vers GestionBdd qui contient toutes les données
    //!
    MaFenetre(int l, int h, GestionBdd *bdd);
    ~MaFenetre() {
        delete(haut);
        delete(bas);
        delete(centre);
        delete(typeRecherche);
        delete(valRecherche);
        delete(boutonRecherche);
        delete(boutonAccueil);
        delete(boutonProfil);
        delete(boutonAjouterVente);
        delete(pseudoConnecte);
        delete(boutonConnexion);

        delete(titreSection);
        delete(barreDefile);

        delete(boutonPrecedent);
        delete(boutonSuivant);
        delete(numPage);
    }

    //!
    //! \brief update - Mets à jour la fenêtre principal
    //!
    void update();

    //!
    //! \brief clearLayout - Vide un layout entré en paramètre
    //! \param layout
    //!
    void clearLayout(QLayout *layout);

public slots:
    //!
    //! \brief afficherResUtilisateurs - Affiche le résultat d'une recherche d'utilisateur
    //! \param v - Utilisateurs à afficher
    //!
    void afficherResUtilisateurs(std::vector<Utilisateur*> v);
    //!
    //! \brief afficherResProduits - Affiche le résultat d'une recherche de produit
    //! \param v - Produits à afficher
    //!
    void afficherResProduits(std::vector<Produit*> v);
    //!
    //! \brief rechercher - Redirige vers l'affichage d'utilisateurs ou de produits selon le type de recherche lancé
    //!
    void rechercher();
    //!
    //! \brief accueil - Affiche les produits en vente actuellement
    //!
    void accueil();
    //!
    //! \brief profil - Affiche le profil de l'utilisateur connecté
    //!
    void profil();
    //!
    //! \brief statistiques - Affiche les statistiques de l'utilisateur connecté
    //!
    void statistiques();
    //!
    //! \brief ventes - Affiche les ventes de l'utilisateur connecté
    //!
    void ventes();
    //!
    //! \brief achats - Affiche les achats de l'utilisateur connecté
    //!
    void achats();
    //!
    //! \brief ajouterVente - Ouvre la boîte de dialogue permettant d'ajouter une vente si on est connecté
    //!
    void ajouterVente();
    //!
    //! \brief connexion - Ouvre la boîte de dialogue de connexion
    //!
    void connexion();
    //!
    //! \brief modificationProfil - Ouvre la boîte de dialogue de modification de profil de l'utilisateur connecté
    //!
    void modificationProfil();
    //!
    //! \brief voirProduit - Affiche les données du produit et permet de l'acheter
    //! \param ref
    //!
    void voirProduit(QString ref);
    //!
    //! \brief acheter - Achète le produit si on est connecté
    //!
    void acheter();

signals:
    //!
    //! \brief signalRechercheUtilisateur - Signale qu'il s'agit d'une recherche d'utilisateurs
    //! \param v - Utilisateurs à afficher
    //!
    void signalRechercheUtilisateur(std::vector<Utilisateur*> v);
    //!
    //! \brief signalRechercheProduits - Signale qu'il s'agit d'une recherche de produits
    //! \param v - Produits à afficher
    //!
    void signalRechercheProduits(std::vector<Produit*> v);

protected:
    //!
    //! \brief haut - Contient la barre de recherche, l'accueil, l'ajout de vente, mon profil, connexion
    //!
    QHBoxLayout *haut;
    //!
    //! \brief centre - Contient le titre de ce qu'on affiche au centre et les affichages
    //!
    QVBoxLayout *centre;
    //!
    //! \brief centreProfil - Contient l'affichage du profil
    //!
    QHBoxLayout *centreProfil;
    //!
    //! \brief bas - Contient le changement de pages
    //!
    QHBoxLayout *bas;

    //!
    //! \brief typeRecherche - Type de la recherche : Produit ou Utilisateur
    //!
    QComboBox *typeRecherche;
    //!
    //! \brief valRecherche - Ce que l'on veut rechercher
    //!
    QLineEdit *valRecherche;
    //!
    //! \brief boutonRecherche - Lancement de la recherche
    //!
    QPushButton *boutonRecherche;
    //!
    //! \brief boutonAccueil - Affichage des ventes en cours
    //!
    QPushButton *boutonAccueil;
    //!
    //! \brief boutonProfil - Affichage du profil de l'utilisateur
    //!
    QPushButton *boutonProfil;
    //!
    //! \brief boutonAjouterVente - Permet d'ajouter un produit en vente
    //!
    QPushButton *boutonAjouterVente;
    //!
    //! \brief boutonStatistiques - Affichage des statistiques utilisateur
    //!
    QPushButton *boutonStatistiques;
    //!
    //! \brief boutonVentes - Affichage des ventes utilisateur
    //!
    QPushButton *boutonVentes;
    //!
    //! \brief boutonAchats - Affichage des achats utilisateurs
    //!
    QPushButton *boutonAchats;
    //!
    //! \brief boutonAnnulerAchat
    //!
    QPushButton *boutonAnnulerAchat;
    //!
    //! \brief boutonAnnulerVente
    //!
    QPushButton *boutonAnnulerVente;
    //!
    //! \brief boutonCompte - Affichage du profil de l'utilisateur connecté
    //!
    QPushButton *boutonCompte;
    //!
    //! \brief pseudoConnecte - Affichage du pseudo de l'utilisateur connecté
    //!
    QLabel *pseudoConnecte;
    //!
    //! \brief boutonConnexion - Permet de se connecter/déconnecter
    //!
    QPushButton *boutonConnexion;
    //!
    //! \brief titreSection - Affiche le titre de ce qu'on affiche au centre
    //!
    QLabel *titreSection;
    //!
    //! \brief barreDefile - "Cadre" du centre de l'affichage
    //!
    QScrollArea *barreDefile;
    //!
    //! \brief boutonPrecedent - Permet de passer à la page précédente
    //!
    QPushButton *boutonPrecedent;
    //!
    //! \brief boutonSuivant - Permet de passer à la page suivante
    //!
    QPushButton *boutonSuivant;
    //!
    //! \brief numPage - Affiche le numéro de page actuel
    //!
    QLabel *numPage;
    //!
    //! \brief modifProfil - Boîte de dilaogue de modification de profil
    //!
    DialogModificationProfil *modifProfil;
    //!
    //! \brief ajouterVentes - Boîte de dialogue d'ajout de vente
    //!
    DialogAjouterVente *ajouterVentes;
    //!
    //! \brief connexions - Boîte de dialogue de connexion
    //!
    DialogConnexion *connexions;
    //!
    //! \brief achats - Boîte de dialogue d'achats
    //!
    DialogAcheter *acheterQuantite;
    //!
    //! \brief largeur - largeur de la fenêtre
    //!
    int largeur;
    //!
    //! \brief hauteur - hauteur de la fenêtre
    //!
    int hauteur;
    //!
    //! \brief gestionBdd - Lien vers GestionBdd qui contient toutes les données
    //!
    GestionBdd *gestionBdd;
    //!
    //! \brief produitCourant - Poduit sélectionné via "Voir produit"
    //!
    Produit *produitCourant;
    //!
    //! \brief mapperProduit
    //!
    QSignalMapper mapperProduit;
    //!
    //! \brief mapperProfil
    //!
    QSignalMapper mapperProfil;
    //!
    //! \brief mapperStatistiques
    //!
    QSignalMapper mapperStatistiques;
    //!
    //! \brief mapperVentes
    //!
    QSignalMapper mapperVentes;
    //!
    //! \brief mapperAchats
    //!
    QSignalMapper mapperAchats;

};

#endif // MAFENETRE_H
