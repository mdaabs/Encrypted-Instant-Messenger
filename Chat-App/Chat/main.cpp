#include "mainwindow.h"
#include "login.h"
#include <QImageIOPlugin>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    login l;

    l.show();
    a.exec();

//    while(1){
//        string h=l.send.receivemsg(l.temp.getsocket());
//        if(h.length()>0)
//                emit l.w->Temprec(h);

//    }

//    a.exec();
//    a.exec();
//    while(1){

//    if(l.send.receivemsg(l.temp.getsocket()).size()>0)
//        break;
//    }


    return 0;
}

