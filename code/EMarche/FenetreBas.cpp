#include "FenetreBas.h"

FenetreBas::FenetreBas()
{
    /* Boutons de changement de page */
    boutonPrecedent = new QPushButton("<");
    boutonSuivant = new QPushButton(">");
    numPage = new QLabel("1");
    addWidget(boutonPrecedent);
    addWidget(numPage);
    addWidget(boutonSuivant);
    setAlignment(Qt::AlignHCenter);

}
