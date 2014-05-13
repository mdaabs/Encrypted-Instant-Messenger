#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>
#include <convoTab.h>
#include <mainwindow.h>
#include "allusers.h"
#include <QWidget>
#include "QtNetwork"


namespace Ui {
class TabDialog;
}

class TabDialog : public QDialog
{
    Q_OBJECT
    
public:
   // explicit TabDialog(const QString name, int* sock, QWidget *parent = 0);
    explicit TabDialog(allUsers *currentuser, QWidget *parent = 0);

    QVBoxLayout*mainlayout;
    QString thissender;

    bool checkifopen(QString find);
    QTabWidget *tabWidget;
//    QTcpSocket*		tabsocket;
    QBuffer*		buffer;

    int* socket;
    void receiveConvo(string from, string message);
    string searchFrom(string rec);
    string getMessage(string mes);
    ~TabDialog();

signals:
    void senttomain(string *t);

private slots:
    void testrev(string f, string l);
    //void sendMessage();
    void delmytab(const int&);
    int newconvo(QListWidgetItem* item);
    void sendtoser(string *t);
    
private:
    Ui::TabDialog *ui;




};

#endif // TABDIALOG_H
