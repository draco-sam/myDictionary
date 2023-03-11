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
    void line_english_set_text(QString text);
    void line_french_set_text(QString text);
    void line_frequency_set_text(QString text);

private:
    Ui::WindowPopUp *ui;
};

#endif // WINDOWPOPUP_H
