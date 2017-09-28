#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sipnotifier.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SipNotifier *sipNotifier = new SipNotifier(this);
    ui->lineEdit->installEventFilter(sipNotifier);
    ui->lineEdit_2->installEventFilter(sipNotifier);
}

MainWindow::~MainWindow()
{
    delete ui;
}
