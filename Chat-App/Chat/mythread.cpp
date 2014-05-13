#include "mythread.h"
#include "client.h"

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
//    sock=socket;
}
void MyThread::run()
{
    sendToClient thisc;
    string mss;
    while(1)
    {
        QMutex mutex;
        // prevent other threads from changing the "Stop" value
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();
        mss=thisc.receivemsg(sock);
        // emit the signal for the count label
        if(mss.size()>0)
            emit valueChanged(mss);

        // slowdown the count change, msec
        this->msleep(500);
    }
}
