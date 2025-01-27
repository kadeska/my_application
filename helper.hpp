#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <string>

class Helper {
public:
    Helper() = default;

    // Example utility function: clamps a value between a minimum and maximum
    static float clamp(float value, float min, float max) {
        return (value < min) ? min : (value > max) ? max : value;
    }

    // Example utility function: log messages
    static void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

// Declare the global helper instance
extern Helper helper;

// Namespace for managing background color
namespace BackgroundColor {
// Encapsulate RGBA values and provide getters/setters
inline float R = 0.0f;
inline float G = 0.0f;
inline float B = 0.0f;
inline float A = 1.0f;

void setColor(float red, float green, float blue, float alpha);
void getColor(float& red, float& green, float& blue, float& alpha);
}

// Namespace for organizing various utilities
namespace UsefulFunctions {

class StdOutput {
public:
    StdOutput() = default;

    // Example function: print a message
    static void print(const std::string& message) {
        std::cout << message << std::endl;
    }
};

class QtOutput {
public:
    QtOutput() = default;

    // Placeholder: Example for Qt-specific output functionality
    void qtSpecificOutput(const std::string& message) {
        // Add Qt-specific output logic here
    }
};

class Calculation {
public:
    Calculation() = default;

    // Example function: compute a square
    static float square(float value) {
        return value * value;
    }
};

class Misc {
public:
    Misc() = default;

    // Example function: generate a random number
    static int randomInt(int min, int max);
};

} // namespace UsefulFunctions

#endif // HELPER_HPP
