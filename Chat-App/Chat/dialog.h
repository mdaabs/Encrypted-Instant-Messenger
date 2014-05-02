#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class TabDialog;
}

class TabDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TabDialog(QWidget *parent = 0);
    ~TabDialog();
    
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
