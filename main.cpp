#include "mainwindow.h"
#include "sipserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    bool debug = true;
    int port = 12345;

    QApplication a(argc, argv);

    SipServer *ss = new SipServer(port, debug);
    QObject::connect(ss, &SipServer::closed, &a, &QApplication::quit);

    MainWindow w;
    w.show();

    return a.exec();
}
