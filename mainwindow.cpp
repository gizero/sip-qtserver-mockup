#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sipserver.h"
#include "sipnotifier.h"

MainWindow::MainWindow(QWidget *parent, SipServer *server) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SipNotifier *sipNotifier = new SipNotifier(this, server);
    ui->lineEdit->installEventFilter(sipNotifier);
    ui->lineEdit_2->installEventFilter(sipNotifier);
}

MainWindow::~MainWindow()
{
    delete ui;
}
