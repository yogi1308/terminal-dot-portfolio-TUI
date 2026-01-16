#include <ftxui/dom/elements.hpp>
#include <sstream> // <--- REQUIRED: Needed to split the string
#include <vector>

using namespace ftxui;

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
                 RenderLines(name_ascii) | color(Color::RGB(77, 163, 255)),


                 bio_text});
}