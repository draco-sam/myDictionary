/**************************************************************************************************
 * Name of the project  : my_dictionary.
 *
 * Name of the creator  : Sam.
 * Date                 : 12/03/2023
 *
 * Description          :
 *
 * Remarks              :
 *
 * Improvements         :
 *  - List of dictionary on the left area of the main window.
 *  - Table view at the center of the main window.
 *  - Popup window show words of the day when mouse cross window.
 *
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
    m_modele_dict_1(0),m_model_dict_2(0),m_item_dictionary(0),m_item_1_1_dict(0),m_item_2_s(""),
    m_dict_1_row(0),m_dict_2_row(0),m_dict_1_row_last(0),m_dict_2_row_last(0),
    m_dict_1_column(0),m_sql_query(0),m_sql_db(0),m_sql_row_count(0),m_random(0),m_f_frequency(0),
    m_frequency(0),m_nb_of_word(0),m_timer_popup(0),m_repeat_popup_ms(5000),m_popup_f_first_time(0),
    m_timer_widget(0),m_table_view_1(NULL)
/*
 *
 */
{
    ui->setupUi(this);

    ui_popup->setupUi(&m_widget);


    //ui->menubar->hide();
    //ui->checkBox->toggled();

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

    m_item_dictionary = new QStandardItem("Dictionary_2");
    m_modele_dictionary->appendRow(m_item_dictionary);
    m_item_2_s = m_item_dictionary->index().data().toString();
    m_item_dictionary->appendRow(new QStandardItem("Dictionary_2.1"));

    m_item_2_2_dict         = new QStandardItem("Dictionary_2.2");
    m_item_dictionary->appendRow(m_item_2_2_dict);
    m_item_2_2_dict->appendRow(new QStandardItem("Dictionary_2.2.1"));
    m_item_2_2_s            = m_item_2_2_dict->index().data().toString();

    ui->treeView->setModel(m_modele_dictionary);
    //-------------------------------------------------------------------------

    //sql test : ----------------------------------------------------------------------------------
    m_sql_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    //m_sql_db->setDatabaseName("release/dictionary_1.db");
    m_sql_db->setDatabaseName("dictionary_1.db");

    m_sql_query = new QSqlQuery(*m_sql_db);
    //---------------------------------------------------------------------------------------------

    //Configure table view on the main window.
    config_table_dict_main_window();

    //First call of the pop up window with a timer :
    m_timer_popup = new QTimer(this);

    //Connection between objects : ---------------------------------------------------------------------
    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::menu_bar_show_hide);

    //Open a specific dictionary when we do a double click on any one items.
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::dict_item_double_clicked);

    connect(ui_table_view_dict->pb_add, &QPushButton::clicked, this, &MainWindow::add_sql_data);

    connect(ui->button_main_add, &QPushButton::clicked, this, &MainWindow::main_add_sql_data);

    connect(m_timer_popup, &QTimer::timeout, this, &MainWindow::window_popup_show);


    //--------------------------------------------------------------------------------------------------

    m_timer_popup->start(m_repeat_popup_ms);
}

MainWindow::~MainWindow()
{
    //qDebug()<<"!!! destructor !!!"<<m_window_popup.close();
    qDebug()<<"!!! destructor !!!";

    m_window_popup.close();

    //m_window_popup.hide();

    m_widget_dict_1.close();//??
    delete  m_modele_dictionary;
    delete  m_menu_right_click;

    delete ui_table_view_dict;
    delete  ui;
}

//-------------------------------------------------------------------------------------------------

void MainWindow::change_widget(){
/*
 *
 */
    m_widget_4.close();
    //m_layout_grid_4->removeWidget(&m_widget_3);
    //m_widget_3->hide();
    //delete m_widget_3;

    //delete m_widget_3;
    //m_layout_grid_4->addWidget(m_pb_3,0,1);
//    m_layout_grid_4->removeWidget(m_pb_1);
//    m_layout_grid_4->addWidget(m_pb_3,0,0);
//    m_widget_4.show();
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

    qDebug()<<"Double click on item = "<<index.data().toString();


    //Check if the string of the index is "Dictionary_2.2".
    //If yes, open another GUI.
    if(index.data().toString() == m_item_1_s){
        qDebug()<<"m_item_1_s = "<<m_item_1_s;

        sql_edit_table_view();
        m_widget_dict_1.show();
    }
    else if(index.data().toString() == m_item_2_s){
        qDebug()<<"m_item_2_s = "<<m_item_2_s;

        item_2_edit_table();
    }
    else if(index.data().toString() == m_item_2_2_s){
        m_widget.show();
    }


}
//-------------------------------------------------------------------------------------------------

