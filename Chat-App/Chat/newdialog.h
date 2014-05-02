#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QWidget>

namespace Ui {
class newdialog;
}

class newdialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit newdialog(QWidget *parent = 0);
    ~newdialog();
    
private:
    Ui::newdialog *ui;
};

#endif // NEWDIALOG_H
