#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QObject>
#include <QtDebug>

class SqlDataBase : public QObject
{
    Q_OBJECT

    public:
        SqlDataBase();
        ~SqlDataBase();

    public slots:
        void receive_config(uint8_t config_number);
};

#endif // SQLDATABASE_H
