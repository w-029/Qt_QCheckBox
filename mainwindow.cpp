#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* apply the qss style */
    QFile file(":/Qss/checkbox.qss");
    if (file.open(QFile::ReadOnly)) {
        QString fileText = file.readAll();

        ui->QCheckBox_1->setChecked(true);
        ui->QCheckBox_1->setStyleSheet(fileText);

        ui->QCheckBox_2->setChecked(true);
        ui->QCheckBox_2->setStyleSheet(fileText);

        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
