#include <QApplication>
#include "maFenetre.h"
#include "bdd/GestionBdd.h"


int main(int argc, char *argv[])

{

    QApplication app(argc, argv);

    /* initialisation de la base de données contenant la liste des utilisateurs, des produits etc */
    GestionBdd gestionBdd;

    /* fenêtre principale de l'application */
    maFenetre fenetre(1200,700, gestionBdd);

    fenetre.show();

    return app.exec();

}
