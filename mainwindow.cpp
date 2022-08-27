#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),
    ui_table_view_dict(new Ui::Table_view_dict),m_menu_right_click(0), m_modele_dictionary(0),
    m_modele_dict_1(0),m_item_dictionary(0),m_item_1_1_dict(0),m_dict_1_row(0),m_dict_1_column(0)
/*
 *
 */
{
    ui->setupUi(this);

    //ui->menubar->hide();
    //ui->checkBox->toggled();
    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::menu_bar_show_hide);
    //ui->dockWidget_2->hide();

    config_table_view_dict();

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

    sql_test();

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
 * Open another GUI created on Qt Designer if the string of the index
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

void MainWindow::config_table_view_dict(){
/*
 * Tabe View dictionary that will contain words in a sql database.
 */
    ui_table_view_dict->setupUi(&m_widget_dict_1);
    m_widget_dict_1.setWindowState(Qt::WindowMaximized);

    QStringList horizontal_header_labels = {"English","Français","date"};

    m_modele_dict_1 = new QStandardItemModel(10,3);
    m_modele_dict_1->setHorizontalHeaderLabels(horizontal_header_labels);
    m_modele_dict_1->setItem(4,1, new QStandardItem("Sam dic 1"));

    ui_table_view_dict->tableView->setModel(m_modele_dict_1);
}
//-------------------------------------------------------------------------------------------------

void MainWindow::sql_test(){
/*
 *
 */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    //Sets the connection's database : --------------------------------------------------
    /* To have effect, the database name must be set before the connection is opened.
     *
     * For the QSQLITE driver, if the database name specified does not exist,
     * hen it will create the file for you
     * unless the QSQLITE_OPEN_READONLY option is set.
     */

    db.setDatabaseName("dictionary_1.db");
    //-----------------------------------------------------------------------------------

    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

    QSqlQuery query;

//    query.exec("create table dictionary_1 (id int primary key, "
//               "english varchar(20), french varchar(20), date varchar(10))");

//    query.exec("insert into dictionary_1 values(101, 'hello', 'bonjour', '25/08/2022')");
//    query.exec("insert into dictionary_1 values(102, 'welcom', 'bienvenue', '26/08/2022')");
//    query.exec("insert into dictionary_1 values(103, 'word', 'mot', '27/08/2022')");

    query.exec("SELECT english, french, date FROM dictionary_1");

    while(query.next()){
        /*************************************************************************
         * "query.next()" set the current record.
         *
         * The index of the "query.value(...)" return the field of the command
         * "SELECT firstname, lastname FROM person".
         *
         * The filed are numbered from left (0) to right (1).
         *************************************************************************/

        m_modele_dict_1->setItem(m_dict_1_row,0,
                                 new QStandardItem(query.value(0).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,1,
                                 new QStandardItem(query.value(1).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,2,
                                 new QStandardItem(query.value(2).toString()));
        m_dict_1_row++;

        qDebug()<<query.value(0).toString()<<" : "<<query.value(1).toString()<<
                  " : "<<query.value(2).toString();
    }
}
//-------------------------------------------------------------------------------------------------




