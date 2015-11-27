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
    struct tm dateNaissance;
    std::string email;
    std::string adresse;
    unsigned int nbVentes;
    unsigned int nbAchats;
    unsigned int note;

public:
    /* Constructeur */
    Utilisateur(std::string monPseudo, std::string monMdp, std::string name, std::string firstname, int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr) :
        pseudo(monPseudo), mdp(monMdp), nom(name), prenom(firstname), email(mail), adresse(adr), nbVentes(0), nbAchats(0), note(0) {
        dateNaissance.tm_mday = jourNaiss;
        dateNaissance.tm_mon = moisNaiss;
        dateNaissance.tm_year = anneeNaiss;
    }

    /* Destructeur */
    virtual ~Utilisateur() {}

    /* Fonctions get */
    std::string getPseudo();
    std::string getMdp();
    std::string getNom();
    std::string getPrenom();
    std::string getDateNaissance();
    std::string getEmail();
    std::string getAdresse();
    unsigned int getNbVentes();
    unsigned int getNbAchats();
    unsigned int getNote();

    /* Fonctions set */
    void setPseudo(std::string p);
    void setMdp(std::string m);
    void setNom(std::string n);
    void setPrenom(std::string p);
    void setDateNaissance(int jour, int mois, int annee);
    void setEmail(std::string e);
    void setAdresse(std::string a);
    void setNbVentes(unsigned int n);
    void setNbAchats(unsigned int n);
    void setNote(unsigned int n);

    /* Fonctions d'affichage */
    std::string toString();

    void   decrit(std::ostream &os) {
        os << "------Utilisateur " << getPseudo() << "-------\n" << getPrenom() << " " << getNom() << "\nMot de passe : " << getMdp()
           << "\nDate de naissance : " << getDateNaissance() << "\nEmail : " << getEmail() << "\nAdresse : " << getAdresse()
           << "\nNombre de ventes : " << getNbVentes() << "  Nombre d'achats : " << getNbAchats() << "\nNote : " << getNote();
    }

    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif // UTILISATEUR_H
