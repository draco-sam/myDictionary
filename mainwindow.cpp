/**************************************************************************************************
 * Name of the project  : my_dictionary.
 *
 * Name of the creator  : Sam.
 * Date                 : 04/09/2022
 *
 * Description          :
 *
 * Remarks              :
 *
 * Improvements         :
 *  - Put sql attributes, methodes, signals and slots in a separate class file (04/09/2022).
 *  - Show the QStringList in construction (during the day) when the mouse passes over the window.
 *************************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_windowpopup.h"

//MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow),ui_table_view_dict(new Ui::Table_view_dict),
    ui_popup(new Ui::WindowPopUp),

    m_menu_right_click(0), m_modele_dictionary(0),
    m_modele_dict_1(0),m_item_dictionary(0),m_item_1_1_dict(0),m_dict_1_row(0),m_dict_1_column(0),
    m_sql_query(0),m_sql_db(0),m_sql_row_count(0),m_random(0),m_nb_of_word(0),m_timer_popup(0),
    m_timer_widget(0)
/*
 *
 */
{
    ui->setupUi(this);

    ui_popup->setupUi(&m_widget);


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

    ui->treeView->setModel(m_modele_dictionary);
    //-------------------------------------------------------------------------

    //Open a specific dictionary when we do a double click on any one items :
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::dict_item_double_clicked);

    connect(ui_table_view_dict->pb_add, &QPushButton::clicked, this, &MainWindow::add_sql_data);



    //sql test : ----------------------------------------------------------------------------------
    m_sql_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    m_sql_db->setDatabaseName("dictionary_1.db");

    m_sql_query = new QSqlQuery(*m_sql_db);
    //---------------------------------------------------------------------------------------------

    //First call of the pop up window with a timer :
    m_timer_popup = new QTimer(this);
    connect(m_timer_popup, &QTimer::timeout, this, &MainWindow::window_popup_show);
    m_timer_popup->start(2000);

    //Test change of widget : ------------------------------------------------------
    m_pb_1.setText("pb_1");
    m_pb_1.setGeometry(60, 50, 180, 70);
    m_pb_1.setParent(&m_widget_1);

    m_pb_2.setText("pb_2");
    m_pb_2.setParent(&m_widget_2);
    m_pb_3.setText("pb_3");
    m_pb_3.move(30,30);
    m_pb_3.setParent(&m_widget_2);

    m_widget_1.setParent(&m_widget_3);
    m_widget_2.setParent(NULL);

    m_timer_widget = new QTimer(this);
    connect(m_timer_widget, &QTimer::timeout, this, &MainWindow::widget_test);
    m_timer_widget->start(6000);

    m_widget_3.show();
    //------------------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
    //qDebug()<<"!!! destructor !!!"<<m_window_popup.close();
    qDebug()<<"!!! destructor !!!";

    //m_window_popup.hide();

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
        sql_edit_table_view();
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

