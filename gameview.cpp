#include "gameview.h"
#include <QBrush>
#include <QPen>
#include <QMessageBox>
#include <QtLogging>
#include <QtDebug>
GameView::GameView(QWidget* parent):QGraphicsView(parent) {

    gscene = new QGraphicsScene(this);
    gscene->setSceneRect(0,0,constants::W_SIZE,constants::H_SIZE);
    gscene->setBackgroundBrush(QColor::fromRgb(180, 230, 170));
    this->setScene(gscene);

    this->setFocusPolicy(Qt::StrongFocus);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(constants::W_SIZE, constants::H_SIZE);
    this->setFrameStyle(QFrame::NoFrame);
    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // body parts positions
    snake.assign({QPoint(2,0), QPoint(1,0), QPoint(0,0)});

    // body parts occupy space in grid --> add to occupied set
    occupied.clear();
    occupied.insert(snake[0]);
    occupied.insert(snake[1]);
    occupied.insert(snake[2]);
    QBrush blackBrush(Qt::black);
    // segments
    QGraphicsRectItem* point_1 = gscene->addRect(0, 0, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), blackBrush);
    point_1->setPos(constants::TILE_SIZE*2, 0);
    QGraphicsRectItem* point_2 = gscene->addRect(0, 0, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), blackBrush);
    point_2->setPos(constants::TILE_SIZE,   0);
    QGraphicsRectItem* point_3 = gscene->addRect(0, 0, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), blackBrush);
    point_3->setPos(0,   0);
    segments.push_back(point_1);
    segments.push_back(point_2);
    segments.push_back(point_3);
    // generate food
    spawnFood();

    // timer logic
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveSlot()));
    timer->start(constants::TICK_INTERVAL);
}
void GameView::spawnFood(){
    while(true)
    {
        int x = QRandomGenerator::global()->bounded(constants::WIDTH);
        int y = QRandomGenerator::global()->bounded(constants::HEIGHT);

        if (! occupied.contains({x, y})){
            foodPos = {x, y};
        }
        if(food == nullptr){
            food= gscene->addRect(foodPos.x()*constants::TILE_SIZE, foodPos.y()*constants::TILE_SIZE, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), QBrush(Qt::red));
            return;
        }
    }
}
void GameView::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
        currDir = UP;

    }else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
        currDir = DOWN;

    }else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        currDir = LEFT;

    }else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        currDir = RIGHT;
    }
}
void GameView::MoveSlot(){

    int headCellX = snake[0].x();
    int headCellY = snake[0].y();

    switch (currDir) {
    case UP:
        headCellY--;
        break;
    case DOWN:
        headCellY++;
        break;
    case LEFT:
        headCellX--;
        break;
    default:
        headCellX++;
        break;
    }
    QPoint next ={headCellX, headCellY};
    wrap(next);
    bool grow = (next == foodPos);

    if(!grow){
        occupied.remove(snake.back());
    }
    snake.prepend(next);
    occupied.insert(next);
    if(grow){
        auto *r = gscene->addRect(0, 0, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), QBrush(Qt::black));
        segments.prepend(r);
        gscene->removeItem(food);
        food = nullptr;
        spawnFood();
    }else{
        snake.removeLast();
        makeTailNewHead(next);
    }
    if(grow) renderAllSegments();
    // qDebug() << "MoveSlot()";

    // qDebug() << "0 --> x:" << segments[0]->x()  << ", y:" << segments[0]->y() ;
    // qDebug() << "1 --> x:" << segments[1]->x()  << ", y:" << segments[1]->y() ;
    // qDebug() << "2 --> x:" << segments[2]->x()  << ", y:" << segments[2]->y() ;
}

void GameView::renderAllSegments(){
    while (segments.size() < snake.size()) {
        auto *r = gscene->addRect(0, 0, constants::TILE_SIZE, constants::TILE_SIZE, QPen(Qt::NoPen), QBrush(Qt::black));
        segments.push_back(r);
    }

    for (int i = 0; i < segments.size(); i++) {
        const QPoint &cell = snake[i];
        segments[i]->setPos(cell.x() * constants::TILE_SIZE, cell.y() * constants::TILE_SIZE);
    }
}
void GameView::makeTailNewHead(const QPoint& newHeadCell){
    int x_val = newHeadCell.x()*constants::TILE_SIZE;
    int y_val = newHeadCell.y()*constants::TILE_SIZE;
    segments[segments.size()-1]->setPos(x_val, y_val);
    segments.push_front(segments.takeLast());
    // qDebug() << "makeTailNewHead()";
    // qDebug() << "0 --> x:" << segments[0]->x()  << ", y:" << segments[0]->y() ;
    // qDebug() << "1 --> x:" << segments[1]->x()  << ", y:" << segments[1]->y() ;
    // qDebug() << "2 --> x:" << segments[2]->x()  << ", y:" << segments[2]->y() ;
}

void GameView::wrap(QPoint &p){
    if (p.x() >= constants::WIDTH) p.setX(0);
    else if (p.x() < 0) p.setX(constants::WIDTH-1);
    if (p.y() >= constants::HEIGHT) p.setY(0);
    else if (p.y() < 0) p.setY(constants::HEIGHT-1);
}

void GameView::gameOver(){
    timer->stop();
    QMessageBox msgBox;
    msgBox.setText("Game Over");
    msgBox.exec();
}
