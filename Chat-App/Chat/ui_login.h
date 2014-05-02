/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Fri May 2 04:32:46 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *createnew;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *login_2;
    QPushButton *settingsbutton;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLineEdit *user;
    QLineEdit *pass;
    QLineEdit *ip;
    QLineEdit *port;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(400, 300);
        createnew = new QPushButton(login);
        createnew->setObjectName(QString::fromUtf8("createnew"));
        createnew->setGeometry(QRect(280, 70, 85, 27));
        label_3 = new QLabel(login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(289, 50, 61, 20));
        label_4 = new QLabel(login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 40, 61, 31));
        QFont font;
        font.setPointSize(19);
        label_4->setFont(font);
        login_2 = new QPushButton(login);
        login_2->setObjectName(QString::fromUtf8("login_2"));
        login_2->setGeometry(QRect(140, 200, 85, 27));
        settingsbutton = new QPushButton(login);
        settingsbutton->setObjectName(QString::fromUtf8("settingsbutton"));
        settingsbutton->setGeometry(QRect(10, 0, 85, 27));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 52, 16));
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 55, 16));
        label_5 = new QLabel(login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 101, 20));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(login);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 170, 24, 16));
        label_6->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 80, 120, 116));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        user = new QLineEdit(layoutWidget);
        user->setObjectName(QString::fromUtf8("user"));

        formLayout->setWidget(0, QFormLayout::LabelRole, user);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pass);

        ip = new QLineEdit(layoutWidget);
        ip->setObjectName(QString::fromUtf8("ip"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ip);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));

        formLayout->setWidget(3, QFormLayout::LabelRole, port);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0, QApplication::UnicodeUTF8));
        createnew->setText(QApplication::translate("login", "Create Account", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("login", "New User?", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("login", "Login", 0, QApplication::UnicodeUTF8));
        login_2->setText(QApplication::translate("login", "Login", 0, QApplication::UnicodeUTF8));
        settingsbutton->setText(QApplication::translate("login", "Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("login", "Password:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("login", "Username:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("login", "Server IP Address:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("login", "Port:", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("login", "10.0.2.15", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("login", "6543", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
