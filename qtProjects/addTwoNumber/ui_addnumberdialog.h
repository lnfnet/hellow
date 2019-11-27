/********************************************************************************
** Form generated from reading UI file 'addnumberdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNUMBERDIALOG_H
#define UI_ADDNUMBERDIALOG_H

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

class Ui_AddNumberDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *countBtn;
    QLineEdit *lineEditRadios;
    QLineEdit *lineEditArea;

    void setupUi(QDialog *AddNumberDialog)
    {
        if (AddNumberDialog->objectName().isEmpty())
            AddNumberDialog->setObjectName(QStringLiteral("AddNumberDialog"));
        AddNumberDialog->resize(861, 300);
        label = new QLabel(AddNumberDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 100, 54, 12));
        label_2 = new QLabel(AddNumberDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 100, 54, 12));
        countBtn = new QPushButton(AddNumberDialog);
        countBtn->setObjectName(QStringLiteral("countBtn"));
        countBtn->setGeometry(QRect(570, 220, 75, 23));
        lineEditRadios = new QLineEdit(AddNumberDialog);
        lineEditRadios->setObjectName(QStringLiteral("lineEditRadios"));
        lineEditRadios->setGeometry(QRect(140, 90, 113, 20));
        lineEditArea = new QLineEdit(AddNumberDialog);
        lineEditArea->setObjectName(QStringLiteral("lineEditArea"));
        lineEditArea->setGeometry(QRect(520, 90, 113, 20));

        retranslateUi(AddNumberDialog);

        QMetaObject::connectSlotsByName(AddNumberDialog);
    } // setupUi

    void retranslateUi(QDialog *AddNumberDialog)
    {
        AddNumberDialog->setWindowTitle(QApplication::translate("AddNumberDialog", "AddNumberDialog", 0));
        label->setText(QApplication::translate("AddNumberDialog", "\345\215\212\345\276\204\357\274\232", 0));
        label_2->setText(QApplication::translate("AddNumberDialog", "\351\235\242\347\247\257\357\274\232", 0));
        countBtn->setText(QApplication::translate("AddNumberDialog", "\350\256\241\347\256\227", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNumberDialog: public Ui_AddNumberDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNUMBERDIALOG_H
