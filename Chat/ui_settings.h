/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Sat Apr 19 21:14:53 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QLabel *label_3;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *ip;
    QLabel *label_2;
    QLineEdit *port;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel;
    QPushButton *save;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(239, 264);
        label_3 = new QLabel(settings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 20, 141, 41));
        QFont font;
        font.setPointSize(28);
        label_3->setFont(font);
        layoutWidget = new QWidget(settings);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(29, 80, 174, 56));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ip = new QLineEdit(layoutWidget);
        ip->setObjectName(QString::fromUtf8("ip"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ip);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port);

        layoutWidget1 = new QWidget(settings);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 180, 178, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancel = new QPushButton(layoutWidget1);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout->addWidget(cancel);

        save = new QPushButton(layoutWidget1);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout->addWidget(save);


        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("settings", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settings", "IP Address", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("settings", "192.168.1.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settings", "Port", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("settings", "22", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("settings", "Cancel", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("settings", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
