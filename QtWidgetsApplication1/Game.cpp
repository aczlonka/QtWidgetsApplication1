#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "StartWindow.h"
#include "RecordManager.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QMessageBox>
#include <QApplication>

Game::Game(QWidget* parent) : QGraphicsView(parent) {
    // Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1280, 920);
    QImage backgroundImage("images/bg.png");
    QImage scaledBackground = backgroundImage.scaled(1280, 920, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setBackgroundBrush(QBrush(scaledBackground));
    // Make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280, 920);

    // Hide the game window initially
    hide();
}

void Game::startGame() {
    // Create the player
    player = new Player();
    player->setPos(550, 700);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // Create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    // Spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(1700);

    // Connect scoreChanged signal to updateEnemiesSpeed slot
    QObject::connect(score, SIGNAL(scoreChanged(int)), this, SLOT(updateEnemiesSpeed(int)));

    // Connect noHealth signal from health to gameOver slot
    QObject::connect(health, SIGNAL(noHealth()), this, SLOT(gameOver()));

    // Show the game window
    show();
}

void Game::updateEnemiesSpeed(int score) {
    // Example logic to increase enemy speed based on score
    int newSpeed = 5 + score / 10; 
    QList<QGraphicsItem*> items = scene->items();
    foreach(QGraphicsItem * item, items) {
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if (enemy) {
            enemy->setSpeed(newSpeed);
        }
    }
}

void Game::checkAndUpdateRecord() {
    int currentScore = score->getScore();
    int record = RecordManager::readRecord("record.txt");
    if (currentScore > record) {
        RecordManager::writeRecord("record.txt", currentScore);
    }
}

void Game::gameOver() {
    int finalScore = score->getScore();
    checkAndUpdateRecord();

    // Stop the game
    scene->clear(); // Clear all items from the scene
    hide(); // Hide the game window

    QMessageBox msgBox;
    msgBox.setText("Game Over");
    msgBox.setInformativeText("Your score: " + QString::number(finalScore));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setStyleSheet("QMessageBox { background-color: #F0F8FF; }"
        "QLabel { color: #2E8B57; font-size: 18px; }"
        "QPushButton { background-color: #2E8B57; color: white; border-radius: 10px; min-width: 80px; }");
    
    msgBox.exec();


    // Exit the application (optional)
    QApplication::quit();
}
