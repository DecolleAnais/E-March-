#ifndef FENETREHAUT_H
#define FENETREHAUT_H

#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include "bdd/GestionBdd.h"

/* Haut de la fenêtre principale de l'application contenant les boutons de recherche et de connexion */

class FenetreHaut : public QHBoxLayout
{

public:
    FenetreHaut(GestionBdd bdd);

private slots:
    void on_boutonRecherche_clicked();

private:
    QComboBox *typeRecherche;
    QLineEdit *valRecherche;
    QPushButton *boutonRecherche;
    QPushButton *boutonConnexion;
    GestionBdd gestionBdd;


};

#endif // FENETREHAUT_H
