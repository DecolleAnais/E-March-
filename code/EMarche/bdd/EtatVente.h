#ifndef ETATVENTE_H
#define ETATVENTE_H

#include <string>
#include <ctime>
#include <sstream>

class EtatVente {

public:
    EtatVente(bool b);
    bool venteEnCours();
    virtual float getPrixActuel();
    virtual std::string getDateLimite();
    virtual void setPrixActuel(float prix);
    virtual void setDateLimite(struct tm date);

protected:
    bool estEnCours;
    float prixActuel;
    int tempsRestant;
    struct tm dateLimite;
};

#endif
