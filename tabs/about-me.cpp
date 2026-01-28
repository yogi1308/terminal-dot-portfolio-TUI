#include <ftxui/dom/elements.hpp>
#include <sstream> // <--- REQUIRED: Needed to split the string
#include <vector>
#include "../helpers/bullet-points.cpp"

using namespace ftxui;

Element Skills()
{
    auto accent = Color::RGB(77, 163, 255);
    return vbox
    ({
        text("Skills") | color(accent) | bold,
        separator(),
        vbox
        ({
            hbox
            ({
                text("[ languages ] ") | color(accent),
                flexbox
                ({
                    text("C++ "),
                    BulletPoints("Python  "),
                    BulletPoints("Java  "),
                    BulletPoints("JavaScript  "),
                    BulletPoints("TypeScript  ")
                }, FlexboxConfig().Set(FlexboxConfig::Wrap::Wrap))
            }), separatorEmpty(),
            hbox
            ({
                text("[ frontend  ] ") | color(accent),
                flexbox
                ({
                    text("ReactJS "),
                    BulletPoints("TailWindCSS  "),
                    BulletPoints("HTML  "),
                    BulletPoints("CSS  ")
                }, FlexboxConfig().Set(FlexboxConfig::Wrap::Wrap))
            }), separatorEmpty(),
            hbox
            ({
                text("[  backend  ] ") | color(accent),
                flexbox
                ({
                    text("NodeJS "),
                    BulletPoints("ExpressJS  "),
                    BulletPoints("PostgreSQL  "),
                    BulletPoints("Prisma ORM  ")
                }, FlexboxConfig().Set(FlexboxConfig::Wrap::Wrap))
            }), separatorEmpty(),
            hbox
            ({
                text("[   tools   ] ") | color(accent),
                flexbox
                ({
                    text("Git "),
                    BulletPoints("Linux  "),
                    BulletPoints("Window  ")
                }, FlexboxConfig().Set(FlexboxConfig::Wrap::Wrap))
            })
        })
    });
}

Element RenderLines(std::string art) // Splits a multi-line string into a vertical box of individual text elements.
{
    std::vector<Element> lines;
    std::stringstream ss(art);
    std::string line;
    while (std::getline(ss, line))
    {
        lines.push_back(text(line));
    }
    return vbox(lines);
}

ftxui::Element AboutMe()
{
    // Your ASCII Art (Raw String)
    std::string name_ascii = 
    R"(███████╗██╗  ██╗██████╗ ███████╗███████╗████████╗███████╗      ██╗    
██╔════╝██║  ██║██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝      ██║    
███████╗███████║██████╔╝█████╗  █████╗     ██║   █████╗        ██║    
╚════██║██╔══██║██╔══██╗██╔══╝  ██╔══╝     ██║   ██╔══╝  ██    ██║    
███████║██║  ██║██║  ██║███████╗███████╗   ██║   ███████╗╚█████╔╝    
╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚══════╝ ╚════╝    
                                                                     
██╗  ██╗ █████╗ ██████╗  ██████╗ ███████╗                            
██║  ██║██╔══██╗██╔══██╗██╔════╝ ██╔════╝                            
███████║███████║██║  ██║██║  ███╗█████╗                              
██╔══██║██╔══██║██║  ██║██║   ██║██╔══╝                              
██║  ██║██║  ██║██████╔╝╚██████╔╝███████╗                            
╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚══════╝                            
)";

    return vbox
    ({
        hbox
        ({
            RenderLines(name_ascii) | color(Color::RGB(77, 163, 255)),
            Skills()
        }),
        text(""),
        paragraph("Hey, I'm Shreetej Hadge. I'm currently a Computer Science Student at Arizona State University in my Sophomore Year. I am highly passionate about building cool software, and learning more about the vast, endless field of Computer Science and Software Engineering. For now, I am deep into the world of web dev, while polishing my Java, Python, and C/C++ skills. I am also highly interested in Data Science (especially Sports Analytics), and Embedded Systems.... I'm no expert here, but I'm curious and wish to learn more about them.\nWhen I'm not on my computer, I spend my time swimming, watching basketball, catching up to the latest shows and movies and reading some manga. My goal is to simply build cool stuff and do cool things") | color(Color::Default)
    });
}