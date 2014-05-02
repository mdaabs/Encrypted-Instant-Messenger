#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMessageBox>

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
     bool checkvalid(QString x, QString y);
    //Ui::settings *ui;
    ~settings();
    
public slots:
    void changed();
    void cancel();

    QString getip();
    QString getport();


signals:
    void saved();
private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
