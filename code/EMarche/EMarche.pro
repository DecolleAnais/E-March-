#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T16:32:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = EMarche
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Produit.cpp \
    Categorie.cpp \
    VenteEnchere.cpp \
<<<<<<< HEAD
    Utilisateur.cpp \
    Avis.cpp
=======
    EtatVente.cpp \
    EtatConnexion.cpp
>>>>>>> 6e4c0d939eaa5a3763afc3f66464d1c038f5db69

HEADERS += \
    Produit.h \
    Categorie.h \
    VenteEnchere.h \
<<<<<<< HEAD
    Utilisateur.h \
    Avis.h
=======
    EtatVente.h \
    VenteNormale.h \
    EtatConnexion.h \
    EtatConnecte.h \
    EtatDeconnecte.h
>>>>>>> 6e4c0d939eaa5a3763afc3f66464d1c038f5db69
