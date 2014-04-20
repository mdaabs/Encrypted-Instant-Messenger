/********************************************************************************
** Form generated from reading UI file 'tabdialog.ui'
**
** Created: Wed Apr 16 16:40:45 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABDIALOG_H
#define UI_TABDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabDialog
{
public:
    QWidget *widget;

    void setupUi(QDialog *TabDialog)
    {
        if (TabDialog->objectName().isEmpty())
            TabDialog->setObjectName(QString::fromUtf8("TabDialog"));
        TabDialog->resize(400, 300);
        widget = new QWidget(TabDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 331, 251));
        widget->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(TabDialog);

        QMetaObject::connectSlotsByName(TabDialog);
    } // setupUi

    void retranslateUi(QDialog *TabDialog)
    {
        TabDialog->setWindowTitle(QApplication::translate("TabDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabDialog: public Ui_TabDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABDIALOG_H
