/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *addressLiEdit;
    QLabel *label_2;
    QLineEdit *portLiEdit;
    QPushButton *connRedisBtn;
    QTextEdit *textEdit;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(570, 454);
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        addressLiEdit = new QLineEdit(MainWidget);
        addressLiEdit->setObjectName(QString::fromUtf8("addressLiEdit"));

        gridLayout->addWidget(addressLiEdit, 0, 1, 1, 1);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        portLiEdit = new QLineEdit(MainWidget);
        portLiEdit->setObjectName(QString::fromUtf8("portLiEdit"));

        gridLayout->addWidget(portLiEdit, 0, 3, 1, 1);

        connRedisBtn = new QPushButton(MainWidget);
        connRedisBtn->setObjectName(QString::fromUtf8("connRedisBtn"));

        gridLayout->addWidget(connRedisBtn, 0, 4, 1, 1);

        textEdit = new QTextEdit(MainWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 5);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\347\253\257\345\217\243\357\274\232", nullptr));
        connRedisBtn->setText(QCoreApplication::translate("MainWidget", "Conn_Redis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
