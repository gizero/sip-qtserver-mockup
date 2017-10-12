#ifndef SIPSERVER_H
#define SIPSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class SipServer : public QObject
{
    Q_OBJECT
public:
    explicit SipServer(quint16 port, bool debug = false, QObject *parent = Q_NULLPTR);
    ~SipServer();

    void sendBcastTextMessage(QString message);
    int getClientsCount();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();
    void echoTextMessage(QString message);
    void echoBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    bool m_debug;
};

#endif // SIPSERVER_H
