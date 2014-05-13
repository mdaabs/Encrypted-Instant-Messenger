#include "rectest.h"
#include "ui_rectest.h"

rectest::rectest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rectest)
{
    ui->setupUi(this);
}
void rectest::trackbf(QString bf){

ui->listWidget->addItem(bf);

}
void rectest::trackaf(QString af){
ui->listWidget_2->addItem(af);

}

rectest::~rectest()
{
    delete ui;
}
