#include <ftxui/dom/elements.hpp>

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

Element Sidebar_Active_Tab(std::string tab) {
    if (tab == "Git Gemini Automation Shell Script") {
        return paragraph(tab) | bgcolor(Color::RGB(77, 163, 255)) | color(Color::White);    
    }
    return text(tab) | bgcolor(Color::RGB(77, 163, 255)) | color(Color::White);
}
Element Sidebar_Inactive_Tab(std::string tab) {
    if (tab == "Git Gemini Automation Shell Script") {
        return paragraph(tab) | color(Color::White);    
    }
    return text(tab) | color(Color::White);
}

Element Sidebar(std::string tabs[], int active_tab, int size)
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
    );
}