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
    EtatVente.cpp \
    EtatConnexion.cpp

HEADERS += \
    Produit.h \
    Categorie.h \
    VenteEnchere.h \
    EtatVente.h \
    VenteNormale.h \
    EtatConnexion.h \
    EtatConnecte.h \
    EtatDeconnecte.h
