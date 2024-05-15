/* SIMPLE RGBA COLOR CLASS 
 *
 * Adds a rgba color representation class, uses 8 bits instead of floats to save memory
 *
 * Functions: 
 *      rgbacmp: Compares colors 
*/

#pragma once 

#include <iostream>
#include <string>

#define RGBA_WHITE 255, 255, 255, 255
#define RGBA_BLACK 0, 0, 0, 255
#define RGBA_RED 255, 0, 0, 255
#define RGBA_GREEN 0, 255, 0, 255
#define RGBA_BLUE 0, 0, 255, 255
#define RGBA_YELLOW 255, 255, 0, 255
#define RGBA_MAGENTA 255, 0, 255, 255
#define RGBA_CYAN 0, 255, 255, 255
#define RGBA_GRAY 127, 127, 127, 255
#define RGBA_SKY_BLUE 135, 206, 235, 255

#define RGBA_NORMALIZED_FLOAT(x) ((float)x.r / 255.0f), ((float)x.g / 255.0f), ((float)x.b / 255.0f), ((float)x.a / 255.0f)
#define RGBA_NORMALIZED_INT(x) (int)(x.r / 255), (int)(x.g / 255), (int)(x.b / 255), (int)(x.a / 255)
#define RGBA_NORMALIZED(x) (x.r / 255), (x.g / 255), (x.b / 255), (x.a / 255)
#define RGBA_UNPACK(x) x.r, x.g, x.b, x.a
#define RGB_RANDOM rand_int(0, 255), rand_int(0, 255), rand_int(0, 255)
#define RGBA_RANDOM rand_int(0, 255), rand_int(0, 255), rand_int(0, 255), rand_int(0, 255)

namespace utilz
{
    struct rgba_color
    {
        uint8_t r, g, b, a;
        rgba_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
        rgba_color() : r(0), g(0), b(0), a(0) {}

        static uint8_t rgbacmp(rgba_color a, rgba_color b) 
        { return (a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a); }

        std::string to_string()
        { return std::string(std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ", " + std::to_string(a)); } 
    };  

    struct rgb_color
    {
        uint8_t r, g, b;
        rgb_color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
        rgb_color() : r(0), g(0), b(0) {}

        static uint8_t rgbcmp(rgb_color a, rgb_color b) 
        { return (a.r == b.r && a.g == b.g && a.b == b.b); }

        std::string to_string()
        { return std::string(std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b)); }

    };
};

