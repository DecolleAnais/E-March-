/********************************************************************************
** Form generated from reading UI file 'DialogAjouterVente.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERVENTE_H
#define UI_DIALOGAJOUTERVENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogAjouterVente
{
public:
    QLabel *label;
    QLabel *labelNom;
    QLineEdit *valNom;
    QLabel *labelCat;
    QLineEdit *valCat;
    QLabel *labelPrix;
    QLabel *labelQte;
    QSpinBox *valQte;
    QLabel *label_6;
    QLabel *labelDateLimite;
    QRadioButton *radioEnchere;
    QDateEdit *valDateLimite;
    QPushButton *boutonAjouterVente;
    QRadioButton *radioNormale;
    QDoubleSpinBox *valPrix;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogAjouterVente)
    {
        if (DialogAjouterVente->objectName().isEmpty())
            DialogAjouterVente->setObjectName(QStringLiteral("DialogAjouterVente"));
        DialogAjouterVente->resize(689, 450);
        DialogAjouterVente->setMinimumSize(QSize(689, 450));
        DialogAjouterVente->setMaximumSize(QSize(689, 450));
        label = new QLabel(DialogAjouterVente);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 20, 199, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        labelNom = new QLabel(DialogAjouterVente);
        labelNom->setObjectName(QStringLiteral("labelNom"));
        labelNom->setGeometry(QRect(115, 122, 201, 17));
        labelNom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valNom = new QLineEdit(DialogAjouterVente);
        valNom->setObjectName(QStringLiteral("valNom"));
        valNom->setGeometry(QRect(320, 122, 146, 27));
        labelCat = new QLabel(DialogAjouterVente);
        labelCat->setObjectName(QStringLiteral("labelCat"));
        labelCat->setGeometry(QRect(116, 156, 201, 17));
        labelCat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valCat = new QLineEdit(DialogAjouterVente);
        valCat->setObjectName(QStringLiteral("valCat"));
        valCat->setGeometry(QRect(320, 155, 146, 27));
        labelPrix = new QLabel(DialogAjouterVente);
        labelPrix->setObjectName(QStringLiteral("labelPrix"));
        labelPrix->setGeometry(QRect(116, 196, 201, 17));
        labelPrix->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelQte = new QLabel(DialogAjouterVente);
        labelQte->setObjectName(QStringLiteral("labelQte"));
        labelQte->setGeometry(QRect(116, 226, 201, 17));
        labelQte->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valQte = new QSpinBox(DialogAjouterVente);
        valQte->setObjectName(QStringLiteral("valQte"));
        valQte->setGeometry(QRect(320, 221, 81, 27));
        valQte->setMinimum(1);
        valQte->setMaximum(999);
        label_6 = new QLabel(DialogAjouterVente);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(9, 237, 16, 17));
        labelDateLimite = new QLabel(DialogAjouterVente);
        labelDateLimite->setObjectName(QStringLiteral("labelDateLimite"));
        labelDateLimite->setEnabled(false);
        labelDateLimite->setGeometry(QRect(116, 266, 201, 17));
        labelDateLimite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radioEnchere = new QRadioButton(DialogAjouterVente);
        buttonGroup = new QButtonGroup(DialogAjouterVente);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioEnchere);
        radioEnchere->setObjectName(QStringLiteral("radioEnchere"));
        radioEnchere->setGeometry(QRect(375, 70, 164, 22));
        valDateLimite = new QDateEdit(DialogAjouterVente);
        valDateLimite->setObjectName(QStringLiteral("valDateLimite"));
        valDateLimite->setEnabled(false);
        valDateLimite->setGeometry(QRect(320, 260, 111, 27));
        valDateLimite->setDateTime(QDateTime(QDate(2015, 12, 25), QTime(0, 0, 0)));
        valDateLimite->setMinimumDateTime(QDateTime(QDate(2015, 12, 1), QTime(0, 0, 0)));
        boutonAjouterVente = new QPushButton(DialogAjouterVente);
        boutonAjouterVente->setObjectName(QStringLiteral("boutonAjouterVente"));
        boutonAjouterVente->setGeometry(QRect(280, 350, 141, 27));
        radioNormale = new QRadioButton(DialogAjouterVente);
        buttonGroup->addButton(radioNormale);
        radioNormale->setObjectName(QStringLiteral("radioNormale"));
        radioNormale->setGeometry(QRect(190, 70, 164, 22));
        radioNormale->setAutoFillBackground(false);
        radioNormale->setChecked(true);
        valPrix = new QDoubleSpinBox(DialogAjouterVente);
        valPrix->setObjectName(QStringLiteral("valPrix"));
        valPrix->setGeometry(QRect(320, 190, 81, 27));
        valPrix->setMinimum(1);
        valPrix->setMaximum(10000);

        retranslateUi(DialogAjouterVente);
        QObject::connect(radioEnchere, SIGNAL(toggled(bool)), labelDateLimite, SLOT(setEnabled(bool)));
        QObject::connect(radioEnchere, SIGNAL(toggled(bool)), valDateLimite, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(DialogAjouterVente);
    } // setupUi

    void retranslateUi(QDialog *DialogAjouterVente)
    {
        DialogAjouterVente->setWindowTitle(QApplication::translate("DialogAjouterVente", "Dialog", 0));
        label->setText(QApplication::translate("DialogAjouterVente", "Ajouter un produit en vente", 0));
        labelNom->setText(QApplication::translate("DialogAjouterVente", "Nom :", 0));
        labelCat->setText(QApplication::translate("DialogAjouterVente", "Cat\303\251gorie :", 0));
        labelPrix->setText(QApplication::translate("DialogAjouterVente", "Prix Unitaire/Prix de d\303\251part :", 0));
        labelQte->setText(QApplication::translate("DialogAjouterVente", "Quantit\303\251 :", 0));
        label_6->setText(QString());
        labelDateLimite->setText(QApplication::translate("DialogAjouterVente", "Date limite si ench\303\250re :", 0));
        radioEnchere->setText(QApplication::translate("DialogAjouterVente", "Vente aux ench\303\250res", 0));
        boutonAjouterVente->setText(QApplication::translate("DialogAjouterVente", "Mettre en vente", 0));
        radioNormale->setText(QApplication::translate("DialogAjouterVente", "Vente normale", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAjouterVente: public Ui_DialogAjouterVente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERVENTE_H