void MainWindow::config_table_view_dict(){
/*
 * !!! old methode !!!
 * Tabe View dictionary that will contain words in a sql database.
 */
    ui_table_view_dict->setupUi(&m_widget_dict_1);
    m_widget_dict_1.setWindowState(Qt::WindowMaximized);

    QStringList horizontal_header_labels = {"English","Français","Family","Frequency","date"};

    m_modele_dict_1 = new QStandardItemModel(10,3);
    m_modele_dict_1->setHorizontalHeaderLabels(horizontal_header_labels);
    m_modele_dict_1->setItem(4,1, new QStandardItem("Sam dic 1"));

    ui_table_view_dict->tableView->setModel(m_modele_dict_1);
}
//-------------------------------------------------------------------------------------------------

void MainWindow::config_table_dict_main_window(){
/*
 * !!! New methode !!!
 * Tabe View dictionary that will contain words in the sql database.
 */
    QStringList horizontal_header_labels = {"English","Français","Family","Frequency","Visibility","Date"};

    m_model_dict_2 = new QStandardItemModel(10,6);//(lines, columns).
    m_model_dict_2->setHorizontalHeaderLabels(horizontal_header_labels);

    //Example to write in a cell.
    m_model_dict_2->setItem(4,1, new QStandardItem("Test to write"));

    ui->table_data_base->setModel(m_model_dict_2);

    //At start-up of the main window, edit directly the table.
    item_2_edit_table();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::item_2_edit_table(){
/*
 * On the main window, when double click on item 2, on the tree list, edit the table view
 * with sql data.
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

    m_sql_query->exec("SELECT english, french, family, frequency, visibility, date FROM dictionary_1");

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

        m_model_dict_2->setItem(m_dict_2_row,0,
                                 new QStandardItem(m_sql_query->value(0).toString()));
        m_model_dict_2->setItem(m_dict_2_row,1,
                                 new QStandardItem(m_sql_query->value(1).toString()));
        m_model_dict_2->setItem(m_dict_2_row,2,
                                 new QStandardItem(m_sql_query->value(2).toString()));
        m_model_dict_2->setItem(m_dict_2_row,3,
                                 new QStandardItem(m_sql_query->value(3).toString()));
        m_model_dict_2->setItem(m_dict_2_row,4,
                                 new QStandardItem(m_sql_query->value(4).toString()));
        m_model_dict_2->setItem(m_dict_2_row,5,
                                 new QStandardItem(m_sql_query->value(5).toString()));

        m_dict_2_row++;

//        qDebug()<<m_sql_query->value(0).toString()<<" : "<<m_sql_query->value(1).toString()<<
//                  " : "<<m_sql_query->value(2).toString()<<
//                  " : "<<m_sql_query->value(3).toString()<<
//                  " : "<<m_sql_query->value(4).toString();
    }

    //Add one empty row at the end (just row and QStandardItem parameter) : -------------
    m_model_dict_2->setItem(m_dict_2_row,new QStandardItem(""));

    uint8_t i_column = 0;

    //Set with empty string each column
    //otherwise, the code will crash when we click on main add button.
    for(i_column=0 ; i_column < 6 ; i_column++){
        m_model_dict_2->setItem(m_dict_2_row,i_column,new QStandardItem(""));
    }
    //-----------------------------------------------------------------------------------

    //Test to read text in a specific row and column.
    qDebug()<<"last row = "<<m_model_dict_2->item(m_dict_2_row - 1,0)->text();



    //m_dict_2_row++;//Not necessary ???

    m_dict_2_row_last = m_dict_2_row;
    m_dict_2_row = 0;//Reset for next open of the table view.

    m_sql_db->close();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::main_add_sql_data(){
/*
 *
 */
    QString id_num_s        = "";
    QString word_english    = "";
    QString word_french     = "";
    QString family_s        = "";
    uint8_t frequency       = 0;
    uint8_t visibility      = 1;//0 = do not display, 1 = display.
    QString date_s          = "";
    /*QString query_s         = "INSERT INTO dictionary_1 (id,english,french)"
                              "VALUE (?,?,?)";*/

    word_english    = m_model_dict_2->item(m_dict_2_row_last,0)->text();
    word_french     = m_model_dict_2->item(m_dict_2_row_last,1)->text();
    family_s        = m_model_dict_2->item(m_dict_2_row_last,2)->text();
    date_s          = m_model_dict_2->item(m_dict_2_row_last,5)->text();

    //Check if frequency or visibility fields are empty : --------------------------
    if(m_model_dict_2->item(m_dict_2_row_last,3)->text() == "")
    {
        frequency = 0;
    }
    else{
        frequency = m_model_dict_2->item(m_dict_2_row_last,3)->text().toInt();
    }

    if(m_model_dict_2->item(m_dict_2_row_last,4)->text() == ""){
        visibility = 1;
    }
    else{
        visibility = m_model_dict_2->item(m_dict_2_row_last,4)->text().toInt();
    }
    //-------------------------------------------------------------------------------

    if (!m_sql_db->open()) {
        qDebug()<<"Cannot open database";
    }

    m_sql_query->prepare("INSERT INTO dictionary_1 (id,english,french,family,frequency,visibility,date)"
                         "VALUES (?,?,?,?,?,?,?);");

    m_sql_query->addBindValue(m_dict_2_row_last + 1);
    m_sql_query->addBindValue(word_english);
    m_sql_query->addBindValue(word_french);
    m_sql_query->addBindValue(family_s);
    m_sql_query->addBindValue(frequency);
    m_sql_query->addBindValue(visibility);
    m_sql_query->addBindValue(date_s);

    if(!m_sql_query->exec()){
        qDebug()<<" adding new value in data base with exec() NOK";
    }
    else{
        qDebug()<<"exec() : OK";
    }

    //Add one empty row at the end (just row and QStandardItem parameter) :
    m_dict_2_row_last++;
    m_model_dict_2->setItem(m_dict_2_row_last,new QStandardItem(""));
}

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

    m_sql_query->exec("SELECT english, french, family, frequency,date FROM dictionary_1");

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
        m_modele_dict_1->setItem(m_dict_1_row,3,
                                 new QStandardItem(m_sql_query->value(3).toString()));
        m_modele_dict_1->setItem(m_dict_1_row,4,
                                 new QStandardItem(m_sql_query->value(4).toString()));

        m_dict_1_row++;

        qDebug()<<m_sql_query->value(0).toString()<<" : "<<m_sql_query->value(1).toString()<<
                  " : "<<m_sql_query->value(2).toString()<<
                  " : "<<m_sql_query->value(3).toString()<<
                  " : "<<m_sql_query->value(4).toString();
    }
    m_dict_1_row_last = m_dict_1_row;
    m_dict_1_row = 0;//Reset for next open of the table view.
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

    id_num_s        = QString::number(m_dict_1_row_last + 1);

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

        m_modele_dict_1->setItem(m_dict_1_row_last,0,
                                 new QStandardItem(m_sql_query->value(0).toString()));
        m_modele_dict_1->setItem(m_dict_1_row_last,1,
                                 new QStandardItem(m_sql_query->value(1).toString()));
        m_modele_dict_1->setItem(m_dict_1_row_last,2,
                                 new QStandardItem(m_sql_query->value(2).toString()));
        m_dict_1_row_last++;

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
    QString path = "";

    //Move the window to an X,Y integer position.
    QPoint point_popup;
    point_popup.setX(650);//old : 950.
    point_popup.setY(150);//old : 455.
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

    //First, count the number of raw in the table : ------------
    //Need just one column label.
    m_sql_query->exec("SELECT id FROM dictionary_1");

    while(m_sql_query->next()){
        m_sql_row_count++;
    }
    //----------------------------------------------------------

    m_random = QRandomGenerator::global()->bounded(m_sql_row_count - 1);
    //qDebug()<<"m_sql_row_count = "<<m_sql_row_count<<" ; m_random = "<<m_random;

    m_sql_row_count = 0;//Reset the variable for next count.

    m_sql_query->exec("SELECT english, french, frequency, image FROM dictionary_1");

    //Then, save datas in the random row.
    //Add words in a QStringList for a table with the words of the day :
    while(m_sql_query->next()){
        if(m_sql_row_count == m_random){
            m_window_popup.line_english_set_text(m_sql_query->value(0).toString());
            m_list_day.append(m_sql_query->value(0).toString());

            m_window_popup.line_french_set_text(m_sql_query->value(1).toString());
            m_list_day.append(m_sql_query->value(1).toString());

            m_window_popup.line_frequency_set_text("Frequency : " + m_sql_query->value(2).toString());
            m_frequency = m_sql_query->value(2).toInt();//Save the number of the frequency.

            path = m_sql_query->value(3).toString();

            m_nb_of_word++;//Count the number of word for each call of the methode.
        }

        m_sql_row_count++;
    }
    //----------------------------------------------------------------------------------------

    if(m_nb_of_word < 30){
        //m_window_popup.set_label_image("Images/workshop_03.jpg");
        m_window_popup.set_label_image(path);
        m_window_popup.show();
    }
    else{
        qDebug()<<"Show 8 words of the day in a table :";
        qDebug()<<"m_list_day : "<<m_list_day;

        m_nb_of_word = 0;//Rest.
    }

    //show one time words with low frequency : ------------------------------------------
    //and another time with high frequency
    if(m_f_frequency == 0){// ok if <= 5.
        if(m_frequency >= 6){// nok.
            set_time_repeat_popup(100);//Resart timer because wrong frequency number.
        }
        else{// <=5 : ok, set the flag only if right frequency number.
            m_f_frequency = 1;//Set flag.
            set_time_repeat_popup(900e3);//15 min.
        }
    }
    else{//m_f_frequency = 1.
        if(m_frequency <= 5){//nok.
            set_time_repeat_popup(100);//Resart timer because wrong frequency number.
        }
        else{//ok.
            m_f_frequency = 0;//Reset flag.
            set_time_repeat_popup(900e3);//15 min.
        }
    }
    //-----------------------------------------------------------------------------------





    //Change the repeat time after the 1st appearance : --------
    if(m_popup_f_first_time == 0){
        set_time_repeat_popup(900e3);//900e3 : 15 min.
        m_popup_f_first_time = 1;
    }
    m_timer_popup->start(m_repeat_popup_ms);
