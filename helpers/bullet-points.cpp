#pragma once

#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Element BulletPoints(std::string details) 
{
    return hbox({
        text("> ") | color(Color::RGB(77, 163, 255)),
        paragraph(details)
    });
}