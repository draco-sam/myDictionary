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
        QStringList get_all_data();

    signals:
        void send_string_list_signal(QStringList list);

    public slots:


    private:
        QStringList                 m_string_list;
        QSqlQuery                   *m_sql_query;
        QSqlDatabase                *m_sql_db;
        uint8_t                     m_table_column_size;
};

#endif // SQLDATABASE_H
