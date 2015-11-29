#include "GestionBdd.h"

GestionBdd::GestionBdd()
{

}

/* Fonctions */

/* inscription */
void GestionBdd::inscrire(std::string monPseudo, std::string monMdp, std::string name, std::string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr)
{
    Utilisateur u(monPseudo, monMdp, name, firstname, jourNaiss, moisNaiss, anneeNaiss, mail, adr);
    utilisateurs.add(&u);
    utilisateurs.affiche();
}
