#include "StartWindow.h"
#include "Game.h"
#include "RecordManager.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QFile>
#include <QTextStream>

StartWindow::StartWindow(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    titleLabel = new QLabel("PlaneBattle", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(32);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    layout->addWidget(titleLabel);

    recordLabel = new QLabel(this);
    QFont recordFont = recordLabel->font();
    recordFont.setPointSize(20);
    recordLabel->setFont(recordFont);
    recordLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(recordLabel);

    startButton = new QPushButton("Start", this);
    startButton->setFixedSize(200, 50);
    QFont buttonFont = startButton->font();
    buttonFont.setPointSize(16);
    startButton->setFont(buttonFont);
    connect(startButton, &QPushButton::clicked, this, &StartWindow::startGame);
    layout->addWidget(startButton);

    // Quit button
    quitButton = new QPushButton("Quit", this);
    quitButton->setFixedSize(200, 50);
    quitButton->setFont(buttonFont);
    connect(quitButton, &QPushButton::clicked, this, &StartWindow::quitGame);
    layout->addWidget(quitButton);

    // Set the layout
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

    displayRecord();

        setStyleSheet("QPushButton { background-color: #2E8B57; color: white; border-radius: 10px; }"
                  "QPushButton:{ background-color: #3CB371; }"
                  "QLabel { color: #2E8B57; }"
                  "QWidget { background-color: #F0F8FF; }");
        resize(600, 400);
}

void StartWindow::startGame() {
    emit startButtonClicked();
    hide();
}

void StartWindow::quitGame() {
    qApp->quit(); // U¿ywamy qApp, który jest wskaŸnikiem do QApplication
}

void StartWindow::displayRecord() {
    int record = RecordManager::readRecord("record.txt");
    recordLabel->setText(QString("Best Score: %1").arg(record));
}
