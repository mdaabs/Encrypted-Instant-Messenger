/********************************************************************************
** Form generated from reading UI file 'addnewfriend.ui'
**
** Created: Tue May 13 03:48:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWFRIEND_H
#define UI_ADDNEWFRIEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addnewfriend
{
public:
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *friend_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancel;
    QPushButton *add;

    void setupUi(QDialog *addnewfriend)
    {
        if (addnewfriend->objectName().isEmpty())
            addnewfriend->setObjectName(QString::fromUtf8("addnewfriend"));
        addnewfriend->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addnewfriend->sizePolicy().hasHeightForWidth());
        addnewfriend->setSizePolicy(sizePolicy);
        label_2 = new QLabel(addnewfriend);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 20, 281, 51));
        QFont font;
        font.setPointSize(30);
        label_2->setFont(font);
        layoutWidget = new QWidget(addnewfriend);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(64, 91, 214, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        friend_2 = new QLineEdit(layoutWidget);
        friend_2->setObjectName(QString::fromUtf8("friend_2"));

        horizontalLayout->addWidget(friend_2);

        layoutWidget1 = new QWidget(addnewfriend);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 190, 178, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cancel = new QPushButton(layoutWidget1);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_2->addWidget(cancel);

        add = new QPushButton(layoutWidget1);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);


        retranslateUi(addnewfriend);

        QMetaObject::connectSlotsByName(addnewfriend);
    } // setupUi

    void retranslateUi(QDialog *addnewfriend)
    {
        addnewfriend->setWindowTitle(QApplication::translate("addnewfriend", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addnewfriend", "Add a New Friend", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addnewfriend", "Friend's Username:", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("addnewfriend", "Cancel", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("addnewfriend", "ADD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addnewfriend: public Ui_addnewfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWFRIEND_H
