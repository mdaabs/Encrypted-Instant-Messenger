#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "allusers.h"
#include "newuser.h"
#include "string"
#include <QString>
#include "iostream"
#include "fstream"
#include "settings.h"

using namespace std;

#define file "/home/george/Messenger/Chat/all.txt"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    MainWindow *w;
    allUsers temp;
     settings *s;
    void pass(allUsers *t);
    ~login();

public slots:
    void opennew();
    void checklogin();
    void settingsb();
    
private:
    Ui::login *ui;
    newuser *n;
};

#endif // LOGIN_H
