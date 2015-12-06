#ifndef FENETREHAUT_H
#define FENETREHAUT_H

#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "bdd/GestionBdd.h"

/* Haut de la fenêtre principale de l'application contenant les boutons de recherche et de connexion */

class FenetreHaut : public QHBoxLayout, public Vue
{
Q_OBJECT;

public:
    FenetreHaut(GestionBdd bdd);

    void update();

public slots:
    void rechercher();

private:
    QComboBox *typeRecherche;
    QLineEdit *valRecherche;
    QPushButton *boutonRecherche;
    QLabel *pseudoConnecte;
    QPushButton *boutonConnexion;
    GestionBdd gestionBdd;


};

#endif // FENETREHAUT_H
