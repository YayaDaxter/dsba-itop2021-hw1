#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <QStringList>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QFile>
#include <QMainWindow>

struct Person
{
    std::string serialNumber;
    std::string gender;
    std::string sePercentage;
    std::string hsePercentage;
    std::string spec;
    std::string degree;
    std::string field;
    std::string workExp;
    std::string employability;
    std::string mbaSpec;
    std::string mbaPercentage;
    std::string salary;
};

class PersonData : public QObject
{
    Q_OBJECT

    public:
        PersonData(QStandardItemModel* model)
        {
            pointerToModel = model;
        }

        void save(QMainWindow* window)
        {
            QString filename = QFileDialog::getSaveFileName(window, "Save file", "", ".csv");
            QFile f(filename);
            f.open(QIODevice::WriteOnly);
            f.write("Serial Number,Gender,S.E. percentage- 10th Grade,H.S.E. percentage- 12th Grade,Spec. in H.S.E.,Degree Percentage,Field of degree education,Work Experience,Employability test,Post Grad.(MBA)- Spec.,MBA percentage,Salary\n");
            for(int i = 0; i < (int) _data.size(); i++)
            {
                std::stringstream ss;
                ss << _data[i].serialNumber << "," << _data[i].gender << "," << _data[i].sePercentage << "," << _data[i].hsePercentage << "," << _data[i].spec << "," << _data[i].degree << "," << _data[i].field << "," << _data[i].workExp << "," << _data[i].employability << "," << _data[i].mbaSpec << "," << _data[i].mbaPercentage << "," << _data[i].salary << "\n";
                f.write(ss.str().c_str());
            }
            f.close();
        }

        Person getPerson(int i)
        {
            return _data[i];
        }

        int getDataSize()
        {
            return _data.size();
        }

        void setInfo(std::string sePercentage, std::string hsePercentage, std::string spec,std::string degree,
                     std::string employability,std::string mbaSpec, std::string mbaPercentage,int i)
        {

            _data[i].sePercentage = sePercentage;
            _data[i].hsePercentage = hsePercentage;
            _data[i].spec = spec;
            _data[i].degree = degree;
            _data[i].employability = employability;
            _data[i].mbaSpec= mbaSpec;
            _data[i].mbaPercentage = mbaPercentage;
        }

        void initModel()
        {
            // fill the model with data
            for(int row = 0; row < _data.size(); row++)
            {
                for(int col = 0; col < 5; col++)
                {
                    QModelIndex index = pointerToModel->index(row, col, QModelIndex());
                    QString cellValue;
                    switch(col)
                    {
                        case 0: cellValue = QString::fromStdString(_data[row].serialNumber);
                                break;

                        case 1: cellValue = QString::fromStdString(_data[row].gender);
                                break;

                        case 2: cellValue = QString::fromStdString(_data[row].workExp);
                                break;

                        case 3: cellValue = QString::fromStdString(_data[row].field);
                                break;

                        case 4: cellValue = QString::fromStdString(_data[row].salary);
                                break;
                    }

                    pointerToModel->setData(index, cellValue); // initialize a cell in the model with zero value (you can also put a string instead of 0)
                }
            }
        }

        void open(QMainWindow* window)
        {
            QString fileName = QFileDialog::getOpenFileName(window,"Open File","*.csv");
            QFile file(fileName);
            file.open(QIODevice::ReadOnly);

            file.readLine();

            int row = 0;

            while(!file.atEnd())
            {
                QByteArray line = file.readLine();
                QList<QByteArray> lineAsVector = line.split(';');
                _data.push_back(Person());
                _data[row].serialNumber = lineAsVector.at(0).toStdString();
                _data[row].gender = lineAsVector.at(1).toStdString();
                _data[row].sePercentage = lineAsVector.at(2).toStdString();
                _data[row].hsePercentage = lineAsVector.at(3).toStdString();
                _data[row].spec = lineAsVector.at(4).toStdString();
                _data[row].degree = lineAsVector.at(5).toStdString();
                _data[row].field = lineAsVector.at(6).toStdString();
                _data[row].workExp = lineAsVector.at(7).toStdString();
                _data[row].employability = lineAsVector.at(8).toStdString();
                _data[row].mbaSpec = lineAsVector.at(9).toStdString();
                _data[row].mbaPercentage = lineAsVector.at(10).toStdString();
                _data[row].salary = lineAsVector.at(11).toStdString();

                row++;
            }
            initModel();
        }

        void remove()
        {
            update();
        }

        void clear()
        {
            _data.clear();
        }

        void update()
        {
            std :: cout << "Cell updated! Updating data..." << std::endl;

            for(int row = 0; row < pointerToModel->rowCount(); row++){

                if(row >= (int) _data.size())           // if the "model" has more elements than the "data"
                    _data.push_back(Person());         // add a new element to the "data".

                for(int col = 0; col < pointerToModel->columnCount(); col++)
                {
                    QModelIndex index = pointerToModel->index(row,col);
                    std::string cellValue = (index.data().toString()).toStdString();

                    switch(col)
                    {
                        case 0: _data[row].serialNumber = cellValue;
                                break;

                        case 1: _data[row].gender = cellValue;
                                break;

                        case 2: _data[row].workExp = cellValue;
                                break;

                        case 3: _data[row].field = cellValue;
                            break;

                        case 4: _data[row].salary = cellValue;
                            break;
                    }
                }
            }
        }

    private:
        std::vector<Person> _data;

        QStandardItemModel* pointerToModel;

//        QSortFilterProxyModel* pointerToModel;
};

#endif // PERSON_H

