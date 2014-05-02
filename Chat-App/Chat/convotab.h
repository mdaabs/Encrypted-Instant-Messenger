#ifndef CONVOTAB_H
#define CONVOTAB_H

#include <QWidget>

namespace Ui {
class convoTab;
}

class convoTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit convoTab(QWidget *parent = 0);
    ~convoTab();
    
private:
    Ui::convoTab *ui;
};

#endif // CONVOTAB_H
