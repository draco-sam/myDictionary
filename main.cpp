#include "mainwindow.h"
#include "sql_data_base.h"
#include "windowpopup.h"
//#include "testpopup.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    SqlDataBase sql_db;

    MainWindow main_window;
    //main_window.setWindowState(Qt::WindowFullScreen);
    main_window.setWindowState(Qt::WindowMaximized);

    //Edit the main table with the SQL data
    //that is given by the SqlDataBase class.
    //main_window.table_edit_all_data(sql_db.get_data_all());//table_edit

    main_window.table_edit(sql_db.get_data_day());



    //main_window.table_edit(sql_db.get_data_day());

//    //Test of get_data_day() with structure : -----------------------
//    ListDay list_day;

//    list_day = sql_db.get_data_day();

//    uint8_t i_for = 0;

//    for(i_for = 0 ; i_for < list_day.size ; i_for++){
//        if(list_day.table[i_for].isEmpty() == false){
//            qDebug()<<"list_day = "<<list_day.table[i_for];
//        }
//    }
//    //---------------------------------------------------------------


    WindowPopUp win_popup;

    win_popup.show();

//    //Test to share QStringList between 2 class :
//    QObject::connect(&sql_db, &SqlDataBase::send_string_list_signal, &main_window, &MainWindow::receive_string_list);
//    sql_db.send_string_list();




    //While(1) with flag to start request_sql_data from main_window ??
    //Or SqlDataBase object in MainWindow object ???

    main_window.show();

    return a.exec();
}
