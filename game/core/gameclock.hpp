#ifndef GAME_CLOCK_HPP
#define GAME_CLOCK_HPP

#include <QObject>
#include <QTimer>

class GameClock : public QObject {
    Q_OBJECT

public:
    explicit GameClock(QObject* parent = nullptr);

    void start(); // Starts the game clock
    bool isRunning() const { return running; } // Getter for running state

private slots:
    void gameTick();
    void eventTimerTriggered();

private:
    void update();
    void render();

    QTimer tickTimer;       // Timer for game ticks
    QTimer eventTimer;      // Timer for custom events
    const int tickInterval; // Tick interval in milliseconds
    bool running;           // Whether the clock is running

    int frameCount;         // Frame count
    int gameLogicUpdateCount; // Logic update count
    int gameTickCount;      // Tick count
};

#endif // GAME_CLOCK_HPP
