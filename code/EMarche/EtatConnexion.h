#ifndef ETATCONNEXION_H
#define ETATCONNEXION_H

class EtatConnexion {

public :
    EtatConnexion(bool b);
    bool connexionEnCours();

private :
    bool estConnecte;
};

#endif
