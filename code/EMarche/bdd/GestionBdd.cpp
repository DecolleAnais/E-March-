#include "GestionBdd.h"
#include <iostream>

using namespace std;

GestionBdd::GestionBdd() : utilisateurConnecte(new Utilisateur()), ref("0")
{

}

/* Génération de la référence */
int valRef = 1;
string nouvelleRef = "#1";
string GestionBdd::generateReference() {
    vector<Produit*>::iterator it;
    vector<Produit*> lesProduits = produits.getListProduits();
    for (it = lesProduits.begin(); it != lesProduits.end(); it++) {
        if((*it)->getReference().compare(nouvelleRef) == 0) {
            while((*it)->getReference().compare(nouvelleRef) == 0) {
                valRef++;
                string s = to_string(valRef);
                nouvelleRef = "#" + s;
            }
        }
    }
    return nouvelleRef;
}

/* Fonctions */

/* incrémenter ref */
void GestionBdd::incrementerRef() {
    int r = atoi(ref.c_str());
    r++;
    ostringstream ss;
    ss << r;
    ref = ss.str();
}

/* ajouter vue */
void GestionBdd::addVue(Vue* v) {
    vues.push_back(v);
}

/* maj vues */
void GestionBdd::update() {
    for(unsigned int i = 0;i < vues.size();i++)
        vues[i]->update();
}

void GestionBdd::setQuantite(int qte){
    quantite = qte;
}

int GestionBdd::getQuantite(){
    return quantite;
}

/* PARTIE UTILISATEURS */

/* connexion */
void GestionBdd::connecterUtilisateur(string pseudo, string mdp) {
    bool valide = utilisateurs.existeUtilisateur(pseudo, mdp);
    if(valide) {
        utilisateurConnecte = utilisateurs.getUtilisateur(pseudo);
        update();
    }
}

/* déconnexion */
void GestionBdd::deconnecterUtilisateur() {
    utilisateurConnecte = new Utilisateur();
}

/* savoir si on est connecté */
bool GestionBdd::isConnecte() {
    return utilisateurConnecte->getPseudo() != "" ? true : false;
}

/* retourner un pointeur vers l'utilisateur connecté */
Utilisateur* GestionBdd::getUtilisateurConnecte() {
    return utilisateurConnecte;
}

/* inscription */
void GestionBdd::inscrire(string monPseudo, string monMdp, string name, string firstname,
              int jourNaiss, int moisNaiss, int anneeNaiss, string mail, string adr, int codePostal)
{
    utilisateurs.add(new Utilisateur(monPseudo, monMdp, name, firstname,
                                     jourNaiss, moisNaiss, anneeNaiss, mail, adr, codePostal));
}

/* modifier le profil */
void GestionBdd::modifierProfil(string nom, string prenom, string mail,
                                int codePostal, string ville, string adresse) {
    string pseudo = utilisateurConnecte->getPseudo();
    utilisateurs.getUtilisateur(pseudo)->setNom(nom);
    utilisateurs.getUtilisateur(pseudo)->setPrenom(prenom);
    utilisateurs.getUtilisateur(pseudo)->setEmail(mail);
    utilisateurs.getUtilisateur(pseudo)->setCodePostal(codePostal);
    utilisateurs.getUtilisateur(pseudo)->setVille(ville);
    utilisateurs.getUtilisateur(pseudo)->setAdresse(adresse);
    update();
}

Produit* GestionBdd::getProduitCourant(){
    return produitCourant;
}

void GestionBdd::setProduitCourant(Produit *p){
    produitCourant = p;
}

void GestionBdd::acheterProduit(Produit* p, int quantite){
    // Ajout du produit dans la liste des achats
    utilisateurConnecte->addAchat(p, quantite);

    // Mise à jour de la liste des produits
    int qte = produits.getProduit(p->getReference())->getQuantite();
    if((qte-quantite) == 0){
        produits.supprimerProduit(p);
    } else {
        produits.getProduit(p->getReference())->setQuantite(qte-quantite);
    }
}

void GestionBdd::annulerAchat(Produit * p) {
    utilisateurConnecte->deleteAchat(p);
    // Mise à jour de la liste des produits
    int qte = produits.getProduit(p->getReference())->getQuantite();
    if(qte == 0) {
        produits.addProduit(p);
    }
    produits.getProduit(p->getReference())->setQuantite(qte+1);
}

void GestionBdd::annulerVente(Produit * p) {
    utilisateurConnecte->deleteVente(p);
    vector<Produit *> listeProduits = produits.getListProduits();
    // Mise à jour de la liste des produits
    vector<Produit*>::iterator it;
    for(it = listeProduits.begin();it != listeProduits.end();it++) {
        produits.supprimerProduit(*it);
    }
}

/* recherche utilisateurs */
vector<Utilisateur*> GestionBdd::rechercherUtilisateurs(string pseudo) {
    return utilisateurs.getUtilisateurs(pseudo);
}

/* recherche utilisateur */
Utilisateur* GestionBdd::rechercherUtilisateur(string pseudo) {
    return utilisateurs.getUtilisateur(pseudo);
}

/* PARTIE PRODUITS */

/* ajouter produit en vente */
void GestionBdd::ajouterVente(string n, string cat, float prix, unsigned int qte, bool etat) {
    string vendeur = utilisateurConnecte->getPseudo();
    Produit *p = new Produit(vendeur, n, cat, prix, qte, etat);
    //p->setReference(ref);
    //incrementerRef();
    p->setReference(generateReference());
    utilisateurConnecte->addVente(p);
    produits.addProduit(p);
    produits.triPrixCroissant();
    update();
}

void GestionBdd::ajouterVente(string n, string cat, float prix, unsigned int qte, bool etat, struct tm date) {
    string vendeur = utilisateurConnecte->getPseudo();
    Produit *p = new Produit(vendeur, n, cat, prix, qte, etat, date);
    //p->setReference(ref);
    //incrementerRef();
    p->setReference(generateReference());
    utilisateurConnecte->addVente(p);
    produits.addProduit(p);
    update();
}

/* ventes en cours */
vector<Produit*> GestionBdd::ventesEnCours() {
    return produits.getListProduits();
}

/* Rechercher un produit par référence */
Produit* GestionBdd::rechercherProduit(string ref) {
    return produits.getProduit(ref);
}

/* Rechercher les tags d'un produit */
vector<Produit*> GestionBdd::rechercherTags(string t){
    // Transformation des caractères du tag en minuscules
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    return produits.rechercherTags(t);
}
