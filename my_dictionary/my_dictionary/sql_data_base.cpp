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
    m_table_all_column_size(11),m_column_frequency_num(4),m_current_offset(0),m_page_size(50)

{
/*
 *
 */
    m_sql_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    m_sql_db->setDatabaseName("dictionary_1.db");

    m_sql_query = new QSqlQuery(*m_sql_db);

    m_current_time = QTime::currentTime();//Initialisation.
    //qDebug()<<"m_current_time = "<<m_current_time.toString();
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

ListData SqlDataBase::get_data_all(){
 /*
 * !!! Check if it's possible to merde "get_data_all()" and "get_data_day()" !!!
 */
    uint8_t         i_column    = 0;
    uint16_t        line_number = 0;
    uint16_t        table_size  = 0;
    QStringList     list_temporary;

    //m_currentOffset = m_currentOffset + m_page_size;

    QString queryString = QString("SELECT id, english,french,family,frequency,date,image,syllable,"
                                  "sentence,visibility_english,visibility_french FROM dictionary_1 ORDER BY Id LIMIT %1 OFFSET %2")
                              .arg(m_page_size)
                              .arg(m_current_offset);

    table_size = m_list_data_all.size;

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "This example needs SQLite support. Please read "
                                          "the Qt SQL driver documentation for information how "
                                          "to build it.\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    m_sql_query->exec(queryString);


    //??? Not working, why ???
    //qDebug()<<"nb of column with record() = "<<m_sql_query->record().count();

    //-----------------------------------------------------------------------------------
    while(m_sql_query->next()){
        /*************************************************************************
         * "query.next()" set the current record.
         *
         * The index of the "query.value(...)" return the field of the command
         * "SELECT firstname, lastname FROM person".
         *
         * The filed are numbered from left (0) to right (1).
         *************************************************************************/

        //Construct QStringList with QString of each cell of one line :
        for(i_column = 0 ; i_column < m_table_all_column_size ; i_column++){
            list_temporary.append(m_sql_query->value(i_column).toString());
        }

        //Put the QStringList in a box of a table :
        if(line_number < table_size){
            m_list_data_all.table[line_number] = list_temporary;
            line_number++;
        }

        list_temporary.clear();
    }//End while.
    //-----------------------------------------------------------------------------------

    m_sql_db->close();

    m_list_data_all.size = line_number;qDebug()<<"line_number = "<<line_number;

    return m_list_data_all;
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

    table_size = m_list_data_day.size;

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
                m_list_data_day.table[line_number] = list_temporary;
                line_number++;
            }
        }

        list_temporary.clear();
    }//End while.

    m_sql_db->close();

    m_list_data_day.size = line_number;

    return m_list_data_day;
}

//-------------------------------------------------------------------------------------------------

void SqlDataBase::edit_data(QString data){
/*
 * !!! Show id on the data base now (26/08/2023) !!!
 */
    bool        db_flag         = false;
    QString     updateQuery     = "";

    db_flag = open_and_check();

    if(db_flag == true){
        updateQuery = QString("UPDATE dictionary_1 SET image = '%1' WHERE id = %2")
                        .arg("image/sam")
                        .arg(10);

        if(m_sql_query->exec(updateQuery)){
            qDebug()<<"update db OK";
        }
        else{
            qDebug()<<"error with update of db";
        }
    }
    else{
        qDebug()<<"!!! error with data base !!!";
    }



    m_sql_db->close();

}
//-------------------------------------------------------------------------------------------------

bool SqlDataBase::open_and_check(){
/*
 *
 */
    bool db_flag = false;

    m_sql_db->close();

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "This example needs SQLite support. Please read "
                                          "the Qt SQL driver documentation for information how "
                                          "to build it.\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        db_flag = true;
    }

    return db_flag;
}
//-------------------------------------------------------------------------------------------------

void SqlDataBase::add_data_to_db(QStringList s_list){
/*
 * add all data at the end of the sql database.
 */
    QVariant    lastId              = "";
    QString     english             = s_list[0];
    QString     french              = s_list[1];
    QString     family              = s_list[2];
    QString     frequency           = s_list[3];
    QString     date                = s_list[4];
    QString     image               = s_list[5];
    QString     syllable            = s_list[6];
    QString     sentence            = s_list[7];
    QString     visibility_english  = s_list[8];
    QString     visibility_french   = s_list[9];

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        //return;
    }

    // ------------------------------------------------------------------------
    //Get the value of the last id of the database :

    if (m_sql_query->exec("SELECT MAX(Id) FROM dictionary_1")) {
        if (m_sql_query->next()) {
            lastId = m_sql_query->value(0).toInt() + 1;
            qDebug() << "Le dernier Id est : " << lastId.toInt();
        } else {
            qDebug() << "La table est vide.";
        }
    } else {
        qDebug() << "Erreur de requête";
    }
    //-------------------------------------------------------------------------

    m_sql_query->prepare("INSERT INTO dictionary_1 (id, english, french, family, frequency, date, image, syllable,"
                         "sentence, visibility_english, visibility_french) "
                         "VALUES (:lastId, :english, :french, :family, :frequency, :date, :image, :syllable,"
                         ":sentence, :visibility_english, :visibility_french)");

    m_sql_query->bindValue(":lastId", lastId);
    m_sql_query->bindValue(":english", english);
    m_sql_query->bindValue(":french", french);
    m_sql_query->bindValue(":family", family);
    m_sql_query->bindValue(":frequency", frequency);
    m_sql_query->bindValue(":date", date);
    m_sql_query->bindValue(":image", image);
    m_sql_query->bindValue(":syllable", syllable);
    m_sql_query->bindValue(":sentence", sentence);
    m_sql_query->bindValue(":visibility_english", visibility_english);
    m_sql_query->bindValue(":visibility_french", visibility_french);

    if (m_sql_query->exec()) {
        qDebug() << "Nouvelle ligne ajoutée avec succès.";

        emit send_message_to_status_bar("SQL database is updated : " + m_current_time.currentTime().toString());
    } else {
        qDebug() << "Erreur d'insertion";
    }
}
//---------------------------------------------------------------------------------------------------------------------

void SqlDataBase::ask_next_data(){
/*
 * Slot to ask the sql database for the next 50 words.
 * The signal is emmitted on the main.cpp, by the mainwindow object.
 */
    //ListData get_data_all();

    ListData list;

    m_current_offset = m_current_offset + m_page_size;

    list = get_data_all();

    emit send_next_list(list);
}
//---------------------------------------------------------------------------------------------------------------------
