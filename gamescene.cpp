#include "gamescene.h"

GameScene::GameScene(QObject* parent):QGraphicsScene(parent) {
    this->setSceneRect(0, 0, constants::W_SIZE, constants::H_SIZE);
}
