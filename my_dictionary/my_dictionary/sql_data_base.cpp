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
    m_sql_query(0),m_sql_db(0),m_table_main_column_size(11),m_table_day_column_size(11),
    m_column_frequency_num(4)

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
    m_list_string.append("english");
    m_list_string.append("french");
    m_list_string.append("date");

    emit send_string_list_signal(m_list_string);
}
//-------------------------------------------------------------------------------------------------

QStringList SqlDataBase::get_data_all(){
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

    m_sql_query->exec("SELECT id,english,french,family,frequency,date,image,syllable,"
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

        for(i_column = 0 ; i_column < m_table_main_column_size ; i_column++){
            m_list_all_string.append(m_sql_query->value(i_column).toString());
        }
    }

    m_sql_db->close();

    return m_list_all_string;
}
//-------------------------------------------------------------------------------------------------

ListData SqlDataBase::get_data_day(){
/*
 *
 */
    uint8_t         i_column    = 0;
    uint16_t        line_number = 0;
    uint16_t        table_size  = 0;
    QStringList     list_temporary;

    table_size = m_list_day.size;

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "This example needs SQLite support. Please read "
                                          "the Qt SQL driver documentation for information how "
                                          "to build it.\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    m_sql_query->exec("SELECT id, english,french,family,frequency,date,image,syllable,"
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

        for(i_column = 0 ; i_column < m_table_day_column_size ; i_column++){
            list_temporary.append(m_sql_query->value(i_column).toString());
        }

        if(list_temporary[m_column_frequency_num].toInt() >= 8){//old 7.
            if(line_number < table_size){
                m_list_day.table[line_number] = list_temporary;
                line_number++;
            }
        }

        list_temporary.clear();
    }//End while.

    m_sql_db->close();

    m_list_day.size = line_number;

    return m_list_day;
}

//-------------------------------------------------------------------------------------------------
