#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "../components/sidebar.cpp"
#include "../helpers/bullet-points.cpp"

using namespace ftxui;

Element ActiveContact(int contact_tab) 
{
    if (contact_tab == 0) {return BulletPoints("shreetej.yogi@gmail.com");}
    else if (contact_tab == 1) {return BulletPoints("https://www.linkedin.com/in/shreetej-hadge") | center;}
    else if (contact_tab == 2) {return vbox({filler(), BulletPoints("https://github.com/yogi1308")}) | flex;}
    return BulletPoints("");
}

Element ContactMe(int contact_tab)
{
    contact_tab = ((contact_tab % 3) + 3) % 3;
    
    std::string my_tabs[] = {
        "email",
        "linkedin",
        "github"
    };

    return vbox
    ({
        flexbox
        ({
            text("☉   send me a message"),
            text("enter") | color(Color::GrayDark)
        }, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceBetween)) | borderLight,
        separatorEmpty(),
        hbox
        ({
            Sidebar(my_tabs, contact_tab, 3),
            separatorEmpty(),
            separator(),
            separatorEmpty(),
            ActiveContact(contact_tab)
        })
    });
}