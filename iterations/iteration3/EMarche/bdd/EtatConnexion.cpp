#include "EtatConnexion.h"

EtatConnexion::EtatConnexion(bool b):estConnecte(b){

}

bool EtatConnexion::connexionEnCours(){
    return estConnecte;
}

