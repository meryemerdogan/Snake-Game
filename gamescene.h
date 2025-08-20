#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "constants.h"
class GameScene: public QGraphicsScene
{
public:
    GameScene(QObject* parent = nullptr);
};

#endif // GAMESCENE_H
