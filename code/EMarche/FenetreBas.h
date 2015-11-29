#ifndef FENETREBAS_H
#define FENETREBAS_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

/* Bas de la fenêtre principale de l'application contenant les boutons de changement de pages */

class FenetreBas : public QHBoxLayout
{

public:
    FenetreBas();

private:
    QPushButton *boutonPrecedent;
    QPushButton *boutonSuivant;
    QLabel *numPage;
};

#endif // FENETREBAS_H
