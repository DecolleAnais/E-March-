#include <sstream>
#include "VenteEnchere.h"

using namespace std;

VenteEnchere::VenteEnchere (bool b) : EtatVente(b) {
    dateLimite.tm_year = 2015;
    dateLimite.tm_mon = 11;
    dateLimite.tm_mday = 13;
}

float EtatVente::getPrixActuel(){
    return prixActuel;
}

string EtatVente::getDateLimite(){
    string result;
    stringstream sstm;

    sstm << dateLimite.tm_mday << "/" << dateLimite.tm_mon << "/" << dateLimite.tm_year;
    result = sstm.str();

    return result;
}

void EtatVente::setPrixActuel(float prix){
    prixActuel = prix;
}

void EtatVente::setDateLimite(struct tm date){
    dateLimite = date;
}

