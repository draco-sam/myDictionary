/**************************************************************************************************
 * Name of the project  : my_dictionary.
 *
 * Name of the creator  : Sam.
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


//MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow),ui_table_view_dict(new Ui::Table_view_dict),

    m_menu_right_click(0), m_modele_dictionary(0),
    m_modele_dict_1(0),m_model_dict_2(0),m_item_dictionary(0),m_item_1_1_dict(0),m_item_2_s(""),
    m_dict_1_row(0),m_dict_2_row(0),m_dict_1_row_last(0),m_dict_2_row_last(0),
    m_dict_1_column(0),m_sql_row_count(0),m_random(0),m_f_frequency(0),
    m_frequency(0),m_frequency_s(""),m_word_english(""),m_word_french(""),m_word_same_f(0),
    m_word_same_counter(0),m_nb_of_word(0),
    m_popup_f_first_time(0),m_popup_f_show(0),m_timer_widget(0),m_table_view_1(NULL),m_time(),
    m_table_main_column_size(10)
/*
 *
 */
{
    ui->setupUi(this);


    //ui->menubar->hide();
    //ui->checkBox->toggled();

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

    //Configure table view on the main window.
    config_table_dict_main_window();

    //Connection between objects : ---------------------------------------------------------------------
    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::menu_bar_show_hide);

    //Open a specific dictionary when we do a double click on any one items.
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::dict_item_double_clicked);

    //!!! this connection crash the software (05/08/2023) !!!
    //connect(ui_table_view_dict->pb_add, &QPushButton::clicked, this, &MainWindow::add_sql_data);

    //connect(m_timer_popup, &QTimer::timeout, this, &MainWindow::window_popup_show);
    //--------------------------------------------------------------------------------------------------

    //Test to get the time of the system : -----------
    m_time = m_time.currentTime();

    qDebug()<<"time = "<<m_time.currentTime();
    qDebug()<<"hour = "<<m_time.hour();
    //------------------------------------------------

}

MainWindow::~MainWindow()
{
    //qDebug()<<"!!! destructor !!!"<<m_window_popup.close();
    qDebug()<<"!!! destructor !!!";

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
 * Only for test ???
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

        //sql_edit_table_view();
        //m_widget_dict_1.show();
    }
    else if(index.data().toString() == m_item_2_s){
        qDebug()<<"m_item_2_s = "<<m_item_2_s;

        //!!! Modification of this function (07/08/2023) !!!
        //item_2_edit_table();
    }
    else if(index.data().toString() == m_item_2_2_s){
        //m_widget.show();
    }
}
//-------------------------------------------------------------------------------------------------

void MainWindow::config_table_dict_main_window(){
/*
 * !!! New methode !!!
 * Tabe View dictionary that will contain words in the sql database.
 */
    QStringList horizontal_header_labels = {"English","French","Family","Frequency","Date",
        "Image","Syllable","Sentence","Visibility English","Visibility French"};

    m_model_dict_2 = new QStandardItemModel(10,10);//(lines, columns).
    m_model_dict_2->setHorizontalHeaderLabels(horizontal_header_labels);

    //Example to write in a cell.
    m_model_dict_2->setItem(4,1, new QStandardItem("Test to write"));

    ui->table_data_base->setModel(m_model_dict_2);
}
//-------------------------------------------------------------------------------------------------

void MainWindow::table_edit_all_data(QStringList list){
/*
 * On the main window, edit the table with all SQL data.
 *
 * Improvement : - "m_dict_2_row" can be local ?
 *
 */
    uint8_t     i_column            = 0;
    uint16_t    i_list              = 0;
    uint16_t    position_of_id_data = 0;

    //qDebug()<<"list = "<<list;

    //Edit each cell of the table : -----------------------------------------------------
    for(i_list = 0 ; i_list < list.size() ; i_list++){
        //Check if the data is not the id because we don't want to put it on the table.
        //The id can be used on the popup window with random number.
        if(i_list != position_of_id_data){
            m_model_dict_2->setItem(m_dict_2_row,i_column,new QStandardItem(list[i_list]));
            i_column++;
        }
        else{
            position_of_id_data = position_of_id_data + m_table_main_column_size + 1;
        }

        if(i_column >= m_table_main_column_size){
            i_column = 0;//Reset.
            m_dict_2_row++;//Next edition of the row on the table.
        }
    }
    //-----------------------------------------------------------------------------------

    //Add one empty row at the end (just row and QStandardItem parameter) : -------------
    m_model_dict_2->setItem(m_dict_2_row,new QStandardItem(""));

    //uint8_t i_column = 0;
    i_column = 0;

    //Set with empty string each column
    //otherwise, the code will crash when we click on main add button.
    //for(i_column=0 ; i_column < 6 ; i_column++){
    for(i_column=0 ; i_column < m_table_main_column_size ; i_column++){
        m_model_dict_2->setItem(m_dict_2_row,i_column,new QStandardItem(""));
    }
    //-----------------------------------------------------------------------------------

    //Test to read text in a specific row and column.
    //qDebug()<<"last row = "<<m_model_dict_2->item(m_dict_2_row - 1,0)->text();

    m_dict_2_row_last = m_dict_2_row;

    //still used ???
    m_dict_2_row = 0;//Reset for next open of the table view.
}
//-------------------------------------------------------------------------------------------------

