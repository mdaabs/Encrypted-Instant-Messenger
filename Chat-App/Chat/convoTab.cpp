#include "convoTab.h"
#include "ui_convoTab.h"


//

convoTab::convoTab(const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convoTab)
{
    ui->setupUi(this);
    thiskey="1";
    thisiv="1";
    ui->tabsendbutton->setDefault(true);
    // ui->tabmessage->installEventFilter(this);
    //convosocket = convosocket;
      buffer = new QBuffer(this);
      buffer->open(QIODevice::ReadWrite);

    receiverof=user;
    sendToClient *thisconvo;
    this->connect(ui->tabsendbutton,SIGNAL(clicked()),this, SLOT(createmessage()));
   // this->connect(this,SIGNAL(sendthis()),this, SLOT(sendMessage()));


    test=new rectest();
    connect(this, SIGNAL(trackingbefore(QString)), test, SLOT(trackbf(QString)));
    connect(this, SIGNAL(trackingafter(QString)), test, SLOT(trackaf(QString)));
    test->show();
}

QString convoTab::getmessage(){
    QString recmsg;
    recmsg=ui->tabmessage->toPlainText();
    ui->tabmessage->clear();
    return recmsg;
    //ui->message->clear();
   // ui->convos=recmsg;


}


void convoTab::createmessage(){
    string from_delimiter="FROM:";
    string message_delimiter="MESSAGE:";
    string star_delimiter="*";
    string sendoption="SENDMESSAGE=TO:";
    string to=receiverof.toStdString();
    QString ms=sender;
    string encrypted;
    ms.append(": ");
    string sendto="";
    sendToEncrypt sendencrypt;

    sendToClient *thissend;

   ms.append(getmessage());
    sendto.append(sendoption);
    sendto.append(to);
    sendto.append(star_delimiter+message_delimiter);
    Encryption cryp;

//    cryp.getAesKey();
//    cryp.getAesIV();
//    thiskey=cryp.aesKey;
//    thisiv=cryp.aesIV;
    encrypted=sendencrypt.encryptMessage(ms.toStdString(), thiskey, thisiv);

    sendto.append(ms.toStdString());
    // encrypted= sendencrypt.sendInfo(sendto, key);

    //thissend->sendmsg(sendto, sock);
    emit sendthis(&sendto);


  updateconvo(ms);
    emit trackingbefore(QString::fromStdString(encrypted));

    string decrypt=sendencrypt.decryptMessage(encrypted, thiskey, thisiv);

     emit trackingafter(QString::fromStdString(decrypt));

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
//void convoTab::sendMessage()
//{
//    // "<nick> message\n"
//    convosocket->write(mesSend->c_str());
//    //mysocket->write("SENDMESSAGE=TO:george*MESSAGE:hi");

//}

convoTab::~convoTab()
{
    delete ui;
}