//    else{
//        m_timer_popup->start(m_repeat_popup_ms);
//        //m_timer_popup->stop();
//    }
    //----------------------------------------------------------
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

    //m_widget_1.setParent(NULL);//Remove parent.

//    m_widget_3.hide();

//    //Change the widget on the parent m_widget_3.
//    m_widget_1.setParent(NULL);
//    m_widget_2.setParent(&m_widget_3);

//    m_timer_widget->stop();

//    m_widget_3.show();
}
//-------------------------------------------------------------------------------------------------

void MainWindow::creat_widget_1(){
/*
 *
 */
//    QGridLayout *m_layout_grid_1 = new QGridLayout;
//    m_layout_grid_1->addWidget(&m_table_view_1,0,0);

//    m_widget_1.setLayout(m_layout_grid_1);

//    m_widget_1.setParent(&m_widget_3);

    //m_table_view_1.setParent(&m_widget_3);
}
//-------------------------------------------------------------------------------------------------

void MainWindow::creat_widget_2(){
/*
 *
 */

    m_line_1.setText("line_1");
    m_line_2.setText("line_2");

    QGridLayout *m_layout_grid_2 = new QGridLayout;

    m_layout_grid_2->addWidget(&m_line_1,0,0);
    m_layout_grid_2->addWidget(&m_line_2,1,0);

    m_widget_2.setLayout(m_layout_grid_2);

}
//-------------------------------------------------------------------------------------------------

void MainWindow::set_time_repeat_popup(uint32_t time_ms){
/*
 * Set the time to repeat the appearance of the popup window.
 */
    m_repeat_popup_ms = time_ms;

    //m_timer_popup->stop();
    m_timer_popup->start(m_repeat_popup_ms);

}
//-------------------------------------------------------------------------------------------------
