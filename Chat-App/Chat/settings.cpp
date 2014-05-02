#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);
    this->connect(ui->save, SIGNAL(clicked()),this, SLOT(changed()));
  this->connect(ui->cancel, SIGNAL(clicked()),this, SLOT(cancel()));

}
bool settings::checkvalid(QString x, QString y){
    if(x.length()==0 || y.length()==0)
        return false;

    return true;

}
void settings::changed(){
    setip(ui->ip->text());

    setport(ui->port->text());
    if(checkvalid(getip(),getport())){
        QMessageBox msgBox;
        msgBox.setText("IP or Port cannot be empty");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();

    }else{
    emit saved();
    this->close();
    }
}
void settings::cancel(){
    this->close();
}
void settings::setip(QString x){
    ui->ip->setText(x);

}

void settings::setport(QString y){
    ui->port->setText(y);
}
QString settings::getip(){
    return ui->ip->text();

}
QString settings::getport(){

    return ui->port->text();
}
settings::~settings()
{
    delete ui;
}
