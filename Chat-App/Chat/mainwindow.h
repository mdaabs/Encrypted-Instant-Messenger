#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "user.h"
#include "mainwindow.h"

#include <QString>
#include <fstream>
#include <tabdialog.h>
#include "allusers.h"
#include "settings.h"
#include "convoTab.h"
#include "client.h"





namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    allUsers *usr;
    QString name;
    settings *s;
    ~MainWindow();

public slots:
    // void convonode(QListWidgetItem* item);
    void logoff();

private:
    Ui::MainWindow *ui;

    void loadFriends();
    QString getinfo();






};

#endif // MAINWINDOW_H
