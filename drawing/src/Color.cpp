#include "titan/drawing/Color.hpp"

namespace titan
{

Color::Color():
    _alpha(255),
    _red(255),
    _green(255),
    _blue(255)
{
}

Color Color::argb(uint8 alpha, uint8 red, uint8 green, uint8 blue)
{
    Color color;
    color.setAlpha(alpha);
    color.setRed(red);
    color.setGreen(green);
    color.setBlue(blue);
    return color;
}

Color::~Color()
{
}

}
