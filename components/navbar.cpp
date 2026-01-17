#include <ftxui/dom/elements.hpp>
#include <string>

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

Element Active_Tab(std::string tab) 
{
    return hbox({text("> ") | color(Color::RGB(77, 163, 255)), text(tab)}) | center;
}

Element Inactive_Tab(std::string tab)
{
    tab = " " + tab;
    return hbox({text(std::string(1, tab[1])), text(tab) | color(Color::GrayDark)}) | center;
}

Element Navbar_Tabs(int active_tab, std::string tab) 
{
    if (active_tab == 0 && tab == "about me") {return Active_Tab(tab);}
    else if (active_tab == 1 && tab == "experience"){return Active_Tab(tab);}
    else if (active_tab == 2 && tab == "projects"){return Active_Tab(tab);}
    else if (active_tab == 3 && tab == "contact me"){return Active_Tab(tab);}
    else{return Inactive_Tab(tab);}
}

Element Navbar(int active_tab)
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