#ifndef VENTEENCHERE_H
#define VENTEENCHERE_H

#include "EtatVente.h"

class VenteEnchere : public EtatVente {

public:
    VenteEnchere(bool b);
    float getPrixActuel();
    std::string getDateLimite();
    void setPrixActuel(float prix);
    void setDateLimite(struct tm date);

private:

};

#endif
