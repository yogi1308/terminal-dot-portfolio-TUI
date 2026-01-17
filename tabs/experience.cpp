#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Element Experience() 
{
    return hbox
    ({
        flexbox
        ({
            text("Office Assistant"),
            text("Documentation Lead"),
            text("Meeting Lead")
        }, FlexboxConfig()
            .Set(FlexboxConfig::Direction::Column)
            .SetGap(0, 1)
        ),
        separatorEmpty(),
        separator(),
        separatorEmpty(),
        vbox
        ({
            flexbox
            ({
                text("Office Assistant"),
                text("March 2025 - Present") | color(Color::GrayDark)
            }, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceBetween)),
            text({"Enterprise Technology Space Management, ASU"}) | color(Color::GrayDark),
            separatorEmpty(),
            vbox({
                hbox({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Maintained accurate departmental records and hardware inventory by performing data entry and documenting surplus and work orders.")
                }),
                hbox({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Managed computer hardware like monitors, CPU’s, laptops, etc. for department staff, including setup, breakdown, transportation, and surplus.")
                }),
                hbox({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Coordinated the maintenance and repair for the Enterprise Technology cart fleet by conducting routine inspections and liaising with external vendors to resolve mechanical issues promptly.")
                })
            })
        })
    });
}