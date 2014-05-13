#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include "allusers.h"
#include "string"
#include <QString>
#include "iostream"
#include "fstream"

using namespace std;

#define file "/home/george/Messenger/Chat/all.txt"

namespace Ui {
class newuser;
}

class newuser : public QDialog
{
    Q_OBJECT
    
public:
    explicit newuser(QWidget *parent = 0);
    QTcpSocket*		addsocket;
    QBuffer*		buffer;
     QString *ip;
     QString *port;
    QString *addnew;
   QString *newusers;
    QString *pass;
      ~newuser();

signals:
    void logconnect();
    void receivedthis(string g);
    void connectworked(QString* p);

public slots:
        void adduser();
        void cancel();
        void toggleConnection();
        void sendMessage(QString* t);
        void receiveMessage();
        void checkiftrue(string g);
       // void displayError(QAbstractSocket::SocketError);


    
private:
    Ui::newuser *ui;
    bool checkusers(string);
    bool checkpasswords(string, string);
    string createip();
    string createstatus();
    QWidget *box;
};

#endif // NEWUSER_H
