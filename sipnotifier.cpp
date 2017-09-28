#include "sipnotifier.h"
#include <QtCore/QDebug>

SipNotifier::SipNotifier(QObject *parent, SipServer *server) : QObject(parent)
{
    m_server = server;
}

bool SipNotifier::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        qDebug() << "someone got focus!";
        if (m_server)
            m_server->sendBcastTextMessage("BCAST");
//        if (watched == ui->lineEdit)
//        {
//            qDebug() << "lineEdit got focus!";
//            return true;
//        }
//        else if (watched == ui->lineEdit_2)
//        {
//            qDebug() << "lineEdit_2 got focus!";
//            return true;
//        }
//        else
//        {
//            qDebug() << "someone else got focus! (?!?!)";
//            return true;
//        }
    }

    return false;
}

