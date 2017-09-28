#ifndef SIPNOTIFIER_H
#define SIPNOTIFIER_H

#include "sipserver.h"
#include <QObject>
#include <QEvent>

class SipNotifier : public QObject
{
    Q_OBJECT
public:
    explicit SipNotifier(QObject *parent = nullptr, SipServer *server = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:

private:
    SipServer *m_server;
};

#endif // SIPNOTIFIER_H
