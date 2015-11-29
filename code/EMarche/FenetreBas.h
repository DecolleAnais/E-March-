#ifndef FENETREBAS_H
#define FENETREBAS_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class FenetreBas : public QHBoxLayout
{

public:
    FenetreBas();

private:
    QPushButton *boutonPrecedent;
    QPushButton *boutonSuivant;
    QLabel *numPage;
};

#endif // FENETREBAS_H
