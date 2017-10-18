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

    QCommandLineOption portOption(QStringList() << "p" << "port",
                                   "TCP port to listen to (1-65535).", "12345");
    parser.addOption(portOption);

    parser.process(a);

    port = parser.value(portOption).toInt();
    if (port < 1 || port > 65535) {
        fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Invalid port argument. Must be 1-65535")));
                parser.showHelp(1);
    }

    SipServer *ss = new SipServer(port, debug);
    QObject::connect(ss, &SipServer::closed, &a, &QApplication::quit);

    MainWindow w(0, ss);
    w.show();

    return a.exec();
}
