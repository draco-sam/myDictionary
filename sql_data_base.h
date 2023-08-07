#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QObject>
#include <QtDebug>
#include <QStringList>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"

class SqlDataBase : public QObject
{
    Q_OBJECT

    public:
        SqlDataBase();
        ~SqlDataBase();
        void send_string_list();
        QStringList get_data_all();
        QStringList get_data_day();

    signals:
        void send_string_list_signal(QStringList list);//To delete !!!

    public slots:


    private:
        QStringList                 m_string_list;
        QStringList                 m_string_list_all;
        QStringList                 m_string_list_day;
        QSqlQuery                   *m_sql_query;
        QSqlDatabase                *m_sql_db;
        uint8_t                     m_table_main_column_size;
        uint8_t                     m_table_day_column_size;
        uint8_t                     m_column_frequency_num;
};

#endif // SQLDATABASE_H
