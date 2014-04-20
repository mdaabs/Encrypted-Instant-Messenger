/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Sat Apr 19 21:14:53 2014
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
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *user;
    QLabel *label_2;
    QLineEdit *pass;
    QLabel *label_5;
    QLineEdit *ipaddress;
    QLabel *label_6;
    QLineEdit *port;
    QPushButton *settingsbutton;

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
        login_2->setGeometry(QRect(140, 210, 85, 27));
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(69, 80, 172, 116));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        user = new QLineEdit(layoutWidget);
        user->setObjectName(QString::fromUtf8("user"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pass);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        ipaddress = new QLineEdit(layoutWidget);
        ipaddress->setObjectName(QString::fromUtf8("ipaddress"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ipaddress);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));

        formLayout->setWidget(3, QFormLayout::FieldRole, port);

        settingsbutton = new QPushButton(login);
        settingsbutton->setObjectName(QString::fromUtf8("settingsbutton"));
        settingsbutton->setGeometry(QRect(10, 0, 85, 27));

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
        label->setText(QApplication::translate("login", "Username:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("login", "Password:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("login", "IP Address:", 0, QApplication::UnicodeUTF8));
        ipaddress->setText(QApplication::translate("login", "192.168.1.1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("login", "Port:", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("login", "22", 0, QApplication::UnicodeUTF8));
        settingsbutton->setText(QApplication::translate("login", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
