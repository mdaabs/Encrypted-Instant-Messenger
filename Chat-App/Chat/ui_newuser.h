/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created: Fri May 2 00:40:07 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

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
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newuser
{
public:
    QLabel *label_5;
    QStackedWidget *messagebox;
    QWidget *messageboxPage1;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLineEdit *newusername;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *pass;
    QLineEdit *pass2;

    void setupUi(QDialog *newuser)
    {
        if (newuser->objectName().isEmpty())
            newuser->setObjectName(QString::fromUtf8("newuser"));
        newuser->resize(400, 300);
        label_5 = new QLabel(newuser);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 0, 131, 41));
        QFont font;
        font.setPointSize(17);
        label_5->setFont(font);
        messagebox = new QStackedWidget(newuser);
        messagebox->setObjectName(QString::fromUtf8("messagebox"));
        messagebox->setGeometry(QRect(230, 70, 151, 80));
        QFont font1;
        font1.setPointSize(8);
        messagebox->setFont(font1);
        messageboxPage1 = new QWidget();
        messageboxPage1->setObjectName(QString::fromUtf8("messageboxPage1"));
        messagebox->addWidget(messageboxPage1);
        layoutWidget = new QWidget(newuser);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 180, 197, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancel = new QPushButton(layoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add = new QPushButton(layoutWidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout->addWidget(add);

        layoutWidget1 = new QWidget(newuser);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(23, 50, 191, 121));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        newusername = new QLineEdit(layoutWidget1);
        newusername->setObjectName(QString::fromUtf8("newusername"));

        verticalLayout->addWidget(newusername);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        pass = new QLineEdit(layoutWidget1);
        pass->setObjectName(QString::fromUtf8("pass"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pass);

        pass2 = new QLineEdit(layoutWidget1);
        pass2->setObjectName(QString::fromUtf8("pass2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pass2);


        retranslateUi(newuser);

        QMetaObject::connectSlotsByName(newuser);
    } // setupUi

    void retranslateUi(QDialog *newuser)
    {
        newuser->setWindowTitle(QApplication::translate("newuser", "Dialog", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("newuser", "Welcome!", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("newuser", "Cancel", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("newuser", "Ok", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("newuser", "New User", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newuser", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("newuser", "Password", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("newuser", "Confirm Password", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newuser: public Ui_newuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
