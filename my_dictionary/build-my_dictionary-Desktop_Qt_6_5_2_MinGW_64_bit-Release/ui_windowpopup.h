/********************************************************************************
** Form generated from reading UI file 'windowpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWPOPUP_H
#define UI_WINDOWPOPUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowPopUp
{
public:
    QAction *actiontest;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *h_layout_tool;
    QSpacerItem *h_spacer_tool;
    QToolButton *tool_configure;
    QSpacerItem *verticalSpacer;
    QLabel *label_english;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_image;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *line_frequency;
    QLineEdit *line_english;
    QLineEdit *line_french;
    QPlainTextEdit *plain_text;

    void setupUi(QWidget *WindowPopUp)
    {
        if (WindowPopUp->objectName().isEmpty())
            WindowPopUp->setObjectName("WindowPopUp");
        WindowPopUp->setEnabled(true);
        WindowPopUp->resize(600, 500);
        WindowPopUp->setMinimumSize(QSize(200, 100));
        WindowPopUp->setMaximumSize(QSize(600, 500));
        WindowPopUp->setStyleSheet(QString::fromUtf8(""));
        actiontest = new QAction(WindowPopUp);
        actiontest->setObjectName("actiontest");
        verticalLayout = new QVBoxLayout(WindowPopUp);
        verticalLayout->setObjectName("verticalLayout");
        h_layout_tool = new QHBoxLayout();
        h_layout_tool->setObjectName("h_layout_tool");
        h_spacer_tool = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_tool->addItem(h_spacer_tool);

        tool_configure = new QToolButton(WindowPopUp);
        tool_configure->setObjectName("tool_configure");
        tool_configure->setMaximumSize(QSize(200, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../00_Documentation/Icons/roue_01.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_configure->setIcon(icon);

        h_layout_tool->addWidget(tool_configure);


        verticalLayout->addLayout(h_layout_tool);

        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_english = new QLabel(WindowPopUp);
        label_english->setObjectName("label_english");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_english->setFont(font);

        verticalLayout->addWidget(label_english);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_image = new QLabel(WindowPopUp);
        label_image->setObjectName("label_image");
        label_image->setMinimumSize(QSize(500, 250));

        horizontalLayout->addWidget(label_image);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(10, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(WindowPopUp);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        line_frequency = new QLineEdit(WindowPopUp);
        line_frequency->setObjectName("line_frequency");
        line_frequency->setReadOnly(true);

        gridLayout->addWidget(line_frequency, 1, 0, 1, 1);

        line_english = new QLineEdit(WindowPopUp);
        line_english->setObjectName("line_english");
        line_english->setMinimumSize(QSize(100, 0));
        line_english->setReadOnly(true);

        gridLayout->addWidget(line_english, 0, 0, 1, 1);

        line_french = new QLineEdit(WindowPopUp);
        line_french->setObjectName("line_french");
        line_french->setEnabled(true);
        line_french->setMinimumSize(QSize(100, 0));
        line_french->setMouseTracking(false);
        line_french->setReadOnly(true);

        gridLayout->addWidget(line_french, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        plain_text = new QPlainTextEdit(WindowPopUp);
        plain_text->setObjectName("plain_text");

        verticalLayout->addWidget(plain_text);


        retranslateUi(WindowPopUp);

        QMetaObject::connectSlotsByName(WindowPopUp);
    } // setupUi

    void retranslateUi(QWidget *WindowPopUp)
    {
        WindowPopUp->setWindowTitle(QCoreApplication::translate("WindowPopUp", "Form", nullptr));
        actiontest->setText(QCoreApplication::translate("WindowPopUp", "test", nullptr));
        tool_configure->setText(QCoreApplication::translate("WindowPopUp", "t", nullptr));
        label_english->setText(QCoreApplication::translate("WindowPopUp", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        label_image->setText(QCoreApplication::translate("WindowPopUp", "<html><head/><body><p><br/></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowPopUp", "Show", nullptr));
        plain_text->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowPopUp: public Ui_WindowPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWPOPUP_H
