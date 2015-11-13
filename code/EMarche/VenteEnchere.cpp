#include "VenteEnchere.h"

using namespace std;

VenteEnchere::VenteEnchere () : prixActuel(0), tempsRestant(0) {
    dateLimite.tm_year = 2015;
    dateLimite.tm_mon = 11;
    dateLimite.tm_mday = 13;
}

float VenteEnchere::getPrixActuel(){
    return prixActuel;
}

string VenteEnchere::getDateLimite(){

    return "";
}

void VenteEnchere::setPrixActuel(float prix){
    prixActuel = prix;
}

void VenteEnchere::setDateLimite(struct tm date){
    dateLimite = date;
}

