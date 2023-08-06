#ifndef WINDOWPOPUP_H
#define WINDOWPOPUP_H

#include <QWidget>
#include <QPixmap>


#define PLAIN_TEXT_HIDE 0
#define PLAIN_TEXT_SHOW 1

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
        void set_label_english(QString text);
        void set_label_image(QString path);
        void plain_text_show_hide(uint8_t show_hide);
        void plain_add_text(QString text);

    public slots:
        void line_french_selected();
        void line_english_selected();
        void line_french_enter_pressed();

    private:
        Ui::WindowPopUp     *ui;
        QPixmap             m_pix;
        uint8_t             m_line_french_is_selected;
        uint8_t             m_line_english_is_selected;
};

#endif // WINDOWPOPUP_H
