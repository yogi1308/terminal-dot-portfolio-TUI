#pragma once
#include <ftxui/dom/elements.hpp>
#include "../helpers/bullet-points.cpp"

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

inline Element Inactive_Tab(std::string tab) {
    tab = " " + tab;
    return hbox({text(std::string(1, tab[1])), text(tab) | color(Color::GrayDark)});
}

inline Element Navbar_Tabs(int active_tab, std::string tab) 
{
    if (active_tab == 0 && tab == "about me") {return BulletPoints(tab);}
    else if (active_tab == 1 && tab == "experience"){return BulletPoints(tab);}
    else if (active_tab == 2 && tab == "projects"){return BulletPoints(tab);}
    else if (active_tab == 3 && tab == "contact me"){return BulletPoints(tab);}
    else{return Inactive_Tab(tab);}
}

inline Element Navbar(int active_tab)
{
    FlexboxConfig config;
    config.justify_content = FlexboxConfig::JustifyContent::SpaceEvenly;

    return flexbox({
        text("shreetej hadge") | center,
        separatorLight() | color(Color::GrayDark),
        Navbar_Tabs(active_tab, "about me"),
        separatorLight() | color(Color::GrayDark),
        Navbar_Tabs(active_tab, "experience"),
        separatorLight() | color(Color::GrayDark),
        Navbar_Tabs(active_tab, "projects"),
        separatorLight() | color(Color::GrayDark),
        Navbar_Tabs(active_tab, "contact me"),
    }, config) | borderStyled(LIGHT, Color::GrayDark);
}