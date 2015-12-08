#include <QApplication>
#include "MaFenetre.h"
#include "bdd/GestionBdd.h"
#include <vector>

using namespace std;


int main(int argc, char *argv[])

{
    /*Produit *p0 = new Produit("prod0","test",1,2,0);
    Utilisateur *u = new Utilisateur("pseudo","mdp","nom","prenom",1,1,2000,"mail","adr");
    u->addVente(p0);
    vector<Produit*>::iterator it;
    vector<Produit*> v = u->getLesVentes();
    for(it = v.begin();it != v.end();it++)
        (*it)->affiche(cout);*/

    QApplication app(argc, argv);

    /* initialisation de la base de données contenant la liste des utilisateurs, des produits etc */
    GestionBdd *gestionBdd = new GestionBdd;
    gestionBdd->inscrire("graou","mdp","nom","prenom",18,04,1994,"mail","adr");
    gestionBdd->inscrire("graou2","mdp","nom","prenom",18,04,1994,"mail","adr");
    gestionBdd->inscrire("blp3","mdp","nom","prenom",18,04,1994,"mail","adr");

    struct tm date;
    date.tm_year = 2016;
    date.tm_mon = 01;
    date.tm_mday = 12;
    gestionBdd->ajouterVente("chaise","meubles",15,4,0);
    gestionBdd->ajouterVente("chocolat","nourriture",5,10,0);
    gestionBdd->ajouterVente("table","meubles",30,1,1, date);

    /* fenêtre principale de l'application */
    maFenetre fenetre(1200,700, gestionBdd);

    fenetre.show();

    return app.exec();

}
