#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class Player;
class Score;
class Health;

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget* parent = nullptr);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

public slots:
    void startGame();
    void updateEnemiesSpeed(int score);
    void gameOver();
private:
    void checkAndUpdateRecord();

};
extern Game* game;

#endif // GAME_H
