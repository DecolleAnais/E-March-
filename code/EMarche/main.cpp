#include <QApplication>
#include "MaFenetre.h"
#include "bdd/GestionBdd.h"
#include <vector>

using namespace std;


int main(int argc, char *argv[])

{
    /*LesUtilisateurs users;
    Utilisateur u1("graou","mdp","nom","prenom",18,04,1994,"mail","adr");
    Utilisateur u2("graou2","mdp","nom","prenom",18,04,1994,"mail","adr");
    Utilisateur u3("blp3","mdp","nom","prenom",18,04,1994,"mail","adr");
    users.add(&u1);
    users.add(&u2);
    vector<Utilisateur*> v = users.getUtilisateurs("graou");
    for(unsigned int i = 0;i < v.size();i++) {
        v[i]->affiche(cout);
    }*/

    QApplication app(argc, argv);

    /* initialisation de la base de données contenant la liste des utilisateurs, des produits etc */
    GestionBdd *gestionBdd = new GestionBdd;
    gestionBdd->inscrire("graou","mdp","nom","prenom",18,04,1994,"mail","adr");
    gestionBdd->inscrire("graou2","mdp","nom","prenom",18,04,1994,"mail","adr");
    gestionBdd->inscrire("blp3","mdp","nom","prenom",18,04,1994,"mail","adr");
    //gestionBdd.rechercherUtilisateurs("graou");

    gestionBdd->ajouterVente("chaise","meubles",15,4,0);
    gestionBdd->ajouterVente("chocolat","nourriture",5,10,0);
    gestionBdd->ajouterVente("table","meubles",30,1,1);
    //gestionBdd.rechercherProduitCat("meubles");

    /* fenêtre principale de l'application */
    maFenetre fenetre(1200,700, gestionBdd);

    fenetre.show();

    return app.exec();

}
