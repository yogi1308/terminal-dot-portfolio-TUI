#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

Element ContactMe(int contact_tab)
{
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
            vbox
            ({
                text("email") | borderEmpty,
                text("linkedin") | borderLight,
                text("github") | borderEmpty
            }),
            separatorEmpty(),
            separator(),
            separatorEmpty(),
            hbox
            ({
                text(" > ") | color(Color::RGB(77, 163, 255)),
                text("shreetej.yogi@gmail.com")
            }) | center
        })
    });
}