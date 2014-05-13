#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "allusers.h"
#include "newuser.h"
#include "string"
#include <QString>
#include "iostream"
#include "fstream"
#include "settings.h"
#include "sendtoencrypt.h"
#include "sendtoclient.h"
#include "client.h"
#include <pthread.h>
#include "mythread.h"
#include "rectest.h"
#include "QtNetwork"
#include "changepassword.h"

using namespace std;

#define file "/home/george/Messenger/Chat/all.txt"

#define NUM_THREADS     5

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    MainWindow *w;

    sendToClient send;
    allUsers temp;
     settings *s;
      string *logger;
    QTcpSocket*		mysocket;
    QBuffer*		buffer;
    void pass(allUsers *t);
    //MyThread *thread;
    //pthread_t threads[NUM_THREADS];
    bool encryptLogin(string usr, string passw);
    void recfuntion(int *sock);
    ~login();
signals:
    void logconnect();
     void connectfailed();
     void connectworked();
     void gotlogstatus(string t);
     void gotkeyandiv(string t);
    void loginfosend(string *f);
    void sendforkey(string* t);
    void enterlogin();

public slots:
    void opennew();
    void changepassw();
    void checklogin();
    void settingsb();
    void updateip();
    void toggleConnection();
    void sendMessage(string* t);
    void receiveMessage();
    void connecttrue();
    void connectfalse();
    void logoff(string* t);
    void getlogstatus(string t);
    void getkeyandiv(string t);
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::login *ui;
    bool checkvalid(QString thisusr, QString thispassw);
    newuser *n;
     changepassword *p;
};

#endif // LOGIN_H
