#include "mainwindow.h"
#include "ui_dictionary_table_view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main_window;
    //main_window.setWindowState(Qt::WindowFullScreen);
    main_window.setWindowState(Qt::WindowMaximized);
    main_window.show();

    QWidget widget;
    Ui::Dictionary_table_view ui_dict_table_view;
    ui_dict_table_view.setupUi(&widget);
    widget.show();

    return a.exec();
}
