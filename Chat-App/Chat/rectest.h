#ifndef RECTEST_H
#define RECTEST_H

#include <QDialog>

namespace Ui {
class rectest;
}

class rectest : public QDialog
{
    Q_OBJECT
    
public:
    explicit rectest(QWidget *parent = 0);
    ~rectest();
    
public slots:
    void trackbf(QString bf);
    void trackaf(QString af);
private:
    Ui::rectest *ui;
};

#endif // RECTEST_H
