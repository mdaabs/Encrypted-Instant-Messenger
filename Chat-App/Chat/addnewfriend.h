#ifndef ADDNEWFRIEND_H
#define ADDNEWFRIEND_H

#include <QDialog>

namespace Ui {
class addnewfriend;
}

class addnewfriend : public QDialog
{
    Q_OBJECT
    
public:
    explicit addnewfriend(QWidget *parent = 0);
    ~addnewfriend();
signals:
    void addthis(QString);

public slots:
    void add();
    void cancel();
    
private:
    Ui::addnewfriend *ui;
};

#endif // ADDNEWFRIEND_H
