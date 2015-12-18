/********************************************************************************
** Form generated from reading UI file 'DialogInscription.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINSCRIPTION_H
#define UI_DIALOGINSCRIPTION_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogInscription
{
public:
    QLabel *labelPseudo;
    QLineEdit *valPseudo;
    QLabel *labelMdp;
    QLineEdit *valMdp;
    QLabel *labelMdp2;
    QLineEdit *valMdp2;
    QLabel *labelNom;
    QLineEdit *valNom;
    QLabel *labelPrenom;
    QLineEdit *valPrenom;
    QLabel *labelMail;
    QLineEdit *valMail;
    QLabel *labelMail2;
    QLineEdit *valMail2;
    QLabel *labelDateNaissance;
    QLabel *labelAdresse;
    QLineEdit *valAdresse;
    QLabel *labelCodePostal;
    QLineEdit *valCodePostal;
    QLabel *labelVille;
    QLineEdit *valVille;
    QLabel *labelInscription;
    QPushButton *boutonValider;
    QDateEdit *valDateNaissance;

    void setupUi(QDialog *DialogInscription)
    {
        if (DialogInscription->objectName().isEmpty())
            DialogInscription->setObjectName(QStringLiteral("DialogInscription"));
        DialogInscription->resize(710, 541);
        DialogInscription->setMinimumSize(QSize(710, 541));
        DialogInscription->setMaximumSize(QSize(710, 541));
        DialogInscription->setModal(true);
        labelPseudo = new QLabel(DialogInscription);
        labelPseudo->setObjectName(QStringLiteral("labelPseudo"));
        labelPseudo->setGeometry(QRect(88, 80, 221, 17));
        labelPseudo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valPseudo = new QLineEdit(DialogInscription);
        valPseudo->setObjectName(QStringLiteral("valPseudo"));
        valPseudo->setGeometry(QRect(310, 80, 146, 27));
        labelMdp = new QLabel(DialogInscription);
        labelMdp->setObjectName(QStringLiteral("labelMdp"));
        labelMdp->setGeometry(QRect(88, 113, 221, 17));
        labelMdp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valMdp = new QLineEdit(DialogInscription);
        valMdp->setObjectName(QStringLiteral("valMdp"));
        valMdp->setGeometry(QRect(310, 113, 146, 27));
        labelMdp2 = new QLabel(DialogInscription);
        labelMdp2->setObjectName(QStringLiteral("labelMdp2"));
        labelMdp2->setGeometry(QRect(88, 146, 216, 17));
        labelMdp2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valMdp2 = new QLineEdit(DialogInscription);
        valMdp2->setObjectName(QStringLiteral("valMdp2"));
        valMdp2->setGeometry(QRect(310, 146, 146, 27));
        labelNom = new QLabel(DialogInscription);
        labelNom->setObjectName(QStringLiteral("labelNom"));
        labelNom->setGeometry(QRect(88, 179, 211, 17));
        labelNom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valNom = new QLineEdit(DialogInscription);
        valNom->setObjectName(QStringLiteral("valNom"));
        valNom->setGeometry(QRect(310, 179, 146, 27));
        labelPrenom = new QLabel(DialogInscription);
        labelPrenom->setObjectName(QStringLiteral("labelPrenom"));
        labelPrenom->setGeometry(QRect(88, 212, 211, 17));
        labelPrenom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valPrenom = new QLineEdit(DialogInscription);
        valPrenom->setObjectName(QStringLiteral("valPrenom"));
        valPrenom->setGeometry(QRect(310, 212, 146, 27));
        labelMail = new QLabel(DialogInscription);
        labelMail->setObjectName(QStringLiteral("labelMail"));
        labelMail->setGeometry(QRect(88, 245, 211, 17));
        labelMail->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valMail = new QLineEdit(DialogInscription);
        valMail->setObjectName(QStringLiteral("valMail"));
        valMail->setGeometry(QRect(310, 245, 146, 27));
        labelMail2 = new QLabel(DialogInscription);
        labelMail2->setObjectName(QStringLiteral("labelMail2"));
        labelMail2->setGeometry(QRect(88, 278, 214, 17));
        labelMail2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valMail2 = new QLineEdit(DialogInscription);
        valMail2->setObjectName(QStringLiteral("valMail2"));
        valMail2->setGeometry(QRect(310, 278, 146, 27));
        labelDateNaissance = new QLabel(DialogInscription);
        labelDateNaissance->setObjectName(QStringLiteral("labelDateNaissance"));
        labelDateNaissance->setGeometry(QRect(88, 311, 211, 17));
        labelDateNaissance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelAdresse = new QLabel(DialogInscription);
        labelAdresse->setObjectName(QStringLiteral("labelAdresse"));
        labelAdresse->setGeometry(QRect(88, 344, 211, 17));
        labelAdresse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valAdresse = new QLineEdit(DialogInscription);
        valAdresse->setObjectName(QStringLiteral("valAdresse"));
        valAdresse->setGeometry(QRect(310, 344, 146, 27));
        labelCodePostal = new QLabel(DialogInscription);
        labelCodePostal->setObjectName(QStringLiteral("labelCodePostal"));
        labelCodePostal->setGeometry(QRect(88, 377, 211, 17));
        labelCodePostal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valCodePostal = new QLineEdit(DialogInscription);
        valCodePostal->setObjectName(QStringLiteral("valCodePostal"));
        valCodePostal->setGeometry(QRect(310, 377, 146, 27));
        labelVille = new QLabel(DialogInscription);
        labelVille->setObjectName(QStringLiteral("labelVille"));
        labelVille->setGeometry(QRect(88, 410, 211, 17));
        labelVille->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valVille = new QLineEdit(DialogInscription);
        valVille->setObjectName(QStringLiteral("valVille"));
        valVille->setGeometry(QRect(310, 410, 146, 27));
        labelInscription = new QLabel(DialogInscription);
        labelInscription->setObjectName(QStringLiteral("labelInscription"));
        labelInscription->setGeometry(QRect(330, 30, 101, 21));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelInscription->setFont(font);
        boutonValider = new QPushButton(DialogInscription);
        boutonValider->setObjectName(QStringLiteral("boutonValider"));
        boutonValider->setGeometry(QRect(330, 470, 99, 27));
        valDateNaissance = new QDateEdit(DialogInscription);
        valDateNaissance->setObjectName(QStringLiteral("valDateNaissance"));
        valDateNaissance->setGeometry(QRect(310, 310, 141, 27));
        valDateNaissance->setMaximumDate(QDate(2015, 12, 31));
        valDateNaissance->setMinimumDate(QDate(1900, 12, 1));
        valDateNaissance->setCalendarPopup(true);

        retranslateUi(DialogInscription);

        QMetaObject::connectSlotsByName(DialogInscription);
    } // setupUi

    void retranslateUi(QDialog *DialogInscription)
    {
        DialogInscription->setWindowTitle(QApplication::translate("DialogInscription", "Inscription", 0));
        labelPseudo->setText(QApplication::translate("DialogInscription", "Pseudo : ", 0));
        labelMdp->setText(QApplication::translate("DialogInscription", "Mot de passe : ", 0));
        labelMdp2->setText(QApplication::translate("DialogInscription", "Confirmation du mot de passe : ", 0));
        labelNom->setText(QApplication::translate("DialogInscription", "Nom :", 0));
        labelPrenom->setText(QApplication::translate("DialogInscription", "Pr\303\251nom :", 0));
        labelMail->setText(QApplication::translate("DialogInscription", "Adresse mail :", 0));
        labelMail2->setText(QApplication::translate("DialogInscription", "Confirmation de l'adresse mail :", 0));
        labelDateNaissance->setText(QApplication::translate("DialogInscription", "Date de naissance :", 0));
        labelAdresse->setText(QApplication::translate("DialogInscription", "Adresse :", 0));
        labelCodePostal->setText(QApplication::translate("DialogInscription", "Code postal :", 0));
        labelVille->setText(QApplication::translate("DialogInscription", "Ville :", 0));
        labelInscription->setText(QApplication::translate("DialogInscription", "Inscription", 0));
        boutonValider->setText(QApplication::translate("DialogInscription", "Valider", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogInscription: public Ui_DialogInscription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINSCRIPTION_H
