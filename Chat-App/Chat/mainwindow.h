#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "user.h"
#include "mainwindow.h"

#include <QString>
#include <fstream>
#include <tabdialog.h>
#include "allusers.h"
#include "settings.h"
#include "convoTab.h"
#include "client.h"
#include "tabdialog.h"
#include "sendtoclient.h"
#include "mythread.h"
#include "QtNetwork"
#include "addnewfriend.h"





namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    allUsers *usr;
     QVBoxLayout*tabbox;
   // TabDialog *t;
    QTabWidget *tabwidg;
    QString name;
    settings *s;
//    QTcpSocket*	mainsocket;
    QBuffer*		buffer;
    //MyThread *thread;
    int *friends;
    int size;
    addnewfriend *addnew;
    string searchFrom(string rec);
    string getMessage(string mes);
     void showtab(string item);
     void receivingmessage(string msg);
     void closeEvent(QCloseEvent *event);
    //void showtab(string item);
   // void Temprec(string r);

    ~MainWindow();
   signals:
    void convonode(QListWidgetItem* item);
    void refreshmain();
    void testrec(string f, string l);
    void sendtolog(string *g);
    void sendtologoff(string *g);

public slots:
    void Temprec(string);
    int loadFriends();
    void logoff();
    void sentosock(string *g);
    void addfriend();
    void add(QString g);
//    void receiveMessage();
//    void toggleConnection();
//    void sendMessage();


private:
    Ui::MainWindow *ui;


    QString getinfo();






};

#endif // MAINWINDOW_H
