#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>
#include <convoTab.h>
#include <mainwindow.h>

namespace Ui {
class TabDialog;
}

class TabDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TabDialog(const QString name, QWidget *parent = 0);
    QVBoxLayout*mainlayout;
    QString thissender;
    ~TabDialog();
private slots:
    void newconvo(QListWidgetItem* item);
    void delmytab(const int&);

    
private:
    Ui::TabDialog *ui;
    QTabWidget *tabWidget;



};

#endif // TABDIALOG_H
