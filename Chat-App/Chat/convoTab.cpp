#include "convoTab.h"
#include "ui_convoTab.h"


//

convoTab::convoTab(const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convoTab)
{
    ui->setupUi(this);

    this->connect(ui->tabsendbutton,SIGNAL(clicked()),this, SLOT(sendmessage()));

}
QString convoTab::getmessage(){
    QString recmsg;
    recmsg=ui->tabmessage->toPlainText();
    ui->tabmessage->clear();
    return recmsg;
    //ui->message->clear();
   // ui->convos=recmsg;


}


void convoTab::sendmessage(){
    QString ms=sender;
    string encrypted;
    ms.append(": ");
    string sendto;
    sendToEncrypt sendencrypt;
    sendToClient *thissend;


   ms.append(getmessage());

    sendto=ms.toStdString();
    // encrypted= sendencrypt.sendInfo(sendto, key);

    thissend->sendmsg(sendto, sock);


   updateconvo(ms);

}
void convoTab::receiveMsg(string mess){
    string decrypt;
    //decrypt=

    updateconvo(QString::fromStdString(mess));


}
void convoTab::updateconvo(QString addmsg){



    int position= ui->tabconvo->count()+1;
    ui->tabconvo->insertItem(position,addmsg);

}
convoTab::~convoTab()
{
    delete ui;
}
