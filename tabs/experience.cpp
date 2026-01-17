#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Element ExperienceDetailsBulletPoints(std::string details) 
{
    return hbox({
        text("> ") | color(Color::RGB(77, 163, 255)),
        paragraph(details)
    });
}

Element Details(std::string position, std::string dates, std::string location) 
{
    if (position == "Office Assistant" || dates == "March 2025 - Present" || location == "Enterprise Technology Space Management, ASU") 
    {
        return vbox({
            ExperienceDetailsBulletPoints("Maintained accurate departmental records and hardware inventory by performing data entry and documenting surplus and work orders."),
            ExperienceDetailsBulletPoints("Managed computer hardware like monitors, CPU’s, laptops, etc. for department staff, including setup, breakdown, transportation, and surplus."),
            ExperienceDetailsBulletPoints("Coordinated the maintenance and repair for the Enterprise Technology cart fleet by conducting routine inspections and liaising with external vendors to resolve mechanical issues promptly.")
        });
    }
    else if (position == "Documentation Lead" || dates == "January 2025 - May 2025" || location == "NUETech, EPICS ASU")
    {
        return vbox({
            ExperienceDetailsBulletPoints("Led the creation and organization of comprehensive project documentation, ensuring clarity and accuracy."),
            ExperienceDetailsBulletPoints("Lead documentation and ensured each respective team member is documenting their work in the design document."),
            ExperienceDetailsBulletPoints("Presented documentation updates to stakeholders, ensuring transparency and alignment with project milestones."),
            ExperienceDetailsBulletPoints("Conducted regular reviews of documentation to ensure alignment with project goals and stakeholder requirements.")
        });
    }
    else if (position == "Meeting Lead" || dates == "August 2024 - December 2024" || location == "Saayam for All, EPICS ASU")
    {
        return vbox({
            ExperienceDetailsBulletPoints("Planned, organized, and facilitated weekly team meetings and created detailed meeting agendas."),
            ExperienceDetailsBulletPoints("Documented meetings, coordinated schedules, tracked action items, and supported project planning to ensure timely deliverables."),
            ExperienceDetailsBulletPoints("Developed and maintained a centralized repository for meeting notes, action items, and project updates."),
            ExperienceDetailsBulletPoints("Monitored progress on action items and provided regular updates to the team and project leads.")
        });
    }
}

Element ExperinceDetails(std::string position, std::string dates, std::string location) 
{
    return vbox
    ({
        flexbox
        ({
            text(position),
            text(dates) | color(Color::GrayDark)
        }, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceBetween)),
        text({location}) | color(Color::GrayDark),
        separatorEmpty(),
        Details(position, dates, location)
    });
}

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
        ExperinceDetails("Office Assistant", "March 2025 - Present", "Enterprise Technology Space Management, ASU")
    });
}