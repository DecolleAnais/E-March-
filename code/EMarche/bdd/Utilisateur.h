#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "Produit.h"
#include "Avis.h"

//!
//! \brief The Utilisateur class - Contient toutes les informations personnelles d'un utilisateur
//!
class Utilisateur {

private:
    std::string pseudo;
    std::string mdp;
    std::string nom;
    std::string prenom;
    struct tm dateNaissance;
    std::string email;
    std::string adresse;
    std::string ville;
    unsigned int nbVentes;
    unsigned int nbAchats;
    unsigned int nbAvis;
    unsigned int note;
    unsigned int nbNotes;
    int codePostal;
    std::vector<Produit*> lesAchats;
    std::vector<Produit*> lesVentes;
    std::vector<Avis> lesAvis;

public:
    /* Constructeur */
    //!
    //! \fn Utilisateur(std::string monPseudo, std::string monMdp, std::string name, std::string firstname, int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr, int cP)
    //! \brief Utilisateur - Constructeur
    //! \param monPseudo - Pseudo de l'utilisateur
    //! \param monMdp - Mot de passe de l'utilisateur
    //! \param name - Nom de l'utilisateur
    //! \param firstname - Prénom de l'utilisateur
    //! \param jourNaiss - Jour de naissance de l'utilisateur
    //! \param moisNaiss - Mois de naissance de l'utilisateur
    //! \param anneeNaiss - Année de naissance de l'utilisateur
    //! \param mail - Adresse mail de l'utilisateur
    //! \param adr - Adresse de l'utilisateur
    //! \param cP - Code postal de l'utilisateur
    //!
    Utilisateur(std::string monPseudo, std::string monMdp, std::string name, std::string firstname, int jourNaiss, int moisNaiss, int anneeNaiss, std::string mail, std::string adr, int cP) :
        pseudo(monPseudo), mdp(monMdp), nom(name), prenom(firstname), email(mail), adresse(adr), nbVentes(0), nbAchats(0), nbAvis(0), note(0), nbNotes(0), codePostal(cP) {
        dateNaissance.tm_mday = jourNaiss;
        dateNaissance.tm_mon = moisNaiss;
        dateNaissance.tm_year = anneeNaiss;
    }

    //!
    //! \fn Utilisateur()
    //! \brief Utilisateur - Constructeur vide
    //!
    Utilisateur() : pseudo(""){}

    /* Destructeur */
    ~Utilisateur() {
        std::vector<Produit*>::iterator it;
        for(it = lesAchats.begin(); it != lesAchats.end();it++) {
            delete(*it);
        }
        for(it = lesVentes.begin(); it != lesVentes.end();it++) {
            delete(*it);
        }
    }

    /* Fonctions get */
    //!
    //! \fn std::string getPseudo()
    //! \brief getPseudo
    //! \return le pseudo de l'utilisateur
    //!
    std::string getPseudo();

    //!
    //! \fn std::string getMdp()
    //! \brief getMdp
    //! \return le mot de passe de l'utilisateur
    //!
    std::string getMdp();

    //!
    //! \fn std::string getNom()
    //! \brief getNom
    //! \return le nom de l'utilisateur
    //!
    std::string getNom();

    //!
    //! \fn std::string getPrenom()
    //! \brief getPrenom
    //! \return le prénom de l'utilisateur
    //!
    std::string getPrenom();

    //!
    //! \fn std::string getDateNaissance()
    //! \brief getDateNaissance
    //! \return la date de naissance de l'utilisateur sous forme de string
    //!
    std::string getDateNaissance();

    //!
    //! \fn std::string getEmail()
    //! \brief getEmail
    //! \return l'adresse e-mail de l'utilisatueur
    //!
    std::string getEmail();

    //!
    //! \fn std::string getAdresse()
    //! \brief getAdresse
    //! \return l'adresse de l'utilisateur
    //!
    std::string getAdresse();

    //!
    //! \fn std::string getVille()
    //! \brief getVille
    //! \return la ville de l'utilisateur
    //!
    std::string getVille();

    //!
    //! \fn int getCodePostal()
    //! \brief getCodePostal
    //! \return le code postal de l'utilisateur
    //!
    int getCodePostal();

    //!
    //! \fn unsigned int getNbVentes()
    //! \brief getNbVentes
    //! \return le nombre de ventes de l'utilisateur
    //!
    unsigned int getNbVentes();

    //!
    //! \fn unsigned int getNbAchats()
    //! \brief getNbAchats
    //! \return le nombre d'achats de l'utilisateur
    //!
    unsigned int getNbAchats();

    //!
    //! \fn unsigned int getNote()
    //! \brief getNote
    //! \return la note de l'utilisateur attribuée par les autres utilisateurs
    //!
    unsigned int getNote();

    //!
    //! \fn std::vector<Produit*> getLesAchats()
    //! \brief getLesAchats
    //! \return un vector contenant les pointeurs vers les achats de l'utilisateur
    //!
    std::vector<Produit*> getLesAchats();

