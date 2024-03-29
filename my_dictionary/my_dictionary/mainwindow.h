#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtDebug>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <QSqlRecord>
#include "ui_table_view_dict.h"
#include "list_data_struct.h"

#define ALL_SQL_DATA        0


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void table_edit_all_data(QStringList list);
        void table_edit(ListData list_data);
        void creat_widget_1();
        void creat_widget_2();

    signals:

    public slots:
        void menu_bar_show_hide(bool change);
        void dict_table_view_open();
        void dict_item_double_clicked(QModelIndex index);
        void config_table_dict_main_window();
        void close_widget();
        void widget_test();
        void change_widget();
        void receive_string_list(QStringList list);


    private:
        Ui::MainWindow              *ui;
        Ui::Table_view_dict         *ui_table_view_dict;
        QMenu                       *m_menu_right_click;
        QStandardItemModel          *m_modele_dictionary;
        QStandardItemModel          *m_modele_dict_1;//old modele.
        QStandardItemModel          *m_model_dict_2;//New for main window.
        QStandardItem               *m_item_dictionary;
        QStandardItem               *m_item_1_1_dict;
        QStandardItem               *m_item_2_2_dict;
        QWidget                     m_widget;
        QWidget                     m_widget_dict_1;
        QString                     m_item_1_s;
        QString                     m_item_2_s;
        QString                     m_item_2_2_s;
        int16_t                     m_dict_1_row;
        int16_t                     m_dict_2_row;
        int16_t                     m_dict_1_row_last;
        int16_t                     m_dict_2_row_last;
        int16_t                     m_dict_1_column;
        uint16_t                    m_sql_row_count;
        uint16_t                    m_random;
        uint8_t                     m_f_frequency;//Flag.
        uint8_t                     m_frequency;
        QString                     m_frequency_s;
        QString                     m_word_english;
        QString                     m_word_french;
        uint8_t                     m_word_same_f;//Flag for same word.
        uint8_t                     m_word_same_counter;
        QStringList                 m_list_day;
        uint16_t                    m_nb_of_word;
        uint8_t                     m_popup_f_first_time;//Flag.
        uint8_t                     m_popup_f_show;//Flag to show or not the pop up.
        QTimer                      *m_timer_widget;
        QWidget                     m_widget_1;
        QWidget                     m_widget_2;
        QWidget                     *m_widget_3;
        QWidget                     m_widget_4;
        QPushButton                 *m_pb_1;
        QPushButton                 *m_pb_2;
        QPushButton                 *m_pb_3;
        QTableView                  m_table_view_1;
        QGridLayout                 *m_layout_grid_1;
        QGridLayout                 *m_layout_grid_2;
        QGridLayout                 *m_layout_grid_3;
        QGridLayout                 *m_layout_grid_4;
        QLineEdit                   m_line_1;
        QLineEdit                   m_line_2;
        QTime                       m_time;//To get the current time.
        uint8_t                     m_table_main_column_size;
        ListData                    m_list_data;
};
#endif // MAINWINDOW_H
