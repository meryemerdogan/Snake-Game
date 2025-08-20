#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<gamescene.h>
#include <gameview.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class SnakeGame;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::SnakeGame *ui;

    GameScene *scene;
    GameView *view;

};
#endif // MAINWINDOW_H
