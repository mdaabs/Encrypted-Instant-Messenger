/********************************************************************************
** Form generated from reading UI file 'convoTab.ui'
**
** Created: Fri May 2 00:40:07 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVOTAB_H
#define UI_CONVOTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_convoTab
{
public:
    QTextEdit *tabmessage;
    QFontComboBox *fontComboBox;
    QListWidget *tabconvo;
    QPushButton *tabsendbutton;

    void setupUi(QWidget *convoTab)
    {
        if (convoTab->objectName().isEmpty())
            convoTab->setObjectName(QString::fromUtf8("convoTab"));
        convoTab->resize(345, 455);
        convoTab->setStyleSheet(QString::fromUtf8(""));
        tabmessage = new QTextEdit(convoTab);
        tabmessage->setObjectName(QString::fromUtf8("tabmessage"));
        tabmessage->setGeometry(QRect(10, 280, 321, 111));
        tabmessage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        fontComboBox = new QFontComboBox(convoTab);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(60, 230, 191, 24));
        fontComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tabconvo = new QListWidget(convoTab);
        tabconvo->setObjectName(QString::fromUtf8("tabconvo"));
        tabconvo->setGeometry(QRect(10, 10, 321, 201));
        tabconvo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        tabsendbutton = new QPushButton(convoTab);
        tabsendbutton->setObjectName(QString::fromUtf8("tabsendbutton"));
        tabsendbutton->setGeometry(QRect(230, 400, 85, 27));
        tabsendbutton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(convoTab);

        QMetaObject::connectSlotsByName(convoTab);
    } // setupUi

    void retranslateUi(QWidget *convoTab)
    {
        convoTab->setWindowTitle(QApplication::translate("convoTab", "Form", 0, QApplication::UnicodeUTF8));
        tabsendbutton->setText(QApplication::translate("convoTab", "Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class convoTab: public Ui_convoTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVOTAB_H
