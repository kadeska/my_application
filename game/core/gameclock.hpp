#ifndef GAME_CLOCK_HPP
#define GAME_CLOCK_HPP

#include <QObject>
#include <QTimer>

class GameClock : public QObject { // Properly named class
    Q_OBJECT

public:
    explicit GameClock(QObject* parent = nullptr); // Constructor matches the class name

    bool isRunning;      // Game running state

    void start();

private slots:
    void gameTick();
    void eventTimerTriggered();

private:
    void update();
    void render();

    QTimer tickTimer;    // Timer for game ticks
    QTimer eventTimer;   // Timer for custom events
    const int tickInterval; // Tick interval in milliseconds


    int frameCount;
    int gameLogicUpdateCount;
    int gameTickCount;
};

#endif // GAME_CLOCK_HPP
