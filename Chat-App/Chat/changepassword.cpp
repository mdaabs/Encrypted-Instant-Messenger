#include "changepassword.h"
#include "ui_changepassword.h"

changepassword::changepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
    setWindowTitle("Change Password");
    changesocket = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    connect(changesocket, SIGNAL(readyRead()), SLOT(receiveMessage()));
    connect(this, SIGNAL(connectworked(QString*)), SLOT(sendMessage(QString*)));
    connect(this, SIGNAL(logconnect()), SLOT(toggleConnection()));
    connect(this, SIGNAL(receivedthis(string)), this , SLOT(checkiftrue(string)));


    this->connect(ui->submit,SIGNAL(clicked()), this, SLOT(changepass()));
    this->connect(ui->cancel,SIGNAL(clicked()), this, SLOT(cancel()));
}
void changepassword::cancel(){
    this->close();

}

void changepassword::changepass(){
     QString un= ui->username->text();
     QString ops= ui->oldpass->text();
     QString pass= ui->newpass->text();
     QString pass2= ui->newpass2->text();
     QString address=ui->changepasswordip->text();
     QString prt=ui->changepasswordport->text();
     QString change="CHANGEPASSWORD=";
     change.append(un);
     change.append("*PASS:");
     change.append(ops);
     change.append("*NEWPASS:");
     change.append(pass);

     username=&un;
     oldpass=&ops;
     ip=&address;
     port=&prt;
     sendchangepass=&change;




        if(checkpasswords(pass.toStdString(),pass2.toStdString())){


            emit logconnect();


        }
        else{
            QMessageBox msgBox;
            msgBox.setText(" Passwords are not valid or do not match");

            msgBox.setStandardButtons(QMessageBox::Close);
            msgBox.setDefaultButton(QMessageBox::Close);
            int ret = msgBox.exec();







    }
//    else{
//        QMessageBox msgBox;
//        msgBox.setText(" Username is not valid!");

//        msgBox.setStandardButtons(QMessageBox::Close);
//        msgBox.setDefaultButton(QMessageBox::Close);
//        int ret = msgBox.exec();

//        //message.setText("Username is already taken. Try Again.");

//    }






}

void changepassword::checkiftrue(string g){

    if(g=="TRUE"){
        QMessageBox msgBox;
        msgBox.setText(" Thank You for joining!");

        msgBox.setStandardButtons(QMessageBox::Close);

        int ret = msgBox.exec();
        this->close();

    }

    else{
        QMessageBox msgBox;
        msgBox.setText(" Password did not match. Try again");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();


    }



}

bool changepassword::checkpasswords(string a, string b){

    if(a.length()==0)
        return false;
    else if(a==b)
        return true;
    else
        return false;

}
void changepassword::toggleConnection()
{
    //the login screen defines a variable of type QTcpsocket
    //
    // QTcpSocket *mysocket = new QTcpSocket(this);
    //
    // QTcpsocket is a QObject (just like any object)
    // QTcpsocket has a set of protocols which when
    // it creates a connection between two hosts
    // they can exchange data

    // mysocket->state() returns if it is already connected
    // if not, create a connection

    if (changesocket->state() == QAbstractSocket::UnconnectedState)
    {
        changesocket->connectToHost(*ip,atoi(port->toStdString().c_str()));
        if(changesocket->waitForConnected(20000)){
            qDebug("connect");
            emit connectworked(sendchangepass);


        }
        else{
        QMessageBox msgBox;
        msgBox.setText(" Could not connect to host. Try again");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();
        }





    }






//    else
//    {
//        changesocket->disconnectFromHost();
//        qDebug("didnt work");
//       // emit connectfailed();
//    }
}
void changepassword::sendMessage(QString *t)
{
    //example of how the gui and client generate a message to
    //the server

    // "SENDMESSAGE=TO:george*MESSAGE:hi");

    qDebug("sending");
    changesocket->write(t->toStdString().c_str());
    qDebug("sent");


}
void changepassword::receiveMessage()
{
    //receive message is signaled by the QTcpsocket
    //if its signaled it reads a line
    //sends it to the mainwindow to be displayed

    char recmess[256];
    string line;

     qDebug("read...");

    qint64 bytes = (changesocket->readLine(recmess,sizeof(recmess)));

    qDebug(recmess);
    line= string(recmess);

    emit receivedthis(line);
//    if(line.find("LOGIN=")==0)
//        emit gotlogstatus(line.substr(5));
//    else if(line.find("KEY=")==0)
//        emit gotkeyandiv(line);
//    else


}
changepassword::~changepassword()
{
    delete ui;
}
