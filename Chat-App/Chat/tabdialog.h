#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>
#include <convoTab.h>
#include <mainwindow.h>
#include "allusers.h"

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

    int* socket;
    ~TabDialog();
private slots:
    void newconvo(QListWidgetItem* item);
    void receiveNewConvo(allUsers user);
    void delmytab(const int&);

    
private:
    Ui::TabDialog *ui;
    QTabWidget *tabWidget;



};

#endif // TABDIALOG_H
