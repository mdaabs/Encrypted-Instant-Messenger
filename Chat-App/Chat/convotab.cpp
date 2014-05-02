#include "convotab.h"
#include "ui_convotab.h"

convoTab::convoTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convoTab)
{
    ui->setupUi(this);
}

convoTab::~convoTab()
{
    delete ui;
}
