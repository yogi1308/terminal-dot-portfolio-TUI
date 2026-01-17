#include <ftxui/dom/elements.hpp>

using namespace ftxui;

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
        vbox
        ({
            flexbox
            ({
                text("Basic Google Drive"),
                text("December 2025") | color(Color::GrayDark)
            }, FlexboxConfig().Set(FlexboxConfig::JustifyContent::SpaceBetween)),
            hbox
            ({
                text("[ preview ] "),
                paragraph("https://file-uploader-orpin.vercel.app/")
            }) | color(Color::GrayDark),
            hbox
            ({
                text("[   src   ] "),
                paragraph("https://github.com/yogi1308/terminal-dot-portfolio-TUI")
            }) | color(Color::GrayDark),
            hbox
            ({
                text("[  stack  ] "),
                paragraph("Node.js | Express | PostgreSQL | Prisma | Cloudinary | Embedded JavaScript(ejs)")
            }) | color(Color::GrayDark),

            separatorEmpty(),

            vbox
            ({
                hbox
                ({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Developed a full-stack file storage application using Node.js, Express, and PostgreSQL (via Prisma ORM) to efficiently manage user data and complex file hierarchies.")
                }),
                
                hbox({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Integrated Cloudinary API for scalable cloud storage, enabling real-time uploads, folder management, and automatic categorization of assets into photos, videos, and documents.")
                }),
                
                hbox({
                    text("> ") | color(Color::RGB(77, 163, 255)),
                    paragraph("Implemented secure user authentication with Passport.js and deployed the application on a serverless architecture using Vercel and Neon for high availability and performance.")
                })
            })
        })
    });
}