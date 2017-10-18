#include "mainwindow.h"
#include "sipserver.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    bool debug = true;
    int port = 12345;

    QApplication a(argc, argv);
    QCommandLineParser parser;

    parser.setApplicationDescription("Qt server mockup");
    parser.addHelpOption();

    parser.process(a);

    SipServer *ss = new SipServer(port, debug);
    QObject::connect(ss, &SipServer::closed, &a, &QApplication::quit);

    MainWindow w(0, ss);
    w.show();

    return a.exec();
}
