#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit settings(QWidget *parent = 0);
    QString ip;
    QString port;
    void setip(QString x);
    void setport(QString y);
    QString getip(QString x);
    QString getport(QString y);
    //Ui::settings *ui;
    ~settings();
    
public slots:
    void changed();
private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
