#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QSortFilterProxyModel>
#include <QtGui>
#include "person.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void save();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

    QStandardItemModel* model;

    QSortFilterProxyModel* proxyModel;

    PersonData* personData; // data
};
#endif // MAINWINDOW_H
