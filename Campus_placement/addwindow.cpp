#include "addwindow.h"
#include "ui_addwindow.h"
#include <QString>

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

void AddWindow::setModelPointer(QStandardItemModel* model)
{
    pointerToModel = model;
}

void AddWindow::setDataPointer(PersonData *personData)
{
    pointerToPersonData = personData;
}

AddWindow::~AddWindow()
{
    delete ui;
}


void AddWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_4->text() != "" && ui->lineEdit_5->text() != "" && ui->lineEdit_6->text() != "" && ui->lineEdit_7->text() != "" && ui->lineEdit_8->text() != "" && ui->lineEdit_9->text() != "" && ui->lineEdit_10->text() != "" && ui->lineEdit_11->text() != "" && ui->lineEdit_12->text() != "")
    {
        int row = pointerToModel->rowCount();

        pointerToModel->insertRows(row, 1); // inserting row #2 (we have now three rows)

        QModelIndex index = pointerToModel->index(row, 0, QModelIndex());
        pointerToModel->setData(index,ui->lineEdit->text());

        index = pointerToModel->index(row, 1, QModelIndex());
        pointerToModel->setData(index,ui->lineEdit_2->text());

        index = pointerToModel->index(row, 2, QModelIndex());
        pointerToModel->setData(index,ui->lineEdit_6->text());

        index = pointerToModel->index(row, 3, QModelIndex());
        pointerToModel->setData(index,ui->lineEdit_5->text());

        index = pointerToModel->index(row, 4, QModelIndex());
        pointerToModel->setData(index,ui->lineEdit_8->text());

        std::string sePercentage = ui->lineEdit_3->text().toStdString();
        std::string hsePercentage = ui->lineEdit_4->text().toStdString();
        std::string spec = ui->lineEdit_9->text().toStdString();
        std::string degree = ui->lineEdit_10->text().toStdString();
        std::string employability = ui->lineEdit_11->text().toStdString();
        std::string mbaSpec = ui->lineEdit_12->text().toStdString();
        std::string mbaPercentage = ui->lineEdit_7->text().toStdString();

        pointerToPersonData->update();
        pointerToPersonData->setInfo(sePercentage,hsePercentage,spec,degree,employability,mbaSpec,mbaPercentage,row);
    }
    else
        std::cout << "Complete form" << '\n';
}
