#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),
    ui_table_view_dict(new Ui::Table_view_dict)
/*
 *
 */
{
    ui->setupUi(this);

    ui_table_view_dict->setupUi(&m_widget_dict_1);

    m_modele_dict_1 = new QStandardItemModel(5,3);
    m_modele_dict_1->setItem(3,1, new QStandardItem("Sam dic 1"));
    ui_table_view_dict->tableView->setModel(m_modele_dict_1);

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
    m_item_1_s = m_item_dictionary->index().data().toString();

    //m_item_dictionary->appendRow(new QStandardItem("Dictionary_1.1"));
    m_item_1_1_dict       = new QStandardItem("Dictionary_1.1");
    m_item_dictionary->appendRow(m_item_1_1_dict);
    m_item_1_1_dict->appendRow(new QStandardItem("Dictionary_1.1.1"));

    m_item_dictionary->appendRow(new QStandardItem("Dictionary_1.2"));

    m_item_dictionary       = new QStandardItem("Dictionary_2");
    m_modele_dictionary->appendRow(m_item_dictionary);
    m_item_dictionary->appendRow(new QStandardItem("Dictionary_2.1"));

    m_item_2_2_dict         = new QStandardItem("Dictionary_2.2");
    m_item_dictionary->appendRow(m_item_2_2_dict);
    m_item_2_2_dict->appendRow(new QStandardItem("Dictionary_2.2.1"));
    m_item_2_2_s            = m_item_2_2_dict->index().data().toString();

//    m_index = m_item_2_2_dict->index();
//    qDebug()<<"For m_item_2_2_dict : m_index = "<<m_index;
//    qDebug()<<"For m_item_2_2_dict : column = "<<m_index.column();
//    qDebug()<<"For m_item_2_2_dict : row = "<<m_index.row();
//    qDebug()<<"For m_item_2_2_dict : data = "<<m_index.data();
//    qDebug()<<"For m_item_2_2_dict : string = "<<m_index.data().toString();
//    m_item_2_2_s = m_item_2_2_dict->index().data().toString();
//    qDebug()<<"m_item_2_2_s = "<<m_item_2_2_s;

    ui->treeView->setModel(m_modele_dictionary);
    //-------------------------------------------------------------------------

    //Open a specific dictionary when we do a double click on any one items :
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::dict_item_double_clicked);

}

MainWindow::~MainWindow()
{

    m_widget_dict_1.close();//??
    delete  m_modele_dictionary;
    delete  m_menu_right_click;

    delete ui_table_view_dict;
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
 * Open another GUI created by Qt Designer if the string of the index
 * is the string of a specific item on the TreeView.
 */
    //qDebug()<<"index = "<<index;

    qDebug()<<"index.data().toString() = "<<index.data().toString();
    qDebug()<<"m_item_1_s = "<<m_item_1_s;
    //Check if the string of the index is "Dictionary_2.2".
    //If yes, open another GUI.
    if(index.data().toString() == m_item_1_s){
        m_widget_dict_1.show();
    }
    else if(index.data().toString() == m_item_2_2_s){
        m_widget.show();
    }


}
//-------------------------------------------------------------------------------------------------
