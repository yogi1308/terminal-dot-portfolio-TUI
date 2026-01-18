#include <ftxui/dom/elements.hpp>
#include "../helpers/bullet-points.cpp"

using namespace ftxui;

Element ProjectDetailPoints(std::string name) 
{
    if (name == "Basic Google Drive") {
        return vbox({
            BulletPoints("Developed a full-stack file storage application using Node.js, Express, and PostgreSQL (via Prisma ORM) to efficiently manage user data and complex file hierarchies."),
            BulletPoints("Integrated Cloudinary API for scalable cloud storage, enabling real-time uploads, folder management, and automatic categorization of assets into photos, videos, and documents."),
            BulletPoints("Implemented secure user authentication with Passport.js and deployed the application on a serverless architecture using Vercel and Neon for high availability and performance.")
        });
    }
    else if (name == "Git Gemini Automation Shell Script")
    {
        return vbox({
            BulletPoints("Wrote a shell script that automates git stage commit and push workflow by sending diffs to the Gemini CLI tool to generate context-aware commit messages to the staged files and pushing them."),
            BulletPoints("Integrated 60-second API timeouts and diff size validation to handle large changesets gracefully with manual fallback options."),
            BulletPoints("Implemented comprehensive error handling for API timeouts, authentication failures, and network issues with user-friendly troubleshooting messages.")
        });
    }
    else if (name == "CLI Art")
    {
        return vbox({
            BulletPoints("Developed a Python command-line tool to convert images from local files or web URLs into full-color ASCII art, with argparse to provide users with full control over output width, color modes, brightness/contrast, and inversion."),
            BulletPoints("Used Pillows library for Image Processing, Colorama to implement multiple color modes, shutil for terminal window data, requests for fetching image from url and argparse to process arguments passed by user using flags."),
            BulletPoints("Packaged the final script into standalone executables for both Windows (.exe), WSL and similar Ubuntu-based Linux systems using PyInstaller and published them on GitHub Releases."),
        });
    }
    else if (name == "Resume/CV Builder")
    {
        return vbox({
            BulletPoints("Engineered a responsive CV/Resume application with React.js, supporting real-time data validation and seamless user input for various resume sections."),
            BulletPoints("Designed and implemented reusable React components for modular resume creation, improving maintainability and scalability of the codebase."),
            BulletPoints("Leveraged modern React features (hooks, context API) to manage application state efficiently and ensure a cohesive user experience."),
            BulletPoints("Integrated print and PDF export capabilities, enabling users to download polished resumes directly from the browser."),
            BulletPoints("Ensured accessibility and cross-browser compatibility through semantic HTML and extensive CSS styling.")
        });
    }
    else if (name == "ssh terminal.portfolio")
    {
        return vbox({
            BulletPoints("Coming Soon")
        });
    }
    return text("");
}

Element ProjectDetails(std::string name, std::string date, std::string preview, std::string src, std::string stack) 
{
    return vbox
        ({
            flexbox
            ({
                text(name),
                text(date) | color(Color::GrayDark)
            }, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceBetween)),
            hbox
            ({
                text("[ preview ] "),
                paragraph(preview)
            }) | color(Color::GrayDark),
            hbox
            ({
                text("[   src   ] "),
                paragraph(src)
            }) | color(Color::GrayDark),
            hbox
            ({
                text("[  stack  ] "),
                paragraph(stack)
            }) | color(Color::GrayDark),

            separatorEmpty(),

            ProjectDetailPoints(name)
        });
}

Element Projects() {
    return hbox
    ({
        flexbox
        ({
            paragraph("ssh terminal.portfolio"),
            paragraph("Basic Google Drive"),
            paragraph("Git Gemini Automation Shell Script"),
            paragraph("CLI Art"),
            paragraph("Resume/CV Builder")
        }, FlexboxConfig()
            .Set(FlexboxConfig::Direction::Column)
            .SetGap(0, 1)
        ),
        separatorEmpty(),
        separator(),
        separatorEmpty(),
        ProjectDetails("ssh terminal.portfolio", "January 2025", "ssh terminal.portfolio.shreetej", "https://github.com/yogi1308/terminal-dot-portfolio-TUI", "C++ | CMake")
    });
}