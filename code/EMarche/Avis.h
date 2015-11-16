#ifndef AVIS_H
#define AVIS_H

#include <string>
#include <sstream>

class Avis {

private:
    unsigned int note;
    std::string commentaire;

public:

    /* Constructeurs */
    Avis(unsigned int notation) : note(notation), commentaire("") {}
    Avis(unsigned int notation, std::string com) : note(notation), commentaire(com) {}

    /* Fonctions get */
    unsigned int getNote();
    std::string getCommentaire();

    /* Affichage */

    void   decrit(std::ostream &os) {
        os << "------Avis-------\nNote : " << getNote() << "\nCommentaire : " << getCommentaire() ;
    }

    std::string decrit() {
        std::ostringstream os;  decrit(os);  return os.str();
    }

    void  affiche(std::ostream &os) {
        decrit(os); os << std::endl;
    }

};

#endif // AVIS_H
