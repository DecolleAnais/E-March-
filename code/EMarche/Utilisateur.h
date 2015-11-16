#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <sstream>
#include <ctime>

class Utilisateur {

private:
    std::string pseudo;
    std::string mdp;
    std::string nom;
    std::string prenom;
    std::time_t date_naiss;
    std::string email;
    std::string adresse;
    unsigned int nbVentes;
    unsigned int nbAchats;
    int noteGlobale;

public:
    /* Constructeur */
    Utilisateur(std::string monPseudo, std::string monMdp, std::string name, std::string firstname, std::time_t date, std::string mail, std::string adr) :
        pseudo(monPseudo), mdp(monMdp), nom(name), prenom(firstname), date_naiss(date), email(mail), adresse(adr), nbVentes(0), nbAchats(0) {}

};

#endif // UTILISATEUR_H
