QT       += widgets \
        core

SOURCES += \
    main.cpp \
    MaFenetre.cpp \
    DialogConnexion.cpp \
    DialogModificationProfil.cpp \
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
    bdd/GestionBdd.cpp \
    Vue.cpp \
    DialogAjouterVente.cpp

HEADERS += \
    MaFenetre.h \
    DialogConnexion.h \
    DialogModificationProfil.h \
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
    bdd/GestionBdd.h \
    Vue.h \
    DialogAjouterVente.h

FORMS += \
    DialogConnexion.ui \
    DialogInscription.ui \
    DialogAjouterVente.ui \
    DialogModificationProfil.ui
