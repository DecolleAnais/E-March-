QT       += widgets \
        core

SOURCES += \
    main.cpp \
    maFenetre.cpp \
    FenetreBas.cpp \
    FenetreHaut.cpp \
    DialogConnexion.cpp \
    bdd/Avis.cpp \
    bdd/Categorie.cpp \
    bdd/EtatConnexion.cpp \
    bdd/EtatVente.cpp \
    bdd/LesProduits.cpp \
    bdd/LesUtilisateurs.cpp \
    bdd/Produit.cpp \
    bdd/Utilisateur.cpp \
    bdd/VenteEnchere.cpp \
    bdd/VenteNormale.cpp \
    DialogInscription.cpp \
    bdd/GestionBdd.cpp

HEADERS += \
    maFenetre.h \
    FenetreBas.h \
    FenetreHaut.h \
    DialogConnexion.h \
    bdd/Avis.h \
    bdd/Categorie.h \
    bdd/EtatConnecte.h \
    bdd/EtatConnexion.h \
    bdd/EtatDeconnecte.h \
    bdd/EtatVente.h \
    bdd/LesProduits.h \
    bdd/LesUtilisateurs.h \
    bdd/Produit.h \
    bdd/Utilisateur.h \
    bdd/VenteEnchere.h \
    bdd/VenteNormale.h \
    DialogInscription.h \
    bdd/GestionBdd.h

FORMS += \
    DialogConnexion.ui \
    DialogInscription.ui
