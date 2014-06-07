#include "titan/drawing/Color.hpp"

namespace titan
{

Color::Color(uint8 alpha, uint8 red, uint8 green, uint8 blue):
    _alpha(alpha),
    _red(red),
    _green(green),
    _blue(blue)
{
}

Color Color::argb32(float32 alpha, float32 red, float32 green, float32 blue)
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
