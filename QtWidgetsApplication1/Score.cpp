#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase() {
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
    emit scoreChanged(score);
}

void Score::increaseWithSpeed(int speed) {
    score += speed; // Increase score by the given speed
    setPlainText(QString("Score: ") + QString::number(score)); // Update score text
    emit scoreChanged(score);
}

int Score::getScore() {
    return score;
}
