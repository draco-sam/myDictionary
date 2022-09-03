#include "windowpopup.h"
#include "ui_windowpopup.h"

WindowPopUp::WindowPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowPopUp)
{
    ui->setupUi(this);
}

WindowPopUp::~WindowPopUp()
{
    delete ui;
}
