#include <QApplication>
#include "maFenetre.h"
#include "bdd/GestionBdd.h"


int main(int argc, char *argv[])

{

    QApplication app(argc, argv);
    GestionBdd gestionBdd;

    /* fenêtre */
    maFenetre fenetre(1200,700, gestionBdd);

    fenetre.show();

    return app.exec();

}
