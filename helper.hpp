#ifndef HELPER_HPP
#define HELPER_HPP

// A simple helper class for shared utility purposes
class Helper {
public:
    Helper() {}
};

// Declare the global helper instance
extern Helper helper;

// Namespace for background color variables
namespace Background_color {
// RGBA color value additions. These are used to manipulate the background color.
extern float R; // Red component
extern float G; // Green component
extern float B; // Blue component
extern float A; // Alpha component (opacity)
}

namespace usefullFunctions {
class StdOutput
{
public:
    StdOutput();
};

class QtOutput
{
public:
    QtOutput();
};

class Calculation
{
public:
    Calculation();
};

class misc
{
public:
    misc();
};
}

#endif // HELPER_HPP
