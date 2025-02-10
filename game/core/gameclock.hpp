#ifndef GAME_CLOCK_HPP
#define GAME_CLOCK_HPP

#include <QObject>
#include <QTimer>
#include "../../glWindow/glWindowCore/openglwindow.hpp"
#include "gameloopmanager.hpp"


namespace myGameClock_QT {

/**
 * @brief The QTGameClock class
 */
class QTGameClock : public QObject {
    Q_OBJECT

public:
    explicit QTGameClock(OpenglWindow* window, QObject* parent = nullptr);

    void start(); // Starts the game clock
    bool isRunning() const { return running; } // Getter for running state
    void stop();

private slots:
    void gameTick();
    void eventTimerTriggered();

private:
    OpenglWindow* thisWindow;
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
}

namespace myGameClock {

class GameClock {
public:
    explicit GameClock(OpenglWindow* window, QObject* parent = nullptr);
    game::GameLoopManager* gameLoop;

    void start(); // Starts the game clock
    bool isRunning() const { return running; } // Getter for running state
    void runGameLoop();
    void stop();

    void setRunning(bool newRunning);

    int getGameTickCount() const;
    void setGameTickCount(int newGameTickCount);

    int getGameLogicUpdateCount() const;
    void setGameLogicUpdateCount(int newGameLogicUpdateCount);

    int getFrameCount() const;
    void setFrameCount(int newFrameCount);

private:
    OpenglWindow* thisWindow;
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
}
#endif // GAME_CLOCK_HPP
