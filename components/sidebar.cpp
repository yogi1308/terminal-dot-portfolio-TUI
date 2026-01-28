#pragma once

#include <ftxui/dom/elements.hpp>

using namespace ftxui;

inline Element Sidebar_Active_Tab(std::string tab) {
    tab = "  " + tab + "  ";
    if (tab == "  Git Gemini Automation Shell Script  ") {
        return vbox({text("  Git Gemini Automation"), text("  Shell Script")}) | bgcolor(Color::RGB(77, 163, 255)) | color(Color::Black); 
    }
    return hbox({text(tab)}) | bgcolor(Color::RGB(77, 163, 255)) | color(Color::Black);
}

inline Element Sidebar_Inactive_Tab(std::string tab) {
    tab = "  " + tab + "  ";
    if (tab == "  Git Gemini Automation Shell Script  ") {
        return vbox({text("  Git Gemini Automation"), text("  Shell Script")});  
    }
    return text(tab) | color(Color::Default);
}

inline Element Sidebar(std::string tabs[], int active_tab, int size)
{
    Elements list; 
    
    for (size_t i = 0; i < size; i++) {
        if (i == active_tab) {
            list.push_back(Sidebar_Active_Tab(tabs[i]));
        } else {
            list.push_back(Sidebar_Inactive_Tab(tabs[i]));
        }
    }

    return flexbox(list, FlexboxConfig()
        .Set(FlexboxConfig::Direction::Column)
        .SetGap(0, 1)
        .Set(FlexboxConfig::AlignItems::Stretch) 
    );
}