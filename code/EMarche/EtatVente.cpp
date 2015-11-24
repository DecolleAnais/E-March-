#include "EtatVente.h"

EtatVente::EtatVente(bool b):estEnCours(b){

}

bool EtatVente::venteEnCours(){
    return estEnCours;
}

