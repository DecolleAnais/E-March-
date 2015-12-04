#include "EtatVente.h"

using namespace std;

EtatVente::EtatVente(bool b):estEnCours(b){

}

bool EtatVente::venteEnCours(){
    return estEnCours;
}
