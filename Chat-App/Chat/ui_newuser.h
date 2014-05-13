/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created: Tue May 13 03:48:00 2014
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newuser
{
public:
    QLabel *label_5;
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
    QWidget *widget;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *newuserip;
    QLabel *label_7;
    QLineEdit *newuserport;

    void setupUi(QDialog *newuser)
    {
        if (newuser->objectName().isEmpty())
            newuser->setObjectName(QString::fromUtf8("newuser"));
        newuser->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newuser->sizePolicy().hasHeightForWidth());
        newuser->setSizePolicy(sizePolicy);
        label_5 = new QLabel(newuser);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 0, 131, 41));
        QFont font;
        font.setPointSize(17);
        label_5->setFont(font);
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        newusername = new QLineEdit(layoutWidget1);
        newusername->setObjectName(QString::fromUtf8("newusername"));

        verticalLayout->addWidget(newusername);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        pass = new QLineEdit(layoutWidget1);
        pass->setObjectName(QString::fromUtf8("pass"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pass);

        pass2 = new QLineEdit(layoutWidget1);
        pass2->setObjectName(QString::fromUtf8("pass2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pass2);

        widget = new QWidget(newuser);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(240, 80, 144, 56));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        newuserip = new QLineEdit(widget);
        newuserip->setObjectName(QString::fromUtf8("newuserip"));
        sizePolicy.setHeightForWidth(newuserip->sizePolicy().hasHeightForWidth());
        newuserip->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, newuserip);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        newuserport = new QLineEdit(widget);
        newuserport->setObjectName(QString::fromUtf8("newuserport"));
        sizePolicy.setHeightForWidth(newuserport->sizePolicy().hasHeightForWidth());
        newuserport->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, newuserport);


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
        label_6->setText(QApplication::translate("newuser", "IP", 0, QApplication::UnicodeUTF8));
        newuserip->setText(QApplication::translate("newuser", "192.168.0.1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("newuser", "Port", 0, QApplication::UnicodeUTF8));
        newuserport->setText(QApplication::translate("newuser", "6543", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newuser: public Ui_newuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
