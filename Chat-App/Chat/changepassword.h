#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H
#include <QDialog>

#include <QWidget>
#include <QMessageBox>
#include "allusers.h"
#include "string"
#include <QString>
#include "iostream"
#include "fstream"

using namespace std;


namespace Ui {
class changepassword;
}

class changepassword : public QDialog
{
    Q_OBJECT
    
public:
    explicit changepassword(QWidget *parent = 0);
    QTcpSocket*		changesocket;
    QBuffer*		buffer;
     QString *ip;
     QString *port;
    QString *oldpass;
   QString *username;
    QString *newpass;
    QString *sendchangepass;
    ~changepassword();

signals:
    void logconnect();
    void receivedthis(string g);
    void connectworked(QString* p);

public slots:
        void changepass();
        void cancel();
        void toggleConnection();
        void sendMessage(QString* t);
        void receiveMessage();
        void checkiftrue(string g);

    
private:
    Ui::changepassword *ui;
    bool checkpasswords(string, string);
};

#endif // CHANGEPASSWORD_H








