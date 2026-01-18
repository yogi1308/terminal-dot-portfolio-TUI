#ifndef BULLET_POINTS_CPP
#define BULLET_POINTS_CPP

#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Element BulletPoints(std::string details) 
{
    return hbox({
        text("> ") | color(Color::RGB(77, 163, 255)),
        paragraph(details)
    });
}

#endif