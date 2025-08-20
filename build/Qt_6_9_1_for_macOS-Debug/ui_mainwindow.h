/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnakeGame
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SnakeGame)
    {
        if (SnakeGame->objectName().isEmpty())
            SnakeGame->setObjectName("SnakeGame");
        SnakeGame->resize(800, 600);
        centralwidget = new QWidget(SnakeGame);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(graphicsView);

        SnakeGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SnakeGame);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 42));
        SnakeGame->setMenuBar(menubar);
        statusbar = new QStatusBar(SnakeGame);
        statusbar->setObjectName("statusbar");
        SnakeGame->setStatusBar(statusbar);

        retranslateUi(SnakeGame);

        QMetaObject::connectSlotsByName(SnakeGame);
    } // setupUi

    void retranslateUi(QMainWindow *SnakeGame)
    {
        SnakeGame->setWindowTitle(QCoreApplication::translate("SnakeGame", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnakeGame: public Ui_SnakeGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
