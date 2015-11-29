#ifndef AVIS_H
#define AVIS_H

#include <string>
#include <sstream>

class Avis {

private:
    unsigned int note;
    std::string commentaire;
    std::string auteur;

public:

    /* Constructeurs */
    Avis(std::string author, unsigned int notation) : note(notation), commentaire(""), auteur(author) {}
    Avis(std::string author, unsigned int notation, std::string com) : note(notation), commentaire(com), auteur(author) {}

    /* Fonctions get */
    unsigned int getNote();
    std::string getCommentaire();
    std::string getAuteur();

    /* Affichage */

    void   decrit(std::ostream &os) {
        os << "------Avis-------\nAuteur : " << getAuteur() << "\nNote : " << getNote() << "\nCommentaire : " << getCommentaire() ;
    }

    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif // AVIS_H
