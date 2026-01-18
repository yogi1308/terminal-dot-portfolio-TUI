#include <ftxui/component/component.hpp> 

using namespace ftxui;

Element FooterElement(std::string controls, std::string values)
{
    return hbox
    ({
        hbox
        ({
            text(controls),
            text(values) | color(Color::GrayDark)
        })
    });
}

Element Footer(std::string tab) {
    if (tab == "about me")
    {
        return flexbox({FooterElement("q ", "quit")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    else if (tab == "experience" || tab == "projects")
    {
        return flexbox({FooterElement("↑/↓ ", "navigate"), FooterElement("q ", "quit")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    else if (tab == "contact me")
    {
        return flexbox({FooterElement("↑/↓ ", "navigate"), FooterElement("enter ", "select"), FooterElement("q ", "quit")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    else if (tab == "contact form")
    {
        return flexbox({FooterElement("tab/shift+tab ", "navigate"), FooterElement("ctrl+s ", "submit"), FooterElement("enter ", "newline"), FooterElement("esc ", "back")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    return text("");
}