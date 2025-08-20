#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SnakeGame)
{
    ui->setupUi(this);
    this->setWindowTitle("Snake Game");
    this->resize(constants::W_SIZE, constants::H_SIZE);
    view = new GameView(this);

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