void MainWindow::table_edit(ListData list_data){
/*
 * On the main window, edit the table with SQL data.
 *
 * Input parameter :
 *      - Structure "ListData" with a table that contains QStringList and the size of the table.
 *
 * Improvement : - "m_dict_2_row" can be local ?
 *
 */
    uint8_t     i_column            = 0;
    uint16_t    i_string_list     = 0;
    uint16_t    i_list              = 0;
    QStringList list;

    //Extract each cell of the table that contains QStringList : ----------------------------------
    for(i_string_list = 0 ; i_string_list < list_data.size ; i_string_list++){
        list.append(list_data.table[i_string_list]);

        //Navigate in to the QStringList to extract useful data.
        //The id number of the SQL data is not useful so, we start at 1 :
        for(i_list = 1 ; i_list < list.size() ; i_list++){
            m_model_dict_2->setItem(m_dict_2_row,i_column,new QStandardItem(list[i_list]));
            i_column++;

            if(i_column >= m_table_main_column_size){
                i_column = 0;//Reset.
                m_dict_2_row++;//Next edition of the row on the table.
            }
        }

        list.clear();
    }
    //---------------------------------------------------------------------------------------------

    //Add one empty row at the end (just row and QStandardItem parameter) : -------------
    m_model_dict_2->setItem(m_dict_2_row,new QStandardItem(""));

    i_column = 0;

    //Set with empty string each column
    //otherwise, the code will crash when we click on main add button.
    for(i_column=0 ; i_column < m_table_main_column_size ; i_column++){
        m_model_dict_2->setItem(m_dict_2_row,i_column,new QStandardItem(""));
    }
    //-----------------------------------------------------------------------------------

    //Test to read text in a specific row and column.
    //qDebug()<<"last row = "<<m_model_dict_2->item(m_dict_2_row - 1,0)->text();

    m_dict_2_row_last = m_dict_2_row;

    //still used ???
    m_dict_2_row = 0;//Reset for next open of the table view.

}
//-------------------------------------------------------------------------------------------------

//void MainWindow::add_sql_data(){
///*
// * !!! Put name of the table in sql database in QString variable !!!
// */
//    QString word_english    = "";
//    QString word_french     = "";
//    QString date_s          = "";
//    QString id_num_s        = "";
//    QString query_s         = "insert into dictionary_1 values(";

//    word_english    = ui_table_view_dict->line_edit_english->text();
//    word_french     = ui_table_view_dict->line_edit_french->text();
//    date_s          = ui_table_view_dict->line_edit_date->text();

//    id_num_s        = QString::number(m_dict_1_row_last + 1);

////    query_s + id_num_s + ",'" + word_english + "','" + word_french + "','" + date_s + "')";
//    query_s.append(id_num_s);
//    query_s.append(",'");
//    query_s.append(word_english);
//    query_s.append("','");
//    query_s.append(word_french);
//    query_s.append("','");
//    query_s.append(date_s);
//    query_s.append("')");

//    qDebug()<<"query_s = "<<query_s;
////    qDebug()<<"m_dict_1_row = "<<QString::number(m_dict_1_row);
////    qDebug()<<"line_edit_english = "<<ui_table_view_dict->line_edit_english->text();
////    m_sql_query->exec("insert into dictionary_1 values(5, 'purchase', 'achat', '28/08/2022')");
//    //m_sql_query->exec("insert into dictionary_1 values(5, 'purchase', 'achat', '28/08/2022')");
//    m_sql_query->exec(query_s);

//    m_sql_query->exec("SELECT english, french, date FROM dictionary_1");

////    while(m_sql_query->next()){
//        /*************************************************************************
//         * "query.next()" set the current record.
//         *
//         * The index of the "query.value(...)" return the field of the command
//         * "SELECT firstname, lastname FROM person".
//         *
//         * The filed are numbered from left (0) to right (1).
//         *************************************************************************/
//        m_sql_query->last();

//        m_modele_dict_1->setItem(m_dict_1_row_last,0,
//                                 new QStandardItem(m_sql_query->value(0).toString()));
//        m_modele_dict_1->setItem(m_dict_1_row_last,1,
//                                 new QStandardItem(m_sql_query->value(1).toString()));
//        m_modele_dict_1->setItem(m_dict_1_row_last,2,
//                                 new QStandardItem(m_sql_query->value(2).toString()));
//        m_dict_1_row_last++;

//        qDebug()<<m_sql_query->value(0).toString()<<" : "<<m_sql_query->value(1).toString()<<
//                  " : "<<m_sql_query->value(2).toString();
////    }

//}
////-------------------------------------------------------------------------------------------------

void MainWindow::close_widget(){
/*
 *
 */

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

void MainWindow::receive_string_list(QStringList list){qDebug()<<"receive_string_list";
/*
 *
 */
    uint16_t i_for = 0;

    qDebug()<<"MainWindow::receive_string_list(...)";

    for(i_for = 0; i_for < list.size(); i_for++){
        qDebug()<<i_for<<" : "<<list[i_for];
    }

    //list.size();
}
//-------------------------------------------------------------------------------------------------


