/********************************************************************************
** Form generated from reading UI file 'DialogAcheter.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGACHETER_H
#define UI_DIALOGACHETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogAcheter
{
public:
    QSpinBox *qte;
    QLabel *labelQte;
    QPushButton *acheter;

    void setupUi(QDialog *DialogAcheter)
    {
        if (DialogAcheter->objectName().isEmpty())
            DialogAcheter->setObjectName(QStringLiteral("DialogAcheter"));
        DialogAcheter->resize(296, 198);
        qte = new QSpinBox(DialogAcheter);
        qte->setObjectName(QStringLiteral("qte"));
        qte->setGeometry(QRect(150, 60, 71, 27));
        qte->setMinimum(1);
        labelQte = new QLabel(DialogAcheter);
        labelQte->setObjectName(QStringLiteral("labelQte"));
        labelQte->setGeometry(QRect(80, 60, 71, 21));
        acheter = new QPushButton(DialogAcheter);
        acheter->setObjectName(QStringLiteral("acheter"));
        acheter->setGeometry(QRect(100, 130, 85, 26));

        retranslateUi(DialogAcheter);

        QMetaObject::connectSlotsByName(DialogAcheter);
    } // setupUi

    void retranslateUi(QDialog *DialogAcheter)
    {
        DialogAcheter->setWindowTitle(QApplication::translate("DialogAcheter", "Dialog", 0));
        labelQte->setText(QApplication::translate("DialogAcheter", "Quantit\303\251 :", 0));
        acheter->setText(QApplication::translate("DialogAcheter", "Acheter", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAcheter: public Ui_DialogAcheter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGACHETER_H
