#include "mainwindow.h"
#include "sql_data_base.h"
//#include "testpopup.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlDataBase sql_db;

    MainWindow main_window;
    //main_window.setWindowState(Qt::WindowFullScreen);
    main_window.setWindowState(Qt::WindowMaximized);

    QObject::connect(&main_window, &MainWindow::send_config_signal, &sql_db, &SqlDataBase::receive_config);

    main_window.send_config(10);

    main_window.show();

//    QWidget widget_1;
//    QWidget widget_2;

//    QPushButton pb_1("push",&widget_1);
//    pb_1.setGeometry(60,50,180,70);

//    //QPushButton pb_2("p2",&widget_2);
//    QPushButton pb_2("p2",&pb_1);

//    QPushButton pb_3;
//    pb_3.setText("pb_3");

//    pb_2.setParent(&pb_3);

//    pb_3.show();

//    widget_1.show();
//    //widget_2.show();


    return a.exec();
}
