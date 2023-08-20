#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QObject>
#include <QtDebug>
#include <QStringList>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"
#include "list_data_struct.h"

//struct ListDay{
//    QStringList table[50];
//    uint16_t    size = 50;
//};

class SqlDataBase : public QObject
{
    Q_OBJECT

    public:
        SqlDataBase();
        ~SqlDataBase();
        void send_string_list();
        ListData get_data_all();
        ListData get_data_day();

    signals:
        void send_string_list_signal(QStringList list);//To delete !!!

    public slots:


    private:
        QStringList                 m_list_string;
        QStringList                 m_list_all_string;
        ListData                     m_list_data_day;
        ListData                     m_list_data_all;
        QSqlQuery                   *m_sql_query;
        QSqlDatabase                *m_sql_db;
        uint8_t                     m_table_main_column_size;
        uint8_t                     m_table_day_column_size;
        uint8_t                     m_table_all_column_size;//Use same virable for day et all ???
        uint8_t                     m_column_frequency_num;
};

#endif // SQLDATABASE_H
