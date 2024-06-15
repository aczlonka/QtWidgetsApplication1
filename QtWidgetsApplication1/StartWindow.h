#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>

class QPushButton;
class QLabel;

class StartWindow : public QWidget {
    Q_OBJECT

public:
    StartWindow(QWidget* parent = nullptr);

signals:
    void startButtonClicked();

private slots:
    void startGame();
    void quitGame();
    void displayRecord();

private:
    QPushButton* startButton;
    QPushButton* quitButton;
    QLabel* recordLabel;
    QLabel* titleLabel;
};

#endif // STARTWINDOW_H
