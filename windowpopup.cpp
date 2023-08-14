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
    m_line_english_is_selected(0),m_popup_timer(0)
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
    qDebug()<<"line_french_selected()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_english_selected(){
/*
 * Tis slot is called when the signal "void QLineEdit::selectionChanged()" is emitted.
 *
 * We need to double click en the QlineEdit to emitted the signal.
 */
    qDebug()<<"line_english_selected()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::line_french_enter_pressed(){
/*
 * Tis slot is called when the signal "..." is emitted.
 *
 * We need to select (one click, not double click) the QLineEdit and then push to ENTER.
 */
    qDebug()<<"line_french_enter_pressed()";
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::set_list_day(ListData list){
/*
 * Copy the structure "ListData" with a QStringList table and the size of the table
 * on the member variable of the class.
 */

    m_list_day = list;

    m_popup_timer->start(5000);

    qDebug()<<"m_list_data = "<<m_list_day.table[0];
}
//-------------------------------------------------------------------------------------------------

void WindowPopUp::window_show(){
/*
 *
 */
    uint8_t     sql_line_random = 0;
    uint8_t     sql_line_max    = 0;
    QStringList string_list;

    //1)Random number.
    //2)Enlever la QStringList du tableau original.
    //3)Mettre cette liste dans une autre variable pour quand tout sera fini.
    //4)Chercher les infos pour editer les champs dans la popup.

    close();

    sql_line_max = m_list_day.size;

    sql_line_random = QRandomGenerator::global()->bounded(sql_line_max - 1);

    string_list = m_list_day.table[sql_line_random];

    line_english_set_text(string_list[1]);
    line_french_set_text(string_list[2]);
    line_frequency_set_text("Frequency : " + string_list[4]);
    set_label_english(string_list[1]);
    set_label_image(string_list[6]);//??? ok ???

    //...
    string_list.clear();

    show();
}
