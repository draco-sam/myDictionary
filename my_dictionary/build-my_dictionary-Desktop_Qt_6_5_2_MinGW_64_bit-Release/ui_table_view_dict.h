/********************************************************************************
** Form generated from reading UI file 'table_view_dict.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_VIEW_DICT_H
#define UI_TABLE_VIEW_DICT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table_view_dict
{
public:
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLineEdit *line_edit_date;
    QLineEdit *line_edit_french;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *line_edit_english;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_add;
    QPushButton *pb_delete;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Table_view_dict)
    {
        if (Table_view_dict->objectName().isEmpty())
            Table_view_dict->setObjectName("Table_view_dict");
        Table_view_dict->resize(974, 625);
        gridLayout_2 = new QGridLayout(Table_view_dict);
        gridLayout_2->setObjectName("gridLayout_2");
        tableView = new QTableView(Table_view_dict);
        tableView->setObjectName("tableView");
        tableView->horizontalHeader()->setMinimumSectionSize(300);
        tableView->horizontalHeader()->setDefaultSectionSize(300);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        line_edit_date = new QLineEdit(Table_view_dict);
        line_edit_date->setObjectName("line_edit_date");
        line_edit_date->setMinimumSize(QSize(300, 0));
        line_edit_date->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(line_edit_date, 1, 2, 1, 1);

        line_edit_french = new QLineEdit(Table_view_dict);
        line_edit_french->setObjectName("line_edit_french");
        line_edit_french->setMinimumSize(QSize(300, 0));
        line_edit_french->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(line_edit_french, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(Table_view_dict);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(true);
        lineEdit_4->setMinimumSize(QSize(300, 0));
        lineEdit_4->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setBold(true);
        lineEdit_4->setFont(font);
        lineEdit_4->setFrame(false);
        lineEdit_4->setReadOnly(true);

        gridLayout->addWidget(lineEdit_4, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(Table_view_dict);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setMinimumSize(QSize(300, 0));
        lineEdit_5->setMaximumSize(QSize(300, 16777215));
        lineEdit_5->setFont(font);
        lineEdit_5->setAcceptDrops(true);
        lineEdit_5->setAutoFillBackground(false);
        lineEdit_5->setFrame(false);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 0, 1, 1, 1);

        line_edit_english = new QLineEdit(Table_view_dict);
        line_edit_english->setObjectName("line_edit_english");
        line_edit_english->setMinimumSize(QSize(300, 0));
        line_edit_english->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(line_edit_english, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(Table_view_dict);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setMinimumSize(QSize(300, 0));
        lineEdit_6->setMaximumSize(QSize(300, 16777215));
        lineEdit_6->setFont(font);
        lineEdit_6->setFrame(false);
        lineEdit_6->setReadOnly(true);

        gridLayout->addWidget(lineEdit_6, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pb_add = new QPushButton(Table_view_dict);
        pb_add->setObjectName("pb_add");
        pb_add->setMinimumSize(QSize(200, 0));
        pb_add->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setBold(false);
        pb_add->setFont(font1);

        horizontalLayout_2->addWidget(pb_add);

        pb_delete = new QPushButton(Table_view_dict);
        pb_delete->setObjectName("pb_delete");
        pb_delete->setMinimumSize(QSize(200, 0));
        pb_delete->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(pb_delete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(Table_view_dict);

        QMetaObject::connectSlotsByName(Table_view_dict);
    } // setupUi

    void retranslateUi(QWidget *Table_view_dict)
    {
        Table_view_dict->setWindowTitle(QCoreApplication::translate("Table_view_dict", "Form", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Table_view_dict", "English word", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Table_view_dict", "Mot fran\303\247ais", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("Table_view_dict", "date", nullptr));
        pb_add->setText(QCoreApplication::translate("Table_view_dict", "Add", nullptr));
        pb_delete->setText(QCoreApplication::translate("Table_view_dict", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table_view_dict: public Ui_Table_view_dict {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_VIEW_DICT_H
