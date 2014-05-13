/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created: Tue May 13 03:48:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

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

class Ui_changepassword
{
public:
    QPushButton *submit;
    QPushButton *cancel;
    QLabel *label_5;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *oldpass;
    QLabel *label_3;
    QLineEdit *newpass;
    QLabel *label_4;
    QLineEdit *newpass2;
    QWidget *widget1;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *changepasswordip;
    QLabel *label_7;
    QLineEdit *changepasswordport;

    void setupUi(QDialog *changepassword)
    {
        if (changepassword->objectName().isEmpty())
            changepassword->setObjectName(QString::fromUtf8("changepassword"));
        changepassword->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(changepassword->sizePolicy().hasHeightForWidth());
        changepassword->setSizePolicy(sizePolicy);
        submit = new QPushButton(changepassword);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(150, 220, 85, 27));
        cancel = new QPushButton(changepassword);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(30, 220, 85, 27));
        label_5 = new QLabel(changepassword);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 20, 171, 51));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label_5->setFont(font);
        widget = new QWidget(changepassword);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 80, 212, 116));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        username = new QLineEdit(widget);
        username->setObjectName(QString::fromUtf8("username"));
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, username);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        oldpass = new QLineEdit(widget);
        oldpass->setObjectName(QString::fromUtf8("oldpass"));
        sizePolicy.setHeightForWidth(oldpass->sizePolicy().hasHeightForWidth());
        oldpass->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, oldpass);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        newpass = new QLineEdit(widget);
        newpass->setObjectName(QString::fromUtf8("newpass"));
        sizePolicy.setHeightForWidth(newpass->sizePolicy().hasHeightForWidth());
        newpass->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, newpass);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        newpass2 = new QLineEdit(widget);
        newpass2->setObjectName(QString::fromUtf8("newpass2"));
        sizePolicy.setHeightForWidth(newpass2->sizePolicy().hasHeightForWidth());
        newpass2->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, newpass2);

        widget1 = new QWidget(changepassword);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(250, 100, 144, 56));
        formLayout_2 = new QFormLayout(widget1);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        changepasswordip = new QLineEdit(widget1);
        changepasswordip->setObjectName(QString::fromUtf8("changepasswordip"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, changepasswordip);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        changepasswordport = new QLineEdit(widget1);
        changepasswordport->setObjectName(QString::fromUtf8("changepasswordport"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, changepasswordport);


        retranslateUi(changepassword);

        QMetaObject::connectSlotsByName(changepassword);
    } // setupUi

    void retranslateUi(QDialog *changepassword)
    {
        changepassword->setWindowTitle(QApplication::translate("changepassword", "Dialog", 0, QApplication::UnicodeUTF8));
        submit->setText(QApplication::translate("changepassword", "Submit", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("changepassword", "Cancel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("changepassword", "Change Password", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("changepassword", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("changepassword", "Old Password", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("changepassword", "New Password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("changepassword", "Confirm Password", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("changepassword", "IP", 0, QApplication::UnicodeUTF8));
        changepasswordip->setText(QApplication::translate("changepassword", "192.168.0.110", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("changepassword", "Port", 0, QApplication::UnicodeUTF8));
        changepasswordport->setText(QApplication::translate("changepassword", "6543", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class changepassword: public Ui_changepassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
