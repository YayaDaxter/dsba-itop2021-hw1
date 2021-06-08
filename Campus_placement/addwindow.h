#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include "person.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();
    void setModelPointer(QStandardItemModel* pointerToModel);
    void setDataPointer(PersonData* personData);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddWindow *ui;
    QStandardItemModel* pointerToModel;
    PersonData* pointerToPersonData;
};

#endif // ADDWINDOW_H
