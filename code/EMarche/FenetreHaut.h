#ifndef FENETREHAUT_H
#define FENETREHAUT_H

#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include "bdd/GestionBdd.h"

class FenetreHaut : public QHBoxLayout
{

public:
    FenetreHaut(GestionBdd bdd);

private:
    QComboBox *typeRecherche;
    QLineEdit *valRecherche;
    QPushButton *boutonRecherche;
    QPushButton *boutonConnexion;
    GestionBdd gestionBdd;


};

#endif // FENETREHAUT_H
