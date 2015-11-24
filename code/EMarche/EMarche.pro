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
    EtatVente.cpp \
    EtatConnexion.cpp
    EtatVente.cpp \

HEADERS += \
    Produit.h \
    Categorie.h \
    VenteEnchere.h \
    Utilisateur.h \
    Avis.h \
    EtatDeconnecte.h \
    LesUtilisateurs.h \
    EtatVente.h \
    VenteNormale.h \
    EtatConnexion.h \
    EtatConnecte.h

FORMS +=
