#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include "allusers.h"
#include "string"
#include <QString>
#include "iostream"
#include "fstream"

using namespace std;

#define file "/home/george/Messenger/Chat/all.txt"

namespace Ui {
class newuser;
}

class newuser : public QDialog
{
    Q_OBJECT
    
public:
    explicit newuser(QWidget *parent = 0);

    ~newuser();
public slots:
        void adduser();


    
private:
    Ui::newuser *ui;
    bool checkusers(string);
    bool checkpasswords(string, string);
    string createip();
    string createstatus();
    QWidget *box;
};

#endif // NEWUSER_H
