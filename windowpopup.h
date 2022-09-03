#ifndef WINDOWPOPUP_H
#define WINDOWPOPUP_H

#include <QWidget>

namespace Ui {
class WindowPopUp;
}

class WindowPopUp : public QWidget
{
    Q_OBJECT

public:
    explicit WindowPopUp(QWidget *parent = nullptr);
    ~WindowPopUp();

private:
    Ui::WindowPopUp *ui;
};

#endif // WINDOWPOPUP_H
