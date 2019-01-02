#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyle();
    connect(ui->QCheckBox_2, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStyle()
{
    QFile file(":/Qss/res/checkbox.qss");
    if (!file.exists()) {
        qDebug() << "err: no qss file";
        return;
    }
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "err: fail to open qss file";
        return;
    }

    QString fileText = file.readAll();

    ui->QCheckBox_1->setChecked(true);
    ui->QCheckBox_1->setStyleSheet(fileText);
    /* this will make setChecked(false) effect */
    ui->QCheckBox_1->setCheckable(false);

    ui->QCheckBox_2->setChecked(true);
    ui->QCheckBox_2->setStyleSheet(fileText);

    file.close();
}

void MainWindow::on_clicked()
{
    /* simulate setCheckable(false), but can setChecked(true) */
    if (ui->QCheckBox_2->isChecked()) {
        ui->QCheckBox_2->setChecked(false);
    }
    else {
        ui->QCheckBox_2->setChecked(true);
    }
}
