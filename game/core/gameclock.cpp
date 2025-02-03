#include "gameclock.hpp"
#include "../../helper.hpp"
#include <iostream>

// Constructor
GameClock::GameClock(OpenglWindow* window, QObject* parent)
    : QObject(parent),
    thisWindow(window),
    tickInterval(16),   // ~60 ticks per second (16ms per tick)
    running(false),     // Initialize as not running
    frameCount(0),
    gameLogicUpdateCount(0),
    gameTickCount(0)
{
    helper.log(3, "GameClock(QObject* parent)");

    bool tickConnected = connect(&tickTimer, &QTimer::timeout, this, &GameClock::gameTick);
    helper.string = std::string("Tick timer connected: ") + (tickConnected ? "Success" : "Failed");
    helper.log(3, helper.string);

    bool eventConnected = connect(&eventTimer, &QTimer::timeout, this, &GameClock::eventTimerTriggered);
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
        helper.log(3, "GameClock started");
    } else {
        helper.log(3, "GameClock is already running!");
    }
}

// Handle game ticks
void GameClock::gameTick() {
    helper.log(4, "gameTick()");
    update();
    render();
    gameTickCount++;
}

// Handle custom event timer
void GameClock::eventTimerTriggered() {
    helper.log(3, "1-second event triggered!");
}

// Update game logic
void GameClock::update() {
    helper.string = std::string("Logic update: ") + std::to_string(gameLogicUpdateCount) + std::string(" Game logic updated");
    helper.log(4, helper.string);
    gameLogicUpdateCount++;
}

// Render the game
void GameClock::render() {
    helper.string = std::string("Frame: ") + std::to_string(frameCount) + std::string(" Rendering Frame");
    helper.log(4, helper.string);
    try {
        thisWindow->render();
    } catch (...) { //const std::exception& e) {
        helper.log(1, std::string("Not able to render: "));// + e.what());
    }


    frameCount++;
}

// Stop the game clock
void GameClock::stop() {
    tickTimer.stop();
}
