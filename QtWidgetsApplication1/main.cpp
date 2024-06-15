#include <QApplication>
#include "Game.h"
#include "StartWindow.h"

Game* game; // Definicja zmiennej game

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    StartWindow startWindow;
    game = new Game();

    QObject::connect(&startWindow, &StartWindow::startButtonClicked, game, &Game::startGame);
    QObject::connect(&startWindow, &StartWindow::startButtonClicked, &startWindow, &StartWindow::hide);

    startWindow.show();

    return a.exec();
}