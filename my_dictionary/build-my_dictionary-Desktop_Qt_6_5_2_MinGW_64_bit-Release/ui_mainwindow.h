/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTest;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QTableView *table_data_base;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_main_add;
    QPushButton *button_main_delete;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdition;
    QMenu *menuView;
    QMenu *menuConfiguration;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(818, 597);
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName("actionTest");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("accessories-calculator");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("C:/Users/Draco/Pictures/MrDA6V3V_400x400.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setEnabled(true);
        treeView->setMaximumSize(QSize(150, 16777215));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setAutoExpandDelay(-1);
        treeView->setRootIsDecorated(true);
        treeView->setAnimated(true);
        treeView->setAllColumnsShowFocus(false);
        treeView->setHeaderHidden(true);
        treeView->setExpandsOnDoubleClick(true);

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        table_data_base = new QTableView(centralwidget);
        table_data_base->setObjectName("table_data_base");

        gridLayout->addWidget(table_data_base, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        button_main_add = new QPushButton(centralwidget);
        button_main_add->setObjectName("button_main_add");
        QFont font;
        font.setBold(false);
        button_main_add->setFont(font);

        horizontalLayout->addWidget(button_main_add);

        button_main_delete = new QPushButton(centralwidget);
        button_main_delete->setObjectName("button_main_delete");

        horizontalLayout->addWidget(button_main_delete);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 818, 30));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName("menuEdition");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuConfiguration = new QMenu(menubar);
        menuConfiguration->setObjectName("menuConfiguration");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName("dockWidget_2");
        dockWidget_2->setEnabled(true);
        dockWidget_2->setMinimumSize(QSize(185, 180));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("accessories-calculator");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        dockWidget_2->setWindowIcon(icon1);
        dockWidget_2->setAutoFillBackground(false);
        dockWidget_2->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName("dockWidgetContents_2");
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        checkBox = new QCheckBox(dockWidgetContents_2);
        checkBox->setObjectName("checkBox");
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        pushButton_2 = new QPushButton(dockWidgetContents_2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dockWidgetContents_2);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget_2);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuConfiguration->menuAction());
        menubar->addAction(menuHelp->menuAction());
        toolBar->addAction(actionTest);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTest->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
#if QT_CONFIG(tooltip)
        actionTest->setToolTip(QCoreApplication::translate("MainWindow", "Bonjour info bulle", nullptr));
#endif // QT_CONFIG(tooltip)
        button_main_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        button_main_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("MainWindow", "Edition", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuConfiguration->setTitle(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        dockWidget_2->setWindowTitle(QCoreApplication::translate("MainWindow", "Games", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Show Menu Bar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
