#include "addnewfriend.h"
#include "ui_addnewfriend.h"

addnewfriend::addnewfriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewfriend)
{
    ui->setupUi(this);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
}
void addnewfriend::add(){
 QString friendname;
 friendname=ui->friend_2->text();
 emit addthis(friendname);
 this->close();

}
void addnewfriend::cancel(){
this->close();

}
addnewfriend::~addnewfriend()
{
    delete ui;
}
