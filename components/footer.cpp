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
        return flexbox({FooterElement("↑/↓ ", "Navigate"), FooterElement("q ", "quit")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    else if (tab == "contact me")
    {
        return flexbox({FooterElement("↑/↓ ", "Navigate"), FooterElement("enter ", "select"), FooterElement("q ", "quit")}, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceEvenly));
    }
    return text("");
}