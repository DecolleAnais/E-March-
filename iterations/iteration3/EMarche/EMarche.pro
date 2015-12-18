QT       += widgets \
        core

SOURCES += \
    main.cpp \
    MaFenetre.cpp \
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
    bdd/GestionBdd.cpp \
    Vue.cpp \
    DialogAjouterVente.cpp \
    bdd/CoordsBancaires.cpp \
    DialogAcheter.cpp

HEADERS += \
    MaFenetre.h \
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
    bdd/GestionBdd.h \
    Vue.h \
    DialogAjouterVente.h \
    bdd/CoordsBancaires.h \
    DialogAcheter.h

FORMS += \
    DialogConnexion.ui \
    DialogAjouterVente.ui \
    DialogAcheter.ui
