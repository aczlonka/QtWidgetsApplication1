#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
 

    QPixmap pixmap("images/player.png");
    QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Zmieñ rozmiar na 50x50
    setPixmap(scaledPixmap);
}

void Player::keyPressEvent(QKeyEvent* event) {
    // move the player left and right
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 1280)
            setPos(x() + 10, y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);

       

    }
}

void Player::spawn() {
    // create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}