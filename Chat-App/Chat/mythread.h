#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>
#include <string.h>
#include <mainwindow.h>
#include <QMainWindow>
using namespace std;
class MyThread : public QThread
{
    Q_OBJECT
public:
     MyThread( QObject *parent = 0);
   // virtual ~MyThread();

    void run();
    string str;

    int *sock;
       // if Stop = true, the thread will break
       // out of the loop, and will be disposed
       bool Stop;

   signals:
       // To communicate with Gui Thread
       // we need to emit a signal
       void valueChanged(string str);

   public slots:

   };

#endif // MYTHREAD_H
