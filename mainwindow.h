#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "ui_dictionary_table_view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void menu_bar_show_hide(bool change);
        void dict_table_view_open();
        void dict_item_double_clicked();


    private:
        Ui::MainWindow              *ui;
        Ui::Dictionary_table_view   *ui_dict_table_view;
        QMenu                       *m_menu_right_click;
        QStandardItemModel          *m_modele_dictionary;
        QStandardItem               *m_item_dictionary;
        QStandardItem               *m_item_1_1_dict;
        QStandardItem               *m_item_2_2_dict;
        QWidget                     m_widget;
};
#endif // MAINWINDOW_H
