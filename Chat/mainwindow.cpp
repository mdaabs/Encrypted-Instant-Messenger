#include "QtGui/qmainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "user.h"



 //QString username="George : ";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString username= QString::fromStdString(usr->getusername());

     ui->thisusr->setText(username);
    TabDialog *t= new TabDialog(username,this) ;

   loadFriends();

   ui->convowidget->setLayout(t->mainlayout);
   this->connect(ui->listoffriends,SIGNAL(itemDoubleClicked(QListWidgetItem*)), t, SLOT(newconvo(QListWidgetItem*)));

  }


void MainWindow:: loadFriends(){
    QList<QStringList> list;
    QStringList templist;
    QStringList onlinefriends;
    QList<QStringList> offlist;
    QStringList offtemplist;
    QStringList offlinefriends;



    onlinefriends=(getusers());
    templist=onlinefriends;
    list.append(templist);


    offlinefriends=(getOffline());
    offtemplist=offlinefriends;
    offlist.append(offtemplist);



    QString temper;
    int i=0;

    foreach(temper, list[i]){

    ui->listoffriends->insertItem(i,temper);
    i++;
    }

    QString offtemper;
    int j=0;

    foreach(offtemper, offlist[j]){

    ui->offlinelist->insertItem(j,offtemper);
    j++;
    }



}


MainWindow::~MainWindow()
{
    delete ui;
}
