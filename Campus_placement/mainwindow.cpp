#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "person.h"
#include "detailwindow.h"
#include "addwindow.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);

    model->setHorizontalHeaderItem(0, new QStandardItem("Serial Number"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Gender"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Work Experience"));
    model->setHorizontalHeaderItem(3, new QStandardItem("Field of degree education"));
    model->setHorizontalHeaderItem(4, new QStandardItem("Salary"));

    personData = new PersonData(model);

    proxyModel = new QSortFilterProxyModel();

    proxyModel->setSourceModel(model);

    ui->tableView->setModel(proxyModel);

    ui->tableView->setSortingEnabled(true);


    QObject::connect(model, &QStringListModel::rowsRemoved, personData, &PersonData::remove);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete personData;
    delete proxyModel;
    delete model;
}


void MainWindow::on_pushButton_5_clicked()
{
    personData->open(this);
    for(int row = 0; row < personData->getDataSize(); row++)
    {
        model->insertRows(row, 1);
    }
    personData->initModel();
}

void MainWindow::on_pushButton_4_clicked()
{
     About aboutWindow;
     aboutWindow.setWindowTitle("About Window");
     aboutWindow.setModal(true);
     aboutWindow.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

    QModelIndex proxyIndex = ui->tableView->currentIndex();

    QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);

    model->removeRow(modelIndex.row());

    update();

}

void MainWindow::on_pushButton_clicked()
{
    std :: cout << "Saving data to a file..." << std :: endl;
    this->save();
}

void MainWindow::on_pushButton_3_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if(selectedRow>=0)
    {
        int selectedRow = ui->tableView->currentIndex().row();
        DetailWindow detailWindow;

        detailWindow.setWindowTitle("Detail Window");

        Person person = personData->getPerson(selectedRow);

        detailWindow.setPersonDetail(person);
        detailWindow.setModal(true);
        detailWindow.exec();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    AddWindow addWindow;
    addWindow.setWindowTitle("Add Window");
    addWindow.setModelPointer(model);
    addWindow.setDataPointer(personData); // this would be like setStudentDetail
    addWindow.setModal(true);
    addWindow.exec();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(QRegExp::FixedString);

    Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive;

    QString text = ui->lineEdit->text();

    QRegExp filter(text, caseSensitivity, syntax);

    proxyModel->setFilterRegExp(filter);

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    std::cout << "Changed sorting to column: " << ui->comboBox->currentIndex() << std :: endl;
    proxyModel->setFilterKeyColumn(ui->comboBox->currentIndex());
}

void MainWindow::on_actionAbout_triggered()
{
    About aboutWindow;
    aboutWindow.setWindowTitle("About Window");
    aboutWindow.setModal(true);
    aboutWindow.exec();
}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save file", "", ".csv");
    QFile f(fileName);

    if( f.open( QIODevice::WriteOnly ) )
    {
//        QTextStream ts( &f );
//        QStringList strList;

//        for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
//            strList << ui->tableView->model()->headerData(c, Qt::Horizontal).toString();
//        ts << strList.join(';')+"\n";

//        for( int r = 0; r < ui->tableView->verticalHeader()->count(); ++r )
//        {
//            strList.clear();
//            strList << ui->tableView->model()->headerData(r, Qt::Vertical).toString();
//            for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
//            {
//                strList << ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString();
//            }
//            ts << strList.join(';');
//        }
        //
        f.write("Serial Number;Gender;S.E. percentage- 10th Grade;H.S.E. percentage- 12th Grade;Spec. in H.S.E.;Degree Percentage;Field of degree education;Work Experience;Employability test;Post Grad.(MBA)- Spec.;MBA percentage;Salary\n");
        for(int i = 0; i < (int) personData->getDataSize(); i++)
        {
            std::stringstream ss;
            ss << personData->getPerson(i).serialNumber << ";" << personData->getPerson(i).gender << ";" << personData->getPerson(i).sePercentage << ";" << personData->getPerson(i).hsePercentage << ";" << personData->getPerson(i).spec << ";" << personData->getPerson(i).degree << ";" << personData->getPerson(i).field << ";" << personData->getPerson(i).workExp << ";" << personData->getPerson(i).employability << ";" << personData->getPerson(i).mbaSpec << ";" << personData->getPerson(i).mbaPercentage << ";" << personData->getPerson(i).salary << "\n";
            f.write(ss.str().c_str());
        }
        f.close();
    }
}

void MainWindow::on_checkBox_2_pressed()
{
//    if (ui->checkBox_2->isEnabled() == true) // ui->checkBox->isChecked() == false
//    {
//        ui->checkBox->setEnabled(false);
//      ui->checkBox->isEnabled();
//        if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
//        {

//        }
//    }
}

void MainWindow::on_checkBox_2_released()
{
//    ui->checkBox->setEnabled(true);
}

void MainWindow::on_checkBox_pressed()
{
//    if (ui->checkBox->isEnabled() == true)
//    {
//        ui->checkBox_2->setEnabled(false);
//        if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
//        {

//        }
//    }
}

void MainWindow::on_checkBox_released()
{
//
}

void MainWindow::on_checkBox_clicked()
{
//    if (ui->checkBox_2->isEnabled() == true /*&&  ui->checkBox_2->isChecked() == false*/)
//    {
//        ui->checkBox_2->setEnabled(false);
//        if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
//        {

//        }
//        else
//            std::cout << "Wrong column" << '\n';
//    }
//    else
//        ui->checkBox_2->setEnabled(true);
    if ( ui->checkBox_2->isEnabled() == true /*&&  ui->checkBox->isChecked() == false*/)
    {
        ui->checkBox_2->setEnabled(false);
        if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
        {

        }
        else
        {
            std::cout << "Wrong column" << '\n';
            ui->checkBox->setChecked(false);
            ui->checkBox_2->setEnabled(true);

        }
    }
    else
        ui->checkBox_2->setEnabled(true);
}

void MainWindow::on_checkBox_2_clicked()
{
    if ( ui->checkBox->isEnabled() == true /*&&  ui->checkBox->isChecked() == false*/)
    {
        ui->checkBox->setEnabled(false);
        if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
        {

        }
        else
        {
            std::cout << "Wrong column" << '\n';
            ui->checkBox_2->setChecked(false);
            ui->checkBox->setEnabled(true);

        }
    }
    else
        ui->checkBox->setEnabled(true);
//    if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Salary")
//    {
//        if ( ui->checkBox->isEnabled() == true)
//        {
//            ui->checkBox->setEnabled(false);
//        }
//        else
//        {
//            std::cout << "Both checkboxes cannot be used" << '\n';
//            ui->checkBox_2->setChecked(false);
//            ui->checkBox->setEnabled(true);
//        }
//    }
//    else
//    {
//        std::cout << "Wrong column" << '\n';
//        ui->checkBox_2->setChecked(false);
//        ui->checkBox->setEnabled(true);
//    }
}
