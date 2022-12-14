#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtDebug>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"
#include <QTimer>
#include "ui_table_view_dict.h"
#include "windowpopup.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void sql_edit_table_view();


    public slots:
        void menu_bar_show_hide(bool change);
        void dict_table_view_open();
        void dict_item_double_clicked(QModelIndex index);
        void config_table_view_dict();
        void add_sql_data();
        void window_popup_show();
        void close_widget();


    private:
        Ui::MainWindow              *ui;
        Ui::Table_view_dict         *ui_table_view_dict;
        WindowPopUp                 m_window_popup;
        QMenu                       *m_menu_right_click;
        QStandardItemModel          *m_modele_dictionary;
        QStandardItemModel          *m_modele_dict_1;
        QStandardItem               *m_item_dictionary;
        QStandardItem               *m_item_1_1_dict;
        QStandardItem               *m_item_2_2_dict;
        QWidget                     m_widget;
        QWidget                     m_widget_dict_1;
        QString                     m_item_1_s;
        QString                     m_item_2_2_s;
        int16_t                     m_dict_1_row;
        int16_t                     m_dict_1_column;
        QSqlQuery                   *m_sql_query;
        QSqlDatabase                *m_sql_db;
        QTimer                      *m_timer_popup;
};
#endif // MAINWINDOW_H
