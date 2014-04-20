#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);

}
void settings::changed(){
    setip(ui->ip->text());
    setport(ui->port->text());

}
void settings::setip(QString x){
    ui->ip->setText(x);

}

void settings::setport(QString y){
    ui->port->setText(y);
}
settings::~settings()
{
    delete ui;
}
