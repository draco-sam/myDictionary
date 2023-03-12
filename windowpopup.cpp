#include "windowpopup.h"
#include "ui_windowpopup.h"

WindowPopUp::WindowPopUp(QWidget *parent) : QWidget(parent),
    ui(new Ui::WindowPopUp),m_pix("Images/workshop.jpg")
{
    ui->setupUi(this);

    //qDebug()<<"load = "<<pix.load("Images/workshop.jpg");
    m_pix = m_pix.scaled(ui->label_image->size(),Qt::KeepAspectRatio);

    //ui->label_image->setPixmap(QPixmap("Images/workshop.jpg"));

    //Image on directory :
    //build-my_dictionary-Desktop_Qt_6_2_4_MinGW_64_bit-Release\Images
    ui->label_image->setPixmap(m_pix);
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

void WindowPopUp::set_label_image(QString path){
/*
 *
 */
    m_pix = path;
    m_pix = m_pix.scaled(ui->label_image->size(),Qt::KeepAspectRatio);
    ui->label_image->setPixmap(m_pix);
}
//-------------------------------------------------------------------------------------------------

