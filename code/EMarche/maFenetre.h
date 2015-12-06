#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include "FenetreHaut.h"
#include "FenetreBas.h"

/* Fenêtre principale de l'application */

class maFenetre : public QWidget, public Vue
{

public:
    maFenetre(int l, int h, GestionBdd bdd);

    void update();

private:
    QLabel *titreSection;
    QScrollArea *barreDefile;
    int largeur;
    int hauteur;
    GestionBdd gestionBdd;

};

#endif // MAFENETRE_H
