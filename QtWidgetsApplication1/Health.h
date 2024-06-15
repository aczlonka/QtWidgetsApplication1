#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem {
    Q_OBJECT
public:
    Health(QGraphicsItem* parent = nullptr);
    void decrease();
    int getHealth();
    int health;
signals:
    void noHealth(); // Deklaracja sygna³u

    
};

#endif // HEALTH_H
