#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Element ContactMe()
{
    return hbox
    ({
        flexbox
        ({
            text("Email"),
            text("LinkedIn"),
            text("GitHub")
        }, FlexboxConfig()
            .Set(FlexboxConfig::Direction::Column)
            .SetGap(0, 1)
        ),
        separatorEmpty(),
        separator(),
        separatorEmpty(),
        text("shreetej.yogi@gmail.com")
    });
}