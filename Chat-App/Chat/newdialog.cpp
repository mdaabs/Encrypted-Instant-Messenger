#include "newdialog.h"
#include "ui_newdialog.h"

newdialog::newdialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newdialog)
{
    ui->setupUi(this);
}

newdialog::~newdialog()
{
    delete ui;
}
