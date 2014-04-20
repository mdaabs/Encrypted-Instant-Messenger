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

     s->show();

 }
void login::opennew(){
    n= new newuser();
    n->show();
}
void login::checklogin(){
    int MAX=200;
    int current=0;

    QString thisuser=ui->user->text();
    QString thispass=ui->pass->text();
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

        if(listofusers[current].getusername()==thisuser.toStdString() && listofusers[current].getpassword()==thispass.toStdString())
        {
            temp.setusername(ui->user->text().toStdString());
            temp.setpassword(ui->pass->text().toStdString());
            //temp.setip(ui->ipaddress->text().toStdString());
           // temp.setport(ui->port->text().toStdString());
            temp.setstatus("online");
            load.close();
            pass(&temp);
            break;
        }
        else
            break;

    }
    load.close();
    temp.setusername(ui->user->text().toStdString());
    temp.setpassword(ui->pass->text().toStdString());
    //temp.setip(ui->ipaddress->text().toStdString());
    //temp.setport(ui->port->text().toStdString());
    temp.setstatus("online");
    //temporary pass until synced with database
    pass(&temp);
    this->close();

}
void login::pass(allUsers *t){

    w->usr->setusername(t->getusername());
    w->usr->setpassword(t->getpassword());
    w->usr->setip(t->getip());
    w->usr->setstatus(t->getstatus());
    w->usr->setport(t->getport());

    w=new MainWindow();
    w->show();

}

login::~login()
{
    delete ui;
}