void MainWindow::sql_edit_table_view(){
/*
 * Edit the items on the table view with sql data.
 *
 * ??? db.close() ???
 */
    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

    m_sql_query->exec("SELECT english, french, date FROM dictionary_1");

    //qDebug()<<"size of m_sql_query = "<<m_sql_query->size();//Not work !!!
     qDebug()<<"nb of column with record() = "<<m_sql_query->record().count();

    while(m_sql_query->next()){
        /*************************************************************************
         * "query.next()" set the current record.
         *
         * The index of the "query.value(...)" return the field of the command
         * "SELECT firstname, lastname FROM person".
         *
         * The filed are numbered from left (0) to right (1).
         *************************************************************************/

        m_modele_dict_1->setItem(m_dict_1_row,0,
                                 new QStandardItem(m_sql_query->value(0).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,1,
                                 new QStandardItem(m_sql_query->value(1).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,2,
                                 new QStandardItem(m_sql_query->value(2).toString()));
        m_dict_1_row++;

        qDebug()<<m_sql_query->value(0).toString()<<" : "<<m_sql_query->value(1).toString()<<
                  " : "<<m_sql_query->value(2).toString();
    }
}
//-------------------------------------------------------------------------------------------------

void MainWindow::add_sql_data(){
/*
 * !!! Put name of the table in sql database in QString variable !!!
 */
    QString word_english    = "";
    QString word_french     = "";
    QString date_s          = "";
    QString id_num_s        = "";
    QString query_s         = "insert into dictionary_1 values(";

    word_english    = ui_table_view_dict->line_edit_english->text();
    word_french     = ui_table_view_dict->line_edit_french->text();
    date_s          = ui_table_view_dict->line_edit_date->text();

    id_num_s        = QString::number(m_dict_1_row + 1);

//    query_s + id_num_s + ",'" + word_english + "','" + word_french + "','" + date_s + "')";
    query_s.append(id_num_s);
    query_s.append(",'");
    query_s.append(word_english);
    query_s.append("','");
    query_s.append(word_french);
    query_s.append("','");
    query_s.append(date_s);
    query_s.append("')");

    qDebug()<<"query_s = "<<query_s;
//    qDebug()<<"m_dict_1_row = "<<QString::number(m_dict_1_row);
//    qDebug()<<"line_edit_english = "<<ui_table_view_dict->line_edit_english->text();
//    m_sql_query->exec("insert into dictionary_1 values(5, 'purchase', 'achat', '28/08/2022')");
    //m_sql_query->exec("insert into dictionary_1 values(5, 'purchase', 'achat', '28/08/2022')");
    m_sql_query->exec(query_s);

    m_sql_query->exec("SELECT english, french, date FROM dictionary_1");

//    while(m_sql_query->next()){
        /*************************************************************************
         * "query.next()" set the current record.
         *
         * The index of the "query.value(...)" return the field of the command
         * "SELECT firstname, lastname FROM person".
         *
         * The filed are numbered from left (0) to right (1).
         *************************************************************************/
        m_sql_query->last();

        m_modele_dict_1->setItem(m_dict_1_row,0,
                                 new QStandardItem(m_sql_query->value(0).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,1,
                                 new QStandardItem(m_sql_query->value(1).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,2,
                                 new QStandardItem(m_sql_query->value(2).toString()));
        m_dict_1_row++;

        qDebug()<<m_sql_query->value(0).toString()<<" : "<<m_sql_query->value(1).toString()<<
                  " : "<<m_sql_query->value(2).toString();
//    }

}
//-------------------------------------------------------------------------------------------------

void MainWindow::window_popup_show(){
/*
 * Open a pop up window with random words every x ms.
 *
 * (0,0) : Top left on Windows 10
 */
    m_sql_row_count = 0;//Reset the variable.

    //Move the window to an X,Y integer position.
    QPoint point_popup;
    point_popup.setX(775);
    point_popup.setY(455);
    m_window_popup.move(point_popup);
    m_window_popup.setWindowState(Qt::WindowState::WindowActive);

    //sql query to select data in a table : --------------------------------------------------
    //Put "m_sql_db->open()" in a methode !!!
    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";

        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

    m_sql_query->exec("SELECT english, french, date FROM dictionary_1");

    //First, count the number of raw in the table :
    while(m_sql_query->next()){
        m_sql_row_count++;
    }

    m_random = QRandomGenerator::global()->bounded(m_sql_row_count - 1);
    //qDebug()<<"m_sql_row_count = "<<m_sql_row_count<<" ; m_random = "<<m_random;

    m_sql_row_count = 0;//Reset the variable for next count.

    m_sql_query->exec("SELECT english, french, date FROM dictionary_1");

    //Then, save datas in the random row.
    //Add words in a QStringList for a table with the words of the day :
    while(m_sql_query->next()){
        if(m_sql_row_count == m_random){
            m_window_popup.line_english_set_text(m_sql_query->value(0).toString());
            m_list_day.append(m_sql_query->value(0).toString());

            m_window_popup.line_french_set_text(m_sql_query->value(1).toString());
            m_list_day.append(m_sql_query->value(1).toString());

            m_nb_of_word++;//Count the number of word for each call of the methode.
        }

        m_sql_row_count++;
    }
    //----------------------------------------------------------------------------------------

    if(m_nb_of_word < 8){
       m_window_popup.show();
    }
    else{
        qDebug()<<"Show 8 words of the day in a table :";
        qDebug()<<"m_list_day : "<<m_list_day;

        m_nb_of_word = 0;//Rest.
    }

    m_timer_popup->start(5000);
    //m_timer_popup->stop();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::close_widget(){
/*
 *
 */
    m_window_popup.close();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::widget_test(){
    //qDebug()<<"widget_test";

    m_widget_1.setParent(NULL);//Remove parent.

    m_widget_3.hide();

    //Change the widget on the parent m_widget_3.
    m_widget_2.setParent(&m_widget_3);

    m_widget_3.show();
}
