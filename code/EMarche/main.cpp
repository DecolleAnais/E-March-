#include <QApplication>
#include "MaFenetre.h"
#include "bdd/GestionBdd.h"
#include <vector>

using namespace std;


int main(int argc, char *argv[])

{
    QApplication app(argc, argv);

    /* initialisation de la base de données contenant la liste des utilisateurs, des produits etc */
    GestionBdd *gestionBdd = new GestionBdd;
    gestionBdd->inscrire("graou","mdp","nom","prenom",18,04,1994,"mail","adr",54000);
    gestionBdd->inscrire("graou2","mdp","nom","prenom",18,04,1994,"mail","adr",68745);
    gestionBdd->inscrire("blp3","mdp","nom","prenom",18,04,1994,"mail","adr",78650);


    struct tm date;
    date.tm_year = 2016;
    date.tm_mon = 01;
    date.tm_mday = 12;
    gestionBdd->ajouterVente("chaise","meubles",15,4,0);
    //gestionBdd->ajouterVente("chocolat","nourriture",5,10,0);
    gestionBdd->ajouterVente("table","meubles",30,1,1, date);
    gestionBdd->ajouterVente("peluche pingouin","déco",25,2,0);
    //gestionBdd->ajouterVente("guirlande","déco",1,5,0);

    /*gestionBdd->ajouterVente("chocolat","nourriture",5,10,0);
    gestionBdd->ajouterVente("camion","véhicule",10000,1,0);
    gestionBdd->ajouterVente("table","meubles",30,1,1, date);*/

    gestionBdd->connecterUtilisateur("graou","mdp");

    /* fenêtre principale de l'application */
    MaFenetre fenetre(1200,700, gestionBdd);

    fenetre.show();
    return app.exec();

}
