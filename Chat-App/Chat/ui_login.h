/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Tue May 13 03:48:00 2014
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *login_2;
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *settingsbutton;
    QSpacerItem *horizontalSpacer;
    QPushButton *changepass;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *createnew;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(368, 276);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 40, 61, 20));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_4 = new QLabel(login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 40, 61, 31));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(19);
        label_4->setFont(font);
        login_2 = new QPushButton(login);
        login_2->setObjectName(QString::fromUtf8("login_2"));
        login_2->setGeometry(QRect(140, 200, 85, 27));
        sizePolicy.setHeightForWidth(login_2->sizePolicy().hasHeightForWidth());
        login_2->setSizePolicy(sizePolicy);
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 52, 16));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 55, 16));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label_5 = new QLabel(login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 101, 20));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(login);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 170, 24, 16));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 80, 120, 116));
        sizePolicy.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        user = new QLineEdit(layoutWidget);
        user->setObjectName(QString::fromUtf8("user"));
        sizePolicy.setHeightForWidth(user->sizePolicy().hasHeightForWidth());
        user->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, user);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        sizePolicy.setHeightForWidth(pass->sizePolicy().hasHeightForWidth());
        pass->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, pass);

        ip = new QLineEdit(layoutWidget);
        ip->setObjectName(QString::fromUtf8("ip"));
        sizePolicy.setHeightForWidth(ip->sizePolicy().hasHeightForWidth());
        ip->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, ip);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));
        sizePolicy.setHeightForWidth(port->sizePolicy().hasHeightForWidth());
        port->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, port);

        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 353, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        settingsbutton = new QPushButton(widget);
        settingsbutton->setObjectName(QString::fromUtf8("settingsbutton"));
        sizePolicy.setHeightForWidth(settingsbutton->sizePolicy().hasHeightForWidth());
        settingsbutton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(settingsbutton);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        changepass = new QPushButton(widget);
        changepass->setObjectName(QString::fromUtf8("changepass"));

        horizontalLayout->addWidget(changepass);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        createnew = new QPushButton(widget);
        createnew->setObjectName(QString::fromUtf8("createnew"));
        sizePolicy.setHeightForWidth(createnew->sizePolicy().hasHeightForWidth());
        createnew->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(createnew);

        createnew->raise();
        label_3->raise();
        label_4->raise();
        settingsbutton->raise();
        label_2->raise();
        label->raise();
        label_5->raise();
        label_6->raise();
        layoutWidget->raise();
        login_2->raise();
        changepass->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("login", "New User?", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("login", "Login", 0, QApplication::UnicodeUTF8));
        login_2->setText(QApplication::translate("login", "Login", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("login", "Password:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("login", "Username:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("login", "Server IP Address:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("login", "Port:", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("login", "192.168.0.101", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("login", "6543", 0, QApplication::UnicodeUTF8));
        settingsbutton->setText(QApplication::translate("login", "Settings", 0, QApplication::UnicodeUTF8));
        changepass->setText(QApplication::translate("login", "Change Password", 0, QApplication::UnicodeUTF8));
        createnew->setText(QApplication::translate("login", "Create Account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
