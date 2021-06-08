#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QDialog>
#include "person.h"

namespace Ui {
class DetailWindow;
}

class DetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DetailWindow(QWidget *parent = nullptr);
    ~DetailWindow();
    void setPersonDetail(Person person);

private:
    Ui::DetailWindow *ui;

    Person personDetail;
};

#endif // DETAILWINDOW_H
