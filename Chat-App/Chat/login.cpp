#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


    setWindowTitle("Welcome to Crypt-Chat!");


    mysocket = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);
    ui->login_2->setDefault(true);


    this->connect(ui->createnew,SIGNAL(clicked()),this,SLOT(opennew()));
    this->connect(ui->changepass,SIGNAL(clicked()),this,SLOT(changepassw()));
    this->connect(ui->login_2,SIGNAL(clicked()),this,SLOT(checklogin()));
    connect(this, SIGNAL(enterlogin()), this, SLOT(checklogin()));
    this->connect(ui->settingsbutton,SIGNAL(clicked()), this, SLOT(settingsb()));

    connect(mysocket, SIGNAL(readyRead()), SLOT(receiveMessage()));
    connect(this, SIGNAL(loginfosend(string*)), SLOT(sendMessage(string*)));
    connect(this, SIGNAL(sendforkey(string*)), SLOT(sendMessage(string*)));
    connect(this, SIGNAL(logconnect()), SLOT(toggleConnection()));
    connect(this, SIGNAL(connectfailed()), this, SLOT(connectfalse()));
    connect(this, SIGNAL(connectworked()), this, SLOT(connecttrue()));

 }
 void login::settingsb(){


     s=new settings();
     s->connect(s,SIGNAL(saved()),this, SLOT(updateip()));
     s->show();

     temp.setip(s->getip().toStdString());
     temp.setport(s->getport().toStdString());

 }
void login::updateip(){
    temp.setip(s->getip().toStdString());
    temp.setport(s->getport().toStdString());
//    ui->ipaddress->setText(s->getip());
//    ui->p->setText(s->getip());

}
void login::opennew(){
    n= new newuser();
    n->show();
}
void login::changepassw(){
    p= new changepassword();
   p->show();
}
void login::checklogin(){


    QString thisuser=ui->user->text();
    QString thispass=ui->pass->text();

    if(thisuser.count()==0||thispass.count()==0){
        QMessageBox msgBox;
        msgBox.setText("Username or Password cannot be empty");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();
    }else if(checkvalid(thisuser,thispass )) {


    temp.setusername(ui->user->text().toStdString());
    temp.setpassword(ui->pass->text().toStdString());
    temp.setip(ui->ip->text().toStdString());
    temp.setport(ui->port->text().toStdString());


    //temp.setsocket(send.connectto(temp.getip(),temp.getport()));


    emit logconnect();

    //send.sendlogin(logger, temp.getsocket());
    //temp.setclient(send);




    }
}
bool login::checkvalid(QString thisusr, QString thispassw){


    return true;


}
bool login::encryptLogin(string usr, string passw){
    bool result;
    string salt;
    string encryptedUsern, encryptedPassw;
    sendToEncrypt loginfo;
    //encryptedUsern= loginfo.sendLoginToEncrypt(usr);
    encryptedPassw=loginfo.hashPass(passw, salt);
    return result;

}
void login::connectfalse(){
    QMessageBox msgBox;
    msgBox.setText("Could not connect to server");

    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    int ret = msgBox.exec();

}
void login::connecttrue(){
    *logger="LOGIN="+temp.getusername();
    *logger+="*PASS:" +temp.getpassword();
    emit loginfosend(logger);
    pass(&temp);

//    this->hide();

}

void login::pass(allUsers *t){

    w->usr->setusername(t->getusername());
    w->usr->setpassword(t->getpassword());
    w->usr->setip(t->getip());
    w->usr->setstatus(t->getstatus());
    w->usr->setkey(t->getkey());
    w->usr->setiv(t->getiv());
     //w->mainsocket=mysocket;
    w=new MainWindow();
    connect(w, SIGNAL(sendtolog(string*)), this, SLOT(sendMessage(string*)));
    connect(w, SIGNAL(sendtologoff(string*)), this, SLOT(logoff(string*)));
    this->hide();
    w->show();


    }
void login::keyPressEvent(QKeyEvent *e){
 if (e->key()==Qt::Key_Enter)
 {
  qDebug() << "1";
  emit enterlogin();
 }
}
void login::logoff(string* t){

    emit loginfosend(t);
//    w->close();
//    this->close();

}
void login::getlogstatus(string t){
    string *cred;
    cred->append("CREDREQ");
    if(t=="TRUE"){
        temp.setstatus("t");
         pass(&temp);
        emit sendforkey(cred);
        //pass(&temp);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Username or Password are invalid");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);

    }

//    w->close();
//    this->close();

}
void login::getkeyandiv(string t){
    int pos=t.find("*");

    string key=t.substr(4,pos);
    qDebug(key.c_str());
    string iv=t.substr((pos+3));
    qDebug(iv.c_str());
    temp.setkey(key);
    temp.setiv(iv);
    this->hide();




}
void login::recfuntion(int *sock){

    //rectest *tp=new rectest(sock);
    //tp->show();
   // tp->test(sock);

}
void login::toggleConnection()
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

    if (mysocket->state() == QAbstractSocket::UnconnectedState)
    {
       mysocket->connectToHost(QString::fromStdString(temp.getip()), atoi(temp.getport().c_str()));


       if(mysocket->waitForConnected(20000)){
           qDebug("connect");
           emit connectworked();


       }else{
       QMessageBox msgBox;
       msgBox.setText(" Could not connect to host. Try again");

       msgBox.setStandardButtons(QMessageBox::Close);
       msgBox.setDefaultButton(QMessageBox::Close);
       int ret = msgBox.exec();
        }


    }
    else
    {
        mysocket->disconnectFromHost();
        qDebug("didnt work");
        emit connectfailed();
    }
}
void login::sendMessage(string *t)
{
    //example of how the gui and client generate a message to
    //the server

    // "SENDMESSAGE=TO:george*MESSAGE:hi");

    qDebug("sending");
    mysocket->write(t->c_str());
    qDebug("sent");


}
void login::receiveMessage()
{
    //receive message is signaled by the QTcpsocket
    //if its signaled it reads a line
    //sends it to the mainwindow to be displayed

    char recmess[256];
    string line;

     qDebug("read...");

    qint64 bytes = (mysocket->readLine(recmess,sizeof(recmess)));

    qDebug(recmess);
    line= string(recmess);
//    if(line.find("LOGIN=")==0)
//        emit gotlogstatus(line.substr(5));
//    else if(line.find("KEY=")==0)
//        emit gotkeyandiv(line);
//    else
    if(line.length()>0)
        w->receivingmessage(line);

}

login::~login()
{
    delete ui;
}
