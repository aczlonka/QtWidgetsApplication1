#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> 
#include "Game.h"
#include "Health.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    // set random x position
    int random_number = rand() % 1000;
    setPos(random_number, 0);

    // drew the rect
    QPixmap pixmap("images/enemy.png");
    QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(scaledPixmap);
    setTransformOriginPoint(50, 50);
    setRotation(180);

    // Set default speed
    speed = 5;

    // make/connect a timer to move() the enemy every so often
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move() {
    // move enemy down with current speed
    setPos(x(), y() + speed);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 920) {
        // decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::setSpeed(int speed) {
    this->speed = speed;
}

int Enemy::getSpeed() {
    return speed;
}
