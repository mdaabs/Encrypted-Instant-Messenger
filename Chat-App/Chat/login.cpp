#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->connect(ui->createnew,SIGNAL(clicked()),this,SLOT(opennew()));
    this->connect(ui->login_2,SIGNAL(clicked()),this,SLOT(checklogin()));
    this->connect(ui->settingsbutton,SIGNAL(clicked()), this, SLOT(settingsb()));



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
    temp.setstatus("online");


    temp.setsocket(send.connect(temp.getip(),temp.getport()));

    pass(&temp);
      this->close();

    }
}
bool login::checkvalid(QString thisusr, QString thispassw){
    int MAX=200;
    int current=0;
    //check if username and password valid
    string line;
    allUsers listofusers[MAX];
    ifstream load;
    load.open(file);
    while(getline(load,line)){
        int i=0;
        int j=0;

        for(i=0;i<line.length();i++){
            if(line.at(i)==','){
            listofusers[current].setusername(line.substr(j,i));
            i++;
            j=i;
            break;

            }}
        for(i;i<line.length();i++){
            if(line.at(i)==','){
            listofusers[current].setpassword(line.substr(j,i));
            i++;
            j=i;
            break;

            }

        }

        if(listofusers[current].getusername()==thisusr.toStdString() && listofusers[current].getpassword()==thispassw.toStdString())
        {
            temp.setusername(ui->user->text().toStdString());
            temp.setpassword(ui->pass->text().toStdString());

            temp.setstatus("online");
            load.close();
            pass(&temp);
            break;
        }
        else
            break;

    }
    load.close();

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
void login::pass(allUsers *t){

    w->usr->setusername(t->getusername());
    w->usr->setpassword(t->getpassword());
    w->usr->setip(t->getip());
    w->usr->setstatus(t->getstatus());
    w->usr->setport(t->getport());
    w->usr->setsocket(t->getsocket());
    w=new MainWindow();
    w->show();

}

login::~login()
{
    delete ui;
}
