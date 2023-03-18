#include "windowpopup.h"
#include "ui_windowpopup.h"

WindowPopUp::WindowPopUp(QWidget *parent) : QWidget(parent),
    ui(new Ui::WindowPopUp),m_pix("Images/workshop.jpg")
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
