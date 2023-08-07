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
    main_window.table_edit_all_data(sql_db.get_data_all());
    //main_window.table_edit_all_data(sql_db.get_data_day());//Test for list of day on main.

    WindowPopUp win_popup;
    QPoint point_popup;

    point_popup.setX(20);//old : 650 or 950.
    point_popup.setY(150);//old : 150 or 455.

    win_popup.move(point_popup);

    win_popup.show();

//    //Test to share QStringList between 2 class :
//    QObject::connect(&sql_db, &SqlDataBase::send_string_list_signal, &main_window, &MainWindow::receive_string_list);
//    sql_db.send_string_list();




    //While(1) with flag to start request_sql_data from main_window ??
    //Or SqlDataBase object in MainWindow object ???

    main_window.show();

    return a.exec();
}
