#include <ftxui/dom/elements.hpp>
#include <sstream> // <--- REQUIRED: Needed to split the string
#include <vector>

using namespace ftxui;

Element Skills(){
    FlexboxConfig config;
    config.wrap = FlexboxConfig::Wrap::Wrap;
    config.gap_x = 3;
    config.gap_y = 1;

    return vbox({text("Skills") | color(Color::RGB(77, 163, 255)), separator(),
                 flexbox({hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" C++")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Java")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Python")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" HTML")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" CSS")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" JavaScript")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" ReactJS")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" ExpressJS")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" NodeJS")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" PostgresSQL")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Git")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Linux")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Prisma ORM")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" TypeScript")}),
                          hbox({text("[>]") | color(Color::RGB(77, 163, 255)), text(" Tailwind")})},
                         config)});
}

// Element Skills()
// {
//     return vbox({
//         text("Skills") | color(Color::RGB(77, 163, 255)), separator(),
//         gridbox({
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" C++")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Java")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Python")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" HTML")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" CSS")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" JavaScript")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" ReactJS")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" ExpressJS")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" NodeJS")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" PostgresSQL")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Git")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Linux")})},
//             {hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Prisma ORM")}), hbox({text("[✱]") | color(Color::RGB(77, 163, 255)), text(" Tailwind")})}
//         })
//     });
// }

// #include <ftxui/dom/elements.hpp>
// #include <ftxui/dom/table.hpp>

// using namespace ftxui;

// Element Skills()
// {
//     // 1. Define color once to keep code clean
//     auto accent = Color::RGB(77, 163, 255);

//     // 2. Helper function to style every skill consistently
//     auto render_skill = [&](std::string name)
//     {
//         return hbox({text("[✱]") | color(accent),
//                      text(" " + name)}) |
//                size(WIDTH, GREATER_THAN, 22);                // Fix 2: Invisible Border (Vertical Spacing)
//     };

//     return vbox({
//         text("Skills") | color(accent) | bold | center,
//         separatorLight(),

//         // 3. The cleaner Gridbox
//         gridbox({{render_skill("C++"), render_skill("Java")},
//                  {render_skill("Python"), render_skill("HTML")},
//                  {render_skill("CSS"), render_skill("JavaScript")},
//                  {render_skill("ReactJS"), render_skill("ExpressJS")},
//                  {render_skill("NodeJS"), render_skill("PostgresSQL")},
//                  {render_skill("Git"), render_skill("Linux")},
//                  {render_skill("Prisma ORM"), render_skill("Tailwind")}})
//     });
// }

// --- Helper Function ---
// Splits a multi-line string into a vertical box of individual text elements.
Element RenderLines(std::string art)
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

ftxui::Element aboutMe()
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

    auto bio_text = paragraph("Hey👋, I'm Shreetej Hadge. I'm currently a Computer Science Student at Arizona State University in my Sophomore Year. I am highly passionate about building cool software, and learning more about the vast, endless field of Computer Science and Software Engineering. For now, I am deep into the world of web dev, while polishing my Java, Python, and C/C++ skills. I am also highly interested in Data Science (especially Sports Analytics), and Embedded Systems.... I'm no expert here, but I'm curious and wish to learn more about them.\nWhen I'm not on my computer, I spend my time swimming, watching basketball, catching up to the latest shows and movies and reading some manga. My goal is to simply build cool stuff and do cool things😎");

    return vbox({// USE THE HELPER HERE
        hbox({
            RenderLines(name_ascii) | color(Color::RGB(77, 163, 255)),
            Skills()
        }),
        text(""),
        bio_text
    });
}