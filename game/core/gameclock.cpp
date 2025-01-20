#include "gameclock.hpp"
#include <iostream>

// Constructor
GameClock::GameClock(QObject* parent)
    : QObject(parent),
    tickInterval(16), // ~60 ticks per second (16ms per tick)
    isRunning(true) {

    // Set up the main game loop
    connect(&tickTimer, &QTimer::timeout, this, &GameClock::gameTick);

    // Set up custom timers
    connect(&eventTimer, &QTimer::timeout, this, &GameClock::eventTimerTriggered);

    // Start the tick timer
    tickTimer.start(tickInterval);

    // Example: Start a timer for a 1-second event
    eventTimer.start(1000);
}

// Start the game clock
void GameClock::start() {
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
    std::cout << "Game logic updated" << std::endl;
}

// Render the game
void GameClock::render() {
    // Render the game (optional for console apps)
    std::cout << "Rendering frame" << std::endl;
}
