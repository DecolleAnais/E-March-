#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T16:32:47
#
#-------------------------------------------------

QT       += core \
    widgets

QT       -= gui

TARGET = EMarche
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Produit.cpp \
    Categorie.cpp \
    VenteEnchere.cpp \
    Utilisateur.cpp \
    Avis.cpp \
    LesUtilisateurs.cpp \
    EtatConnexion.cpp \
    EtatVente.cpp \
    LesProduits.cpp \
    VenteNormale.cpp

HEADERS += \
    Produit.h \
    Categorie.h \
    VenteEnchere.h \
    Utilisateur.h \
    Avis.h \
    EtatDeconnecte.h \
    LesUtilisateurs.h \
    EtatConnecte.h \
    EtatConnexion.h \
    EtatVente.h \
    VenteNormale.h \
    LesProduits.h

FORMS +=
