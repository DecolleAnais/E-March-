/********************************************************************************
** Form generated from reading UI file 'DialogModificationProfil.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODIFICATIONPROFIL_H
#define UI_DIALOGMODIFICATIONPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogModificationProfil
{
public:
    QPushButton *boutonValider;
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_3;
    QLineEdit *prenom;
    QLabel *label_4;
    QLineEdit *email;
    QLabel *label_5;
    QLineEdit *code_postal;
    QLabel *label_2;
    QLineEdit *ville;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *adresse;

    void setupUi(QDialog *DialogModificationProfil)
    {
        if (DialogModificationProfil->objectName().isEmpty())
            DialogModificationProfil->setObjectName(QStringLiteral("DialogModificationProfil"));
        DialogModificationProfil->resize(482, 358);
        boutonValider = new QPushButton(DialogModificationProfil);
        boutonValider->setObjectName(QStringLiteral("boutonValider"));
        boutonValider->setGeometry(QRect(200, 300, 99, 27));
        label = new QLabel(DialogModificationProfil);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 271, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        nom = new QLineEdit(DialogModificationProfil);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(230, 76, 126, 27));
        label_3 = new QLabel(DialogModificationProfil);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(127, 81, 121, 20));
        prenom = new QLineEdit(DialogModificationProfil);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(230, 111, 126, 27));
        label_4 = new QLabel(DialogModificationProfil);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(127, 116, 121, 20));
        email = new QLineEdit(DialogModificationProfil);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(230, 145, 126, 27));
        label_5 = new QLabel(DialogModificationProfil);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(127, 150, 121, 20));
        code_postal = new QLineEdit(DialogModificationProfil);
        code_postal->setObjectName(QStringLiteral("code_postal"));
        code_postal->setGeometry(QRect(230, 181, 126, 27));
        label_2 = new QLabel(DialogModificationProfil);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(127, 186, 121, 20));
        ville = new QLineEdit(DialogModificationProfil);
        ville->setObjectName(QStringLiteral("ville"));
        ville->setGeometry(QRect(230, 216, 126, 27));
        label_6 = new QLabel(DialogModificationProfil);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(127, 221, 121, 20));
        label_7 = new QLabel(DialogModificationProfil);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(127, 255, 121, 20));
        adresse = new QLineEdit(DialogModificationProfil);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(230, 250, 126, 27));

        retranslateUi(DialogModificationProfil);

        QMetaObject::connectSlotsByName(DialogModificationProfil);
    } // setupUi

    void retranslateUi(QDialog *DialogModificationProfil)
    {
        DialogModificationProfil->setWindowTitle(QApplication::translate("DialogModificationProfil", "Dialog", 0));
        boutonValider->setText(QApplication::translate("DialogModificationProfil", "Valider", 0));
        label->setText(QApplication::translate("DialogModificationProfil", "Changement profil", 0));
        label_3->setText(QApplication::translate("DialogModificationProfil", "Nom :", 0));
        label_4->setText(QApplication::translate("DialogModificationProfil", "Pr\303\251nom :", 0));
        label_5->setText(QApplication::translate("DialogModificationProfil", "Email :", 0));
        code_postal->setText(QString());
        label_2->setText(QApplication::translate("DialogModificationProfil", "Code postal :", 0));
        label_6->setText(QApplication::translate("DialogModificationProfil", "Ville :", 0));
        label_7->setText(QApplication::translate("DialogModificationProfil", "Adresse :", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogModificationProfil: public Ui_DialogModificationProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODIFICATIONPROFIL_H
