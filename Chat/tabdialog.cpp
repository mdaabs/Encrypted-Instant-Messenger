#include "tabdialog.h"
#include "ui_tabdialog.h"

TabDialog::TabDialog(const QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabDialog)
{
    ui->setupUi(this);
    thissender=(name);

    tabWidget= new QTabWidget();
    mainlayout= new QVBoxLayout;

}
void TabDialog::newconvo(QListWidgetItem* item){
    QString user=item->text();
    convoTab *temp= new convoTab( user,this);
    temp->sender=thissender;
    tabWidget->addTab(temp,user );
    tabWidget->setTabsClosable(true);
    mainlayout->addWidget(tabWidget);
    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(delmytab(int)));


}
void TabDialog::delmytab(const int& x){
    QWidget* tabItem=tabWidget->widget(x);
    tabItem->close();
    tabItem->deleteLater();
    //tabWidget->removeTab(x);

}

TabDialog::~TabDialog()
{
    delete ui;
}
