#include "math/vector2.hpp"
#include "color/color.hpp"
#include "logger/logger.hpp"

// TODO: File utilities

using namespace utilz;

int main(void)
{ 
    // Log
    logger::log("This is a test file for our cpp utilities!!\n\n");

    // Colors
    rgba_color color1 = rgba_color(RGBA_WHITE);
    rgba_color color2 = rgba_color(RGBA_WHITE);

    logger::log("Color 1: " + color1.to_string() + '\n');
    logger::log("Color 2: " + color2.to_string() + '\n');

    // Color compare
    logger::log("rgbacmp output: " + std::to_string((int)rgba_color::rgbacmp(color1, color2)) + '\n');

    putchar('\n');

    // Vectors
    vector2f vec1 = vector2f(200.0f, 120.0f);
    vector2f vec2 = vector2f(300.0f, 200.0f);

    logger::log("Vector 1: " + vec1.to_string() + '\n');
    logger::log("Vector 2: " + vec2.to_string() + '\n');

    float dist = vector2f::eu_dist(vec1, vec2);

    logger::log("Distance: " + std::to_string(dist) + '\n', logger::WARNING);

    // Logging types 
    if (dist > 50.0f)
        logger::log("Distance between vectors is too great! (>50)\n", logger::ERROR);
    else if (dist < 50.0f)
        logger::log("Distance between vectors is too small! (<50)\n", logger::WARNING);
    else 
        logger::log("Distance between vectors is exactly 50!\n", logger::SUCCESS);


    putchar('\n');

    logger::log("Errors: " + std::to_string(logger::get_errors().size()) + " -> " + logger::get_errors()[0]);

    return 0;
}

