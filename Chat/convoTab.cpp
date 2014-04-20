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
    ms.append(": ");
    string sendto;
    sendToEncrypt send;

   ms.append(getmessage());

   sendto=ms.toStdString();

   send.sendToEncrypter(sendto);

   updateconvo(ms);

}
void convoTab::updateconvo(QString addmsg){

    /*if
    for(int i=0; i<addmsg.size();i++)
    */
    int position= ui->tabconvo->count()+1;
    ui->tabconvo->insertItem(position,addmsg);

    /*string sendstr=addmsg.toStdString();
    ofstream convofile;
    convofile.open("/home/george/Messenger/Chat/convo.txt", ios::app);
    convofile<<sendstr<<'\n';
    convofile.close();
*/
}
convoTab::~convoTab()
{
    delete ui;
}
