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
 *
 *************************************************************************************************/

#include "windowpopup.h"
#include "ui_windowpopup.h"

WindowPopUp::WindowPopUp(QWidget *parent) : QWidget(parent),
    ui(new Ui::WindowPopUp),m_pix("Images/workshop.jpg"),m_line_french_is_selected(0),
    m_line_english_is_selected(0),m_list_clear_line_counter(0),m_repeat_popup_ms(5000),m_popup_timer(0),
    m_english_s(""),m_english_visibility_s("1"),m_french_s(""),m_french_visibility_s("1")
{
    ui->setupUi(this);

//    //qDebug()<<"load = "<<pix.load("Images/workshop.jpg");
//    m_pix = m_pix.scaled(ui->label_image->size(),Qt::KeepAspectRatio);

//    //ui->label_image->setPixmap(QPixmap("Images/workshop.jpg"));

//    //Image on directory :
//    //build-my_dictionary-Desktop_Qt_6_2_4_MinGW_64_bit-Release\Images
//    ui->label_image->setPixmap(m_pix);

    ui->label_image->setAlignment(Qt::AlignCenter);

    //Hide plain text at start-up.
    //Show only after x words.
    ui->plain_text->hide();

    //Move the lower left corner of the window popup at a specific (x,y) coordinate.
    move(20,150);//old (650,150).

    //!!! Start the timer when the "m_list_day" is set !!!
    m_popup_timer = new QTimer(this);
    //m_popup_timer->start(3000);

    //Connection between objects :
    connect(ui->line_french, &QLineEdit::selectionChanged, this, &WindowPopUp::line_french_selected);
    connect(ui->line_english, &QLineEdit::selectionChanged, this, &WindowPopUp::line_english_selected);
    connect(ui->line_french, &QLineEdit::returnPressed, this, &WindowPopUp::line_french_enter_pressed);
    connect(ui->line_english, &QLineEdit::returnPressed, this, &WindowPopUp::line_english_enter_pressed);
    connect(m_popup_timer, &QTimer::timeout, this, &WindowPopUp::window_show);


}
//-------------------------------------------------------------------------------------------------

