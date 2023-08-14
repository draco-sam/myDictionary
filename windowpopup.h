#ifndef WINDOWPOPUP_H
#define WINDOWPOPUP_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QRandomGenerator>
#include "list_data_struct.h"

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
        void set_list_day(ListData list);

    public slots:
        void line_french_selected();
        void line_english_selected();
        void line_french_enter_pressed();
        void window_show();

    private:
        Ui::WindowPopUp     *ui;
        QPixmap             m_pix;
        uint8_t             m_line_french_is_selected;
        uint8_t             m_line_english_is_selected;
        uint16_t            m_list_clear_line_counter;
        QTimer              *m_popup_timer;
        ListData            m_list_day;
        ListData            m_list_day_temporary;
};

#endif // WINDOWPOPUP_H
