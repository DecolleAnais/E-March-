#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include <string>
#include "LesUtilisateurs.h"

class GestionBdd
{

private:
    LesUtilisateurs utilisateurs;

public:
    GestionBdd();

    /* Fonctions */
    void inscrire(std::string monPseudo, std::string monMdp, std::string name, std::string firstname,
                  int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr);
};

#endif // GESTIONBDD_H
