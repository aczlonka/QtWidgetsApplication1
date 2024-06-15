#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
    Q_OBJECT
public:
    Score(QGraphicsItem* parent = nullptr);
    void increase();
    void increaseWithSpeed(int speed);
    int getScore();
    int score;
signals:
    void scoreChanged(int score);

    
};

#endif // SCORE_H
