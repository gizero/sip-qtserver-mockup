#include "sipnotifier.h"
#include <QLineEdit>
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

        // This is ugly but for now we only watch QLineEdit instances
        QString wt = static_cast<QLineEdit *>(watched)->text();

        if (m_server)
            m_server->sendBcastTextMessage("{ \"type\": \"EDITMODE\", \"text\": \"" + wt + "\" }");
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

