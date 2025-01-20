#include "gameclock.hpp"
#include <iostream>

int frameCount;
int gameLogicUpdateCount;
int gameTickCount;

bool isRunning;

// Constructor
GameClock::GameClock(QObject* parent)
    : QObject(parent),
    tickInterval(16), // ~60 ticks per second (16ms per tick)
    isRunning(false) {

    frameCount = 0;
    gameLogicUpdateCount = 0;
    gameTickCount = 0;

    // Set up the main game loop
    connect(&tickTimer, &QTimer::timeout, this, &GameClock::gameTick);

    // Set up custom timers
    connect(&eventTimer, &QTimer::timeout, this, &GameClock::eventTimerTriggered);
}

// Start the game clock
void GameClock::start() {
    // Start the tick timer
    tickTimer.start(tickInterval);

    // Example: Start a timer for a 1-second event
    eventTimer.start(1000);

    std::cout << "GameClock started" << std::endl;
}

// Handle game ticks
void GameClock::gameTick() {
    // Called every 16ms (approx. 60 FPS)
    update();
    render();
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
