/********************************************************************************
** Form generated from reading UI file 'DialogConnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConnexion
{
public:
    QLabel *labelConnexion;
    QPushButton *boutonSeConnecter;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *labelPseudo;
    QLineEdit *valPseudo;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *labelMdp;
    QLineEdit *valMdp;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QStringLiteral("DialogConnexion"));
        DialogConnexion->setWindowModality(Qt::NonModal);
        DialogConnexion->resize(486, 217);
        DialogConnexion->setMaximumSize(QSize(550, 250));
        DialogConnexion->setModal(true);
        labelConnexion = new QLabel(DialogConnexion);
        labelConnexion->setObjectName(QStringLiteral("labelConnexion"));
        labelConnexion->setGeometry(QRect(230, 10, 76, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelConnexion->setFont(font);
        labelConnexion->setAlignment(Qt::AlignCenter);
        boutonSeConnecter = new QPushButton(DialogConnexion);
        boutonSeConnecter->setObjectName(QStringLiteral("boutonSeConnecter"));
        boutonSeConnecter->setGeometry(QRect(220, 140, 107, 27));
        boutonSeConnecter->setAutoDefault(true);
        layoutWidget = new QWidget(DialogConnexion);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 40, 326, 31));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelPseudo = new QLabel(layoutWidget);
        labelPseudo->setObjectName(QStringLiteral("labelPseudo"));
        labelPseudo->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPseudo);

        valPseudo = new QLineEdit(layoutWidget);
        valPseudo->setObjectName(QStringLiteral("valPseudo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, valPseudo);

        layoutWidget1 = new QWidget(DialogConnexion);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 90, 362, 31));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        labelMdp = new QLabel(layoutWidget1);
        labelMdp->setObjectName(QStringLiteral("labelMdp"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelMdp);

        valMdp = new QLineEdit(layoutWidget1);
        valMdp->setObjectName(QStringLiteral("valMdp"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, valMdp);


        retranslateUi(DialogConnexion);

        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QApplication::translate("DialogConnexion", "Connexion", 0));
        labelConnexion->setText(QApplication::translate("DialogConnexion", "Connexion", 0));
        boutonSeConnecter->setText(QApplication::translate("DialogConnexion", "Se connecter", 0));
        labelPseudo->setText(QApplication::translate("DialogConnexion", "Pseudo : ", 0));
        labelMdp->setText(QApplication::translate("DialogConnexion", "Mot de passe :", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
