#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QPoint>
#include "constants.h"

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
private:
    QGraphicsScene *gscene = nullptr;
    Direction currDir = DOWN;
    QTimer *timer  = nullptr;
    QVector<QPoint> snake;
    QSet<QPoint> occupied;
    QPoint foodPos;
    QGraphicsRectItem* food = nullptr;
    QVector<QGraphicsRectItem*> segments;
    void spawnFood();
    bool isCrash(Direction);
    void gameOver();
    void wrap(QPoint& p);
    void makeTailNewHead(const QPoint& newHeadCell);
    void renderAllSegments();

private slots:
    void MoveSlot();
};

#endif // GAMEVIEW_H
