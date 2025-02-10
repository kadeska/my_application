#ifndef GAME_LOOP_MANAGER_HPP
#define GAME_LOOP_MANAGER_HPP

#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>

namespace myGameClock {
class GameClock;
}

namespace game {
class GameLoopManager {
public:
    GameLoopManager(myGameClock::GameClock* game_clock);
    ~GameLoopManager();

    void start();  // Starts the game loop
    void stop();   // Stops the game loop

private:
    void gameLoop(); // The main loop function

    myGameClock::GameClock* gameClock;

    std::thread gameThread;   // Thread for the game loop
    std::atomic<bool> running; // Atomic flag to control loop execution

    const int TICK_INTERVAL = 16; // 16ms per tick (~60 updates per second)
};
}

#endif // GAME_LOOP_MANAGER_HPP
