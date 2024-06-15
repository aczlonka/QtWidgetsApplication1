#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent = nullptr);
    void setSpeed(int speed);
    int getSpeed();
public slots:
    void move();
private:
    int speed;
};

#endif // ENEMY_H
