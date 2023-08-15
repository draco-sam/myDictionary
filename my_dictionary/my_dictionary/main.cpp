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

    WindowPopUp win_popup;
    win_popup.set_list_day(sql_db.get_data_day());



//    QStringList list_01 = {"0","1","2"};
//    QStringList list_02;

//    QStringList table[2];

//    list_02 = list_01;


//    table[0] = list_01;
//    table[1] = list_02;

//    qDebug()<<"table[1] = "<<table[1];

//    list_01.removeOne("1");
//    qDebug()<<"list_01 = "<<list_01;

//    table[0].clear();
//    qDebug()<<"table[0] = "<<table[0];
//    qDebug()<<"isEmpty = "<<table[0].isEmpty();

//    //Test to share QStringList between 2 class :
//    QObject::connect(&sql_db, &SqlDataBase::send_string_list_signal, &main_window, &MainWindow::receive_string_list);
//    sql_db.send_string_list();




    //While(1) with flag to start request_sql_data from main_window ??
    //Or SqlDataBase object in MainWindow object ???

    main_window.show();

    return a.exec();
}
