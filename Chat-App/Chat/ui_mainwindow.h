/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 2 00:40:07 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listoffriends;
    QLabel *friends;
    QLabel *label;
    QLabel *label_2;
    QListWidget *offlinelist;
    QWidget *convowidget;
    QPushButton *pushButton;
    QPushButton *logoffbutton;
    QPushButton *helpbutton;
    QLabel *thisusr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(497, 668);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listoffriends = new QListWidget(centralwidget);
        listoffriends->setObjectName(QString::fromUtf8("listoffriends"));
        listoffriends->setGeometry(QRect(10, 71, 101, 221));
        listoffriends->setLayoutDirection(Qt::LeftToRight);
        listoffriends->setMovement(QListView::Free);
        listoffriends->setFlow(QListView::TopToBottom);
        listoffriends->setResizeMode(QListView::Adjust);
        listoffriends->setLayoutMode(QListView::Batched);
        listoffriends->setSpacing(1);
        listoffriends->setModelColumn(0);
        friends = new QLabel(centralwidget);
        friends->setObjectName(QString::fromUtf8("friends"));
        friends->setGeometry(QRect(30, 30, 55, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 50, 14));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 310, 50, 21));
        offlinelist = new QListWidget(centralwidget);
        offlinelist->setObjectName(QString::fromUtf8("offlinelist"));
        offlinelist->setGeometry(QRect(10, 330, 101, 131));
        offlinelist->setMidLineWidth(1);
        convowidget = new QWidget(centralwidget);
        convowidget->setObjectName(QString::fromUtf8("convowidget"));
        convowidget->setGeometry(QRect(120, 60, 361, 521));
        convowidget->setAutoFillBackground(false);
        convowidget->setStyleSheet(QString::fromUtf8("border-color: rgb(45, 45, 45);\n"
"\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(21, 1, 85, 27));
        logoffbutton = new QPushButton(centralwidget);
        logoffbutton->setObjectName(QString::fromUtf8("logoffbutton"));
        logoffbutton->setGeometry(QRect(434, 0, 51, 27));
        helpbutton = new QPushButton(centralwidget);
        helpbutton->setObjectName(QString::fromUtf8("helpbutton"));
        helpbutton->setGeometry(QRect(110, 0, 85, 27));
        thisusr = new QLabel(centralwidget);
        thisusr->setObjectName(QString::fromUtf8("thisusr"));
        thisusr->setGeometry(QRect(350, 0, 81, 21));
        thisusr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 497, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(listoffriends, offlinelist);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        friends->setText(QApplication::translate("MainWindow", "Friend List", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Online", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Offline", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "+ Add Friend", 0, QApplication::UnicodeUTF8));
        logoffbutton->setText(QApplication::translate("MainWindow", "Log Off", 0, QApplication::UnicodeUTF8));
        helpbutton->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        thisusr->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
