#include "gameloopmanager.hpp"
#include "gameclock.hpp"
#include "../../helper.hpp"


namespace game {
GameLoopManager::GameLoopManager(myGameClock::GameClock* game_clock) : running(false), gameClock(game_clock) {}

GameLoopManager::~GameLoopManager() {
    helper.log(3, "Destructor for gameloopmanager");
    stop();
}

void GameLoopManager::start() {
    helper.log(3, "gameloopmanager start()");
    if (!running) {
        running = true;
        gameThread = std::thread(&GameLoopManager::gameLoop, this);
    }
}

void GameLoopManager::stop() {
    helper.log(3, "stop()");
    running = false;
    if (gameThread.joinable()) {
        gameThread.join();
    }
}

void GameLoopManager::gameLoop() {
    helper.log(3, "gameloopmanager gameLoop()");
    using clock = std::chrono::high_resolution_clock;
    auto nextTick = clock::now();

    while (running) {
        helper.log(3, "gameloop while");
        nextTick += std::chrono::milliseconds(TICK_INTERVAL);



        // Update game logic (fixed timestep)
        //std::cout << "[GameLoop] Updating game logic...\n";
        gameClock->runGameLoop();

        // Render frame
        //std::cout << "[GameLoop] Rendering frame...\n";

        // Sleep until the next tick (to maintain consistent timing)
        std::this_thread::sleep_until(nextTick);
    }
}

}

