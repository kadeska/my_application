#include "gameclock.hpp"
#include "../../helper.hpp"

#include <iostream>

// Constructor
GameClock::GameClock(QObject* parent)
    : QObject(parent),
    tickInterval(16),   // ~60 ticks per second (16ms per tick)
    running(false),     // Initialize as not running
    frameCount(0),
    gameLogicUpdateCount(0),
    gameTickCount(0)
{
    // std::cout << "GameClock constructor \n";
    helper.log(3, "GameClock(QObject* parent)");

    // Set up the main game loop
    //connect(&tickTimer, &QTimer::timeout, this, &GameClock::gameTick);

    // Set up custom timers
    //connect(&eventTimer, &QTimer::timeout, this, &GameClock::eventTimerTriggered);

    bool tickConnected = connect(&tickTimer, &QTimer::timeout, this, &GameClock::gameTick);
    // std::cout << "Tick timer connected: " << (tickConnected ? "Success" : "Failed") << std::endl;
    helper.string = std::string("Tick timer connected: ") + (tickConnected ? "Success" : "Failed");
    helper.log(3, helper.string);

    bool eventConnected = connect(&eventTimer, &QTimer::timeout, this, &GameClock::eventTimerTriggered);
    //std::cout << "Event timer connected: " << (eventConnected ? "Success" : "Failed") << std::endl;
    helper.string = std::string("Event timer connected: ") + (eventConnected ? "Success" : "Failed");
    helper.log(3, helper.string);

}

// Start the game clock
void GameClock::start() {
    helper.log(3, "GameClock::start()");
    if (!running) {
        tickTimer.start(tickInterval); // Start the tick timer
        eventTimer.start(1000);        // Example: 1-second event timer
        running = true;                // Set the running state to true
        // std::cout << "GameClock started" << std::endl;
        helper.log(3, "GameClock started");
    } else {
        // std::cout << "GameClock is already running!" << std::endl;
        helper.log(3, "GameClock is already running!");
    }
}

// Handle game ticks
void GameClock::gameTick() {

    // Called every 16ms (approx. 60 FPS)
    update();
    render();
    gameTickCount++;
}

// Handle custom event timer
void GameClock::eventTimerTriggered() {
    // Triggered every 1 second
    std::cout << "1-second event triggered!" << std::endl;
}

// Update game logic
void GameClock::update() {
    // Update game logic
    std::cout << "Logic update: " << gameLogicUpdateCount << " Game logic updated" << std::endl;
    gameLogicUpdateCount++;

}

// Render the game
void GameClock::render() {
    // Render the game (optional for console apps)
    std::cout << "Frame: " << frameCount << " Rendering frame" << std::endl;
    frameCount++;
}

void GameClock::stop() {
    tickTimer.stop();
}
