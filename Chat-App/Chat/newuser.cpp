#include "newuser.h"
#include "ui_newuser.h"

newuser::newuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);

    setWindowTitle("Create an Account");

    addsocket = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    connect(addsocket, SIGNAL(readyRead()), SLOT(receiveMessage()));
    connect(this, SIGNAL(connectworked(QString*)), SLOT(sendMessage(QString*)));
    connect(this, SIGNAL(logconnect()), SLOT(toggleConnection()));
    connect(this, SIGNAL(receivedthis(string)), this , SLOT(checkiftrue(string)));


    this->connect(ui->add,SIGNAL(clicked()), this, SLOT(adduser()));
    this->connect(ui->cancel,SIGNAL(clicked()), this, SLOT(cancel()));
}
void newuser::cancel(){
    this->close();

}
void newuser::adduser(){
     QString un= ui->newusername->text();
     QString ps= ui->pass->text();
     QString pass2= ui->pass2->text();
     QString address=ui->newuserip->text();
     QString prt=ui->newuserport->text();
     QString addsend="ADDUSER";
     addsend.append(un);
     addsend.append("*PASS:");
     addsend.append(ps);

     newusers=&un;
     pass=&ps;
     ip=&address;
     port=&prt;
     addnew=&addsend;




        if(checkpasswords(ps.toStdString(),pass2.toStdString())){


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

bool newuser::checkusers(string x){


    return true;
}
void newuser::checkiftrue(string g){

    if(g=="TRUE"){
        QMessageBox msgBox;
        msgBox.setText(" Thank You for joining!");

        msgBox.setStandardButtons(QMessageBox::Close);

        int ret = msgBox.exec();
        this->close();

    }

    else{
        QMessageBox msgBox;
        msgBox.setText(" Username not available. Try again");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();


    }



}

bool newuser::checkpasswords(string a, string b){

    if(a.length()==0)
        return false;
    else if(a==b)
        return true;
    else
        return false;

}
void newuser::toggleConnection()
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

    if (addsocket->state() == QAbstractSocket::UnconnectedState)
    {
        addsocket->connectToHost(*ip,atoi(port->toStdString().c_str()));
        if(addsocket->waitForConnected(20000)){
            qDebug("connect");
            emit connectworked(addnew);


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
//        addsocket->disconnectFromHost();
//        qDebug("didnt work");
//       // emit connectfailed();
//    }
}
void newuser::sendMessage(QString *t)
{
    //example of how the gui and client generate a message to
    //the server

    // "SENDMESSAGE=TO:george*MESSAGE:hi");

    qDebug("sending");
    addsocket->write(t->toStdString().c_str());
    qDebug("sent");


}
void newuser::receiveMessage()
{
    //receive message is signaled by the QTcpsocket
    //if its signaled it reads a line
    //sends it to the mainwindow to be displayed

    char recmess[256];
    string line;

     qDebug("read...");

    qint64 bytes = (addsocket->readLine(recmess,sizeof(recmess)));

    qDebug(recmess);
    line= string(recmess);

    emit receivedthis(line);
//    if(line.find("LOGIN=")==0)
//        emit gotlogstatus(line.substr(5));
//    else if(line.find("KEY=")==0)
//        emit gotkeyandiv(line);
//    else


}

newuser::~newuser()
{
    delete ui;
}
