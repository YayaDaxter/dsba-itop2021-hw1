#include "detailwindow.h"
#include "ui_detailwindow.h"
#include "person.h"
#include <QString>

DetailWindow::DetailWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailWindow)
{
    ui->setupUi(this);
}

void DetailWindow::setPersonDetail(Person person)
{

    ui->lineEdit->setText(QString::fromStdString(person.sePercentage));
    ui->lineEdit_2->setText(QString::fromStdString(person.hsePercentage));
    ui->lineEdit_3->setText(QString::fromStdString(person.spec));
    ui->lineEdit_4->setText(QString::fromStdString(person.employability));
    ui->lineEdit_5->setText(QString::fromStdString(person.mbaSpec));
    ui->lineEdit_6->setText(QString::fromStdString(person.mbaPercentage));
    ui->lineEdit_7->setText(QString::fromStdString(person.degree));
}

DetailWindow::~DetailWindow()
{
    delete ui;
}
