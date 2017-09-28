#ifndef SIPNOTIFIER_H
#define SIPNOTIFIER_H

#include <QObject>
#include <QEvent>

class SipNotifier : public QObject
{
    Q_OBJECT
public:
    explicit SipNotifier(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:
};

#endif // SIPNOTIFIER_H
