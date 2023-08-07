/**************************************************************************************************
 * Name of the project  : my_dictionary.
 *
 * Name of the creator  : Sam.
 *
 * Description          :
 *
 * Remarks              :
 *
 * Improvements         :
 *
 *************************************************************************************************/
#include "sql_data_base.h"

SqlDataBase::SqlDataBase():
    m_sql_query(0),m_sql_db(0),m_table_column_size(10)

{
/*
 *
 */
    m_sql_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    m_sql_db->setDatabaseName("dictionary_1.db");

    m_sql_query = new QSqlQuery(*m_sql_db);
}
//-------------------------------------------------------------------------------------------------

SqlDataBase::~SqlDataBase(){
/*
 *
 */

}
//-------------------------------------------------------------------------------------------------

void SqlDataBase::send_string_list(){
/*
 * Emit a signal to share a QStringList with another class.
 */
    m_string_list.append("english");
    m_string_list.append("french");
    m_string_list.append("date");

    emit send_string_list_signal(m_string_list);
}
//-------------------------------------------------------------------------------------------------

QStringList SqlDataBase::get_all_data(){
/*
 *
 */
    uint8_t     i_column = 0;

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "This example needs SQLite support. Please read "
                                          "the Qt SQL driver documentation for information how "
                                          "to build it.\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    m_sql_query->exec("SELECT english,french,family,frequency,date,image,syllable,"
                      "sentence,visibility_english,visibility_french FROM dictionary_1");

    //??? Not working, why ???
    //qDebug()<<"nb of column with record() = "<<m_sql_query->record().count();


    while(m_sql_query->next()){
        /*************************************************************************
         * "query.next()" set the current record.
         *
         * The index of the "query.value(...)" return the field of the command
         * "SELECT firstname, lastname FROM person".
         *
         * The filed are numbered from left (0) to right (1).
         *************************************************************************/

        for(i_column = 0 ; i_column < m_table_column_size ; i_column++){
            m_string_list.append(m_sql_query->value(i_column).toString());
        }
    }

    m_sql_db->close();

    return m_string_list;
}
//-------------------------------------------------------------------------------------------------
