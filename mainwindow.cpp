#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),
    ui_dict_table_view(new Ui::Dictionary_table_view)
/*
 *
 */
{
    ui->setupUi(this);

    ui_dict_table_view->setupUi(&m_widget);
    connect(ui->button_add, &QPushButton::clicked, this, &MainWindow::dict_table_view_open);

    //ui->menubar->hide();
    //ui->checkBox->toggled();
    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::menu_bar_show_hide);
    //ui->dockWidget_2->hide();

    m_menu_right_click = new QMenu("test",this);
    m_menu_right_click->addMenu("test");
    //m_menu_right_click->showTearOffMenu();

    //Dictionaries on Main Window : -------------------------------------------
    m_modele_dictionary     = new QStandardItemModel;

    m_item_dictionary       = new QStandardItem("Dictionary_1");
    m_modele_dictionary->appendRow(m_item_dictionary);

    //m_item_dictionary->appendRow(new QStandardItem("Dictionary_1.1"));
    m_item_1_1_dict       = new QStandardItem("Dictionary_1.1");
    m_item_dictionary->appendRow(m_item_1_1_dict);
    m_item_1_1_dict->appendRow(new QStandardItem("Dictionary_1.1.1"));

    m_item_dictionary->appendRow(new QStandardItem("Dictionary_1.2"));

    m_item_dictionary       = new QStandardItem("Dictionary_2");
    m_modele_dictionary->appendRow(m_item_dictionary);
    m_item_dictionary->appendRow(new QStandardItem("Dictionary_2.1"));

    m_item_2_2_dict       = new QStandardItem("Dictionary_2.2");
    m_item_dictionary->appendRow(m_item_2_2_dict);
    m_item_2_2_dict->appendRow(new QStandardItem("Dictionary_2.2.1"));

    m_index = m_item_2_2_dict->index();
    qDebug()<<"For m_item_2_2_dict : m_index = "<<m_index;
    qDebug()<<"For m_item_2_2_dict : column = "<<m_index.column();
    qDebug()<<"For m_item_2_2_dict : row = "<<m_index.row();
    qDebug()<<"For m_item_2_2_dict : data = "<<m_index.data();
    qDebug()<<"For m_item_2_2_dict : string = "<<m_index.data().toString();

    ui->treeView->setModel(m_modele_dictionary);
    //-------------------------------------------------------------------------

    //Open a specific dictionary when we do a double click on any one items :
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::dict_item_double_clicked);

}

MainWindow::~MainWindow()
{
    delete  m_modele_dictionary;
    delete  m_menu_right_click;
    delete  ui;
}

//-------------------------------------------------------------------------------------------------

void MainWindow::menu_bar_show_hide(bool change){
/*
 *
 */
    if(change == true){//button is checked.
        ui->menubar->show();
    }
    else if(change == false){//button is unchecked.
        ui->menubar->hide();
    }
}
//-------------------------------------------------------------------------------------------------

void MainWindow::dict_table_view_open(){
/*
 *
 */
    m_widget.show();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::dict_item_double_clicked(QModelIndex index){
/*
 *
 */
    qDebug()<<"index = "<<index;

    m_widget.show();
}
//-------------------------------------------------------------------------------------------------
