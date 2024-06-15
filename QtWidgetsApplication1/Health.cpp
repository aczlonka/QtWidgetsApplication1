#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize the health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Health: ") + QString::number(health));

    // If health is zero, emit the noHealth signal
    if (health <= 0) {
        emit noHealth();
    }
}

int Health::getHealth() {
    return health;
}
