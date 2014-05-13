#include "QtGui/qmainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "user.h"
#include <QtNetwork>
#include <QTcpSocket>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Crypt-Chat");

    QString username= QString::fromStdString(usr->getusername());

     ui->thisusr->setText(username);
     TabDialog *t= new TabDialog(usr,this) ;

     //t->tabsocket=mainsocket;
     addnew=new addnewfriend();

     size=loadFriends();
     friends=new int[size];
     ui->convowidget->setLayout(t->mainlayout);

    //mysocket = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

//     thread=new MyThread(usr->getsocket());
//     connect(thread, SIGNAL(valueChanged(string)), this , SLOT(Temprec(string)));
//    thread->run();
   // thread->Stop=true;



   this->connect(ui->listoffriends,SIGNAL(itemDoubleClicked(QListWidgetItem*)), t, SLOT(newconvo(QListWidgetItem*)));
   this->connect(this,SIGNAL(convonode(QListWidgetItem*)), t, SLOT(newconvo(QListWidgetItem*)));
   this->connect(this,SIGNAL(testrec(string,string)), t, SLOT(testrev(string,string)));
   this->connect(ui->addfriend, SIGNAL(clicked()),this, SLOT(addfriend()) );
    connect(addnew, SIGNAL(addthis(QString)), this, SLOT(add(QString)));

    connect(t,SIGNAL(senttomain(string*)), this, SLOT(sentosock(string*)));


   this->connect(ui->logoffbutton, SIGNAL(clicked()),this, SLOT(logoff()));



}
void MainWindow::addfriend(){


    addnew->show();

}
void MainWindow::add(QString g){

ui->listoffriends->insertItem(ui->listoffriends->count()+1,g );
addtofriends(g, usr->getusername());
}
void MainWindow::Temprec(string tg){
    string delm="*";
    qDebug("received in main....");
    qDebug(tg.c_str());

    std::string recmsg=tg;
    //test for if message
    std::size_t found = recmsg.find(delm);

    if(found!=std::string::npos&& recmsg.length()>0){
        stringstream stream(recmsg.substr(5));
        qDebug(recmsg.c_str());
        string from;
        getline(stream, from,'*');
        qDebug(from.c_str());
        string message=recmsg.substr(recmsg.find(delm)+1);
        qDebug(message.c_str());
        showtab(from);
        emit testrec(from, message);

    }


     this->update();

    return;
//    while(i<200000){

//    }
//    emit refreshmain();

}
void MainWindow::receivingmessage(string msg){
    Temprec(msg);

}
void MainWindow::showtab(string item){

    QString receivefrom=QString::fromStdString(item);
    for(int pos=0; pos<size; pos++)
    {
        if(ui->listoffriends->item(pos)->text()==receivefrom){
            emit convonode(ui->listoffriends->item(pos));
            //tabbox->addWidget(tabwidg->widget(pos));
            break;
        }
    }



}
string MainWindow::searchFrom(string rec){
    string dt="";
   // string from="coco";
//    int next;
//    int i;
//    for( i=0; i<dt.length();i++){
//        if(rec.at(i)==':'){
//            i++;
//           next=i;
//            break;
//        }
//       }
//    i=i-1;
//    for(i;i<dt.length();i++){
//      if(rec.at(i)=='*'){

//            break;
//        }
//    }
//     from=dt.substr(next,i);
//    qDebug(from.c_str());
    return dt;
}
string MainWindow::getMessage(string mes){

    string message=mes;


    return message;
}

int MainWindow:: loadFriends(){
    QList<QStringList> list;
    QStringList templist;
    QStringList onlinefriends;
    QList<QStringList> offlist;
    QStringList offtemplist;
    QStringList offlinefriends;



    onlinefriends=(getusers(usr->getusername()));
    templist=onlinefriends;
    list.append(templist);


    offlinefriends=(getOffline(usr->getusername()));
    offtemplist=offlinefriends;
    offlist.append(offtemplist);



    QString temper;
    int i=0;

    foreach(temper, list[i]){
        if(temper.length()>0){
        ui->listoffriends->insertItem(i,temper);
        }
    i++;
    }

    QString offtemper;
    int j=0;

    foreach(offtemper, offlist[j]){

    ui->offlinelist->insertItem(j,offtemper);
    j++;
    }

    return i;

}
void MainWindow::logoff(){
    string *loff;
    loff->append("LOGOFF=");
    loff->append(usr->getusername());
    emit sendtologoff(loff);
}
void MainWindow::sentosock(string *g){

    emit sendtolog(g);

}
//void MainWindow::receiveMessage()
//{
//    // missing some checks for returns values for the sake of simplicity
//    qint64 bytes = buffer->write(mainsocket->readAll());
//    // go back as many bytes as we just wrote so that it can be read
//    buffer->seek(buffer->pos() - bytes);
//    // read only full lines, line by line
//    while (buffer->canReadLine())
//    {
//        QString line = buffer->readLine();
//        emit Temprec(line.toStdString());
//    }
//}
//void MainWindow::toggleConnection()
//{
//    if (mainsocket->state() == QAbstractSocket::UnconnectedState)
//    {
//        mainsocket->connectToHost(QString::fromStdString(usr->getip()), atoi(usr->getport().c_str()));
//    }
//    else
//    {
//        mainsocket->disconnectFromHost();
//    }
//}
//void MainWindow::sendMessage()
//{
//    // "<nick> message\n"
//    mainsocket->write("LOGIN=george\n");
//    mainsocket->write("SENDMESSAGE=TO:george*MESSAGE:hi");

//}
void MainWindow::closeEvent(QCloseEvent *event){


    this->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