WindowPopUp::~WindowPopUp()
{
    delete ui;
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_english_set_text(QString text){
/*
 *
 */
    ui->line_english->setText(text);
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_french_set_text(QString text){
/*
 *
 */
    ui->line_french->setText(text);
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_frequency_set_text(QString text){
/*
 *
 */
    ui->line_frequency->setText(text);
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::set_label_english(QString text){
/*
 *
 */
    ui->label_english->setText(text);
     ui->label_english->setAlignment(Qt::AlignCenter);
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::set_label_image(QString path){
/*
 * Directory of the images :
 * build-my_dictionary-Desktop_Qt_6_2_4_MinGW_64_bit-Release\Images
 */
    m_pix = path;
    //m_pix = m_pix.scaled(ui->label_image->size(),Qt::KeepAspectRatio);

    if(m_pix.load(path) == true){
        ui->label_image->setPixmap(m_pix);
    }
    else{
        ui->label_image->setText("No image");
    }


}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::plain_text_show_hide(uint8_t show_hide){
/*
 * Methode to show or hide the plain text on the pop up window.
 */
    if(show_hide == PLAIN_TEXT_SHOW){
        ui->plain_text->show();
    }
    else if(show_hide == PLAIN_TEXT_HIDE){
        ui->plain_text->hide();
    }
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::plain_add_text(QString text){
/*
 *
 */
    ui->plain_text->appendPlainText(text);
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_french_selected(){
/*
 * Tis slot is called when the signal "void QLineEdit::selectionChanged()" is emitted.
 *
 * We need to double click en the QlineEdit to emitted the signal.
 */
    line_french_set_text(m_french_s);

    qDebug()<<"line_french_selected()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_french_enter_pressed(){
 /*
 * Tis slot is called when the signal "..." is emitted.
 *
 * We need to select (one click, not double click) the QLineEdit and then push to ENTER.
 */
    line_french_set_text(m_french_s);
    qDebug()<<"line_french_enter_pressed()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_english_selected(){
/*
 * Tis slot is called when the signal "void QLineEdit::selectionChanged()" is emitted.
 *
 * We need to double click en the QlineEdit to emitted the signal.
 */
    line_english_set_text(m_english_s);
    qDebug()<<"line_english_selected()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_english_enter_pressed(){
    /*
 * Tis slot is called when the signal "..." is emitted.
 *
 * We need to select (one click, not double click) the QLineEdit and then push to ENTER.
 */
    line_english_set_text(m_english_s);
    qDebug()<<"line_english_enter_pressed()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::set_list_day(ListData list){
/*
 * Copy the structure "ListData" with a QStringList table and the size of the table
 * on the member variable of the class.
 */

    m_list_day = list;
    m_list_day_temporary = list;

    m_popup_timer->start(m_repeat_popup_ms);//3000;

    qDebug()<<"m_list_data = "<<m_list_day.table[0];
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::window_show(){
/*
 *
 */
    uint8_t     sql_line_random = 0;
    uint8_t     sql_line_max    = 0;
    uint16_t    table_list_max  = 0;
    uint16_t    i_for           = 0;
    QStringList string_list;
    QStringList table_list[50];

    close();

    set_time_repeat_popup(900e3);//15 min <-> 900 000 ms.

    sql_line_max = m_list_day.size;

    //Add on "table_list" only data that is not empty : -----------------------
    //from "m_list_day_temporary"
    for(i_for = 0 ; i_for <sql_line_max ; i_for++){
        if(m_list_day_temporary.table[i_for].isEmpty() == false){
            table_list[table_list_max] = m_list_day_temporary.table[i_for];
            table_list_max++;
        }
    }
    //-------------------------------------------------------------------------

    sql_line_random = QRandomGenerator::global()->bounded(table_list_max - 1);

    string_list = table_list[sql_line_random];

    //Edit the window popup en save data in the object : -----------------
    m_english_visibility_s = string_list[9];
    if(m_english_visibility_s == "1"){
        line_english_set_text(string_list[1]);
        set_label_english(string_list[1]);
    }
    else{
        line_english_set_text("");
        set_label_english("");
    }
    m_english_s = string_list[1];

    m_french_visibility_s = string_list[10];
    if(m_french_visibility_s == "1"){
        line_french_set_text(string_list[2]);
    }
    else{
        line_french_set_text("");
    }
    m_french_s = string_list[2];

    line_frequency_set_text("Frequency : " + string_list[4]);
    set_label_image(string_list[6]);//??? ok ???
    //--------------------------------------------------------------------

    //Browse the "m_list_day_temporary" : -----------------------------------------------
    //and clear the QStringList than the random one on "table_list".
    //Check the id number for comparison.
    for(i_for = 0 ; i_for <sql_line_max ; i_for++){
        if(m_list_day_temporary.table[i_for][0] == table_list[sql_line_random][0]){
            m_list_day_temporary.table[i_for].clear();
            m_list_clear_line_counter++;
        }
    }
    //-----------------------------------------------------------------------------------

    //Add words on plain text and show after x words : --------------
    plain_add_text(string_list[1] + " : " + string_list[2]);

    if(m_list_clear_line_counter >= 10){
        plain_text_show_hide(PLAIN_TEXT_SHOW);
    }
    //---------------------------------------------------------------

    //Copy again the "m_list_day" on temporary list : ---------------
    if(m_list_clear_line_counter >= sql_line_max){
        m_list_day_temporary = m_list_day;
        m_list_clear_line_counter = 0;//Reset.
        qDebug()<<"copy m_list_day into m_list_day_temporary";
    }
    //---------------------------------------------------------------

    string_list.clear();

    show();
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::set_time_repeat_popup(uint32_t time_ms){
    /*
 * !!! To delete !!!
 *
 * Set the time to repeat the appearance of the popup window.
 */
    m_repeat_popup_ms = time_ms;

    m_popup_timer->stop();
    m_popup_timer->start(m_repeat_popup_ms);

}
//-------------------------------------------------------------------------------------------------