    //!
    //! \fn std::vector<Produit*> getLesVentes()
    //! \brief getLesVentes
    //! \return un vector contenant les pointeurs vers les ventes de l'utilisateur
    //!
    std::vector<Produit*> getLesVentes();
    std::vector<Avis> getLesAvis();
    void getLesAvis(unsigned int deb, unsigned int nb);

    /* Fonctions set */
    //!
    //! \fn void setPseudo(std::string p)
    //! \brief setPseudo
    //! \param p - nouveau pseudo
    //!
    void setPseudo(std::string p);

    //!
    //! \fn void setMdp(std::string m)
    //! \brief setMdp
    //! \param m - nouveau mot de passe
    //!
    void setMdp(std::string m);

    //!
    //! \fn void setNom(std::string n)
    //! \brief setNom
    //! \param n - nouveau nom
    //!
    void setNom(std::string n);

    //!
    //! \fn void setPrenom(std::string p)
    //! \brief setPrenom
    //! \param p - nouveau prénom
    //!
    void setPrenom(std::string p);

    //!
    //! \fn void setDateNaissance(int jour, int mois, int annee)
    //! \brief setDateNaissance
    //! \param jour - nouveau jour de naissance
    //! \param mois - nouveau mois de naissance
    //! \param annee - nouvelle année de naissance
    //!
    void setDateNaissance(int jour, int mois, int annee);

    //!
    //! \fn void setEmail(std::string e)
    //! \brief setEmail
    //! \param e - nouvelle adresse e-mail
    //!
    void setEmail(std::string e);

    //!
    //! \fn void setAdresse(std::string a)
    //! \brief setAdresse
    //! \param a - nouvelle adresse
    //!
    void setAdresse(std::string a);

    //!
    //! \fn void setCodePostal(int i)
    //! \brief setCodePostal
    //! \param i - nouveau code postal
    //!
    void setCodePostal(int i);

    //!
    //! \fn void setVille(std::string v)
    //! \brief setVille
    //! \param v - nouvelle ville
    //!
    void setVille(std::string v);

    //!
    //! \fn void setNbVentes(unsigned int n)
    //! \brief setNbVentes
    //! \param n - nouveau nombre de ventes
    //!
    void setNbVentes(unsigned int n);

    //!
    //! \fn void setNbAchats(unsigned int n)
    //! \brief setNbAchats
    //! \param n - nouveau nombre d'achats
    //!
    void setNbAchats(unsigned int n);

    //!
    //! \fn void setNote(unsigned int n)
    //! \brief setNote
    //! \param n - nouvelle note
    //!
    void setNote(unsigned int n);

    /* Autres fonctions */
    //!
    //! \fn void addAchat(Produit* p)
    //! \brief addAchat
    //! \param p - Pointeur vers le nouveau produit à ajouter aux achats
    //!
    void addAchat(Produit* p, int quantite);

    //!
    //! \fn void addVente(Produit* p)
    //! \brief addVente
    //! \param p - Pointeur vers le nouveau produit à ajouter aux ventes
    //!
    void addVente(Produit* p);

    //!
    //! \fn void deleteAchat(Produit* p)
    //! \brief deleteAchat
    //! \param p - Pointeur vers le nouveau produit à supprimer des achats
    //!
    void deleteAchat(Produit * p);

    //!
    //! \fn void deleteVente(Produit* p)
    //! \brief deleteVente
    //! \param p - Pointeur vers le nouveau produit à supprimer des ventes
    //!
    void deleteVente(Produit* p);

    //!
    //! \fn void addAvis(Avis a)
    //! \brief addAvis
    //! \param a - Avis à ajouter à l'utilisateur dans le vector lesAvis
    //!
    void addAvis(Avis a);

    /* Fonctions d'affichage */
    //!
    //! \fn void   decrit(std::ostream &os)
    //! \brief decrit - Ecrit toutes les données utilisateur dans un flux donné en paramètre
    //! \param os - Flux
    //!
    void   decrit(std::ostream &os) {
        os << "------Utilisateur " << getPseudo() << "-------\n" << getPrenom() << " " << getNom() << "\nMot de passe : " << getMdp()
           << "\nDate de naissance : " << getDateNaissance() << "\nEmail : " << getEmail() << "\nAdresse : " << getAdresse()
           << "\nNombre de ventes : " << getNbVentes() << "  Nombre d'achats : " << getNbAchats() << "\nNote : " << getNote();
    }

    //!
    //! \fn std::string decrit()
    //! \brief decrit - convertit un flux en string
    //! \return un string à partir d'un flux
    //!
    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    //!
    //! \fn void  affiche(std::ostream &os)
    //! \brief affiche - Ecrit toutes les données utilisateur d'un flux vers une sortie
    //! \param os - Sortie, par exemple : cout
    //!
    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif // UTILISATEUR_H
