#ifndef ETATVENTE_H
#define ETATVENTE_H

class EtatVente {

public:
    EtatVente(bool b);
    bool venteEnCours();

private:
    bool estEnCours;

};

#endif
