/********************************************************************************
** Form generated from reading UI file 'rectest.ui'
**
** Created: Tue May 13 03:48:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTEST_H
#define UI_RECTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_rectest
{
public:
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *rectest)
    {
        if (rectest->objectName().isEmpty())
            rectest->setObjectName(QString::fromUtf8("rectest"));
        rectest->resize(485, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rectest->sizePolicy().hasHeightForWidth());
        rectest->setSizePolicy(sizePolicy);
        listWidget = new QListWidget(rectest);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 80, 181, 192));
        listWidget_2 = new QListWidget(rectest);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(250, 80, 201, 192));
        label = new QLabel(rectest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 0, 331, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(rectest);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 231, 16));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(rectest);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 60, 151, 20));
        label_3->setFont(font1);

        retranslateUi(rectest);

        QMetaObject::connectSlotsByName(rectest);
    } // setupUi

    void retranslateUi(QDialog *rectest)
    {
        rectest->setWindowTitle(QApplication::translate("rectest", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rectest", "Tracking the process of Encryption", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("rectest", "Encrypted and sent to server:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("rectest", "After Decryption:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rectest: public Ui_rectest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTEST_H
