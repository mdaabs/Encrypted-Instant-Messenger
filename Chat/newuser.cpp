#include "newuser.h"
#include "ui_newuser.h"

newuser::newuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);
    this->connect(ui->add,SIGNAL(clicked()), this, SLOT(adduser()));
}
void newuser::adduser(){
    const QString newuser= ui->newusername->text();
    const QString pass= ui->pass->text();
    const QString pass2= ui->pass2->text();
    QMessageBox message;
    box=new QWidget;

    allUsers name;

    if(checkusers(newuser.toStdString()))
    {

        if(checkpasswords(pass.toStdString(),pass2.toStdString())){
        name.setusername(newuser.toStdString());
        name.setpassword(pass.toStdString());
        name.setip(createip());
        name.setstatus(createstatus());

        ofstream addto;
        addto.open(file, ios::app);
        addto<<name.getusername()<<','<<name.getpassword()<<','<<name.getip()<<','<<name.getstatus()<<'\n';
        addto.close();
        this->close();
        }
        else{


           // message.setText("Passwords were not the same. Try Again.");



        }


    }
    else{


        //message.setText("Username is already taken. Try Again.");

    }






}

bool newuser::checkusers(string x){

    string line;
    ifstream checkto;
    checkto.open(file);
    while(getline(checkto, line,',')){
        if(line==x){
            checkto.close();
            return false;
        }

    }

    checkto.close();
    return true;
}
bool newuser::checkpasswords(string a, string b){

    if(a==b)
        return true;
    else
        return false;

}
string newuser::createip(){
    return "0.0.0.1";

}
string newuser::createstatus(){
    return "f";
}

newuser::~newuser()
{
    delete ui;
}
