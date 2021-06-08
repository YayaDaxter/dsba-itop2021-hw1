/********************************************************************************
** Form generated from reading UI file 'detailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILWINDOW_H
#define UI_DETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DetailWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;

    void setupUi(QDialog *DetailWindow)
    {
        if (DetailWindow->objectName().isEmpty())
            DetailWindow->setObjectName(QString::fromUtf8("DetailWindow"));
        DetailWindow->resize(448, 336);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DetailWindow->sizePolicy().hasHeightForWidth());
        DetailWindow->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(DetailWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DetailWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(DetailWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(DetailWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(DetailWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(DetailWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(false);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(DetailWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(false);
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(DetailWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(false);
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(DetailWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(DetailWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(DetailWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(DetailWindow);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(DetailWindow);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(DetailWindow);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(DetailWindow);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_7);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(DetailWindow);

        QMetaObject::connectSlotsByName(DetailWindow);
    } // setupUi

    void retranslateUi(QDialog *DetailWindow)
    {
        DetailWindow->setWindowTitle(QCoreApplication::translate("DetailWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DetailWindow", "S.E. percentage- 10th Grade", nullptr));
        label_2->setText(QCoreApplication::translate("DetailWindow", "H.S.E. percentage- 12th Grade", nullptr));
        label_3->setText(QCoreApplication::translate("DetailWindow", "Spec. in H.S.E.", nullptr));
        label_4->setText(QCoreApplication::translate("DetailWindow", "Employability test", nullptr));
        label_5->setText(QCoreApplication::translate("DetailWindow", "Post Grad.(MBA)- Spec.", nullptr));
        label_6->setText(QCoreApplication::translate("DetailWindow", "MBA percentage", nullptr));
        label_7->setText(QCoreApplication::translate("DetailWindow", "Degree Percentage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailWindow: public Ui_DetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILWINDOW_H
