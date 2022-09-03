#include "mainwindow.h"
//#include "testpopup.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main_window;
    //main_window.setWindowState(Qt::WindowFullScreen);
    main_window.setWindowState(Qt::WindowMaximized);
    main_window.show();

//    QWidget widget_pop;

//    Ui::PopUpWindow ui_p_w;

//    ui_p_w.setupUi(&widget_pop);
//    widget_pop.show();

//    TestPopUp test_pop_up;

//    test_pop_up.show();

    return a.exec();
}
