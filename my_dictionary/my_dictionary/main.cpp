/*
 * Vérifier tâches à l'adresse : https://github.com/users/draco-sam/projects/2
 */


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

    //A startup of the main window, edit the main table with data of the day :
    //main_window.table_edit(sql_db.get_data_day());
    main_window.table_edit(sql_db.get_data_all());

    WindowPopUp win_popup;
    win_popup.set_list_day(sql_db.get_data_day());

    //Test QTimer and update of a flag on MainWindow class : --------------------------------------
    QTimer timer_tree;

    //Use of lambda function in  C++ :
    QObject::connect(&timer_tree, &QTimer::timeout, &main_window, &MainWindow::tree_check_flag);
    QObject::connect(&main_window, &MainWindow::get_tree_flag, [&](bool flag){
        //!!! Change with a structure later !!!
        if(flag == true){
            //!!! Manage data higher than 50 (like on different page) !!!
            main_window.table_edit(sql_db.get_data_all());
        }
        //qDebug()<<"flag = "<<flag;
    });

    QObject::connect(&main_window, &MainWindow::add_data_to_database, &sql_db, &SqlDataBase::add_data_to_db);
    QObject::connect(&sql_db, &SqlDataBase::send_message_to_status_bar, &main_window, &MainWindow::show_message_to_status_bar);

    QObject::connect(&main_window, &MainWindow::show_next_page, &sql_db, &SqlDataBase::ask_next_data);
    QObject::connect(&sql_db, &SqlDataBase::send_next_list, &main_window, &MainWindow::main_table_update);

    timer_tree.start(5000);
    //---------------------------------------------------------------------------------------------

    sql_db.edit_data("test");

    main_window.show();

    return a.exec();
}
