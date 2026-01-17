#include <ftxui/component/component.hpp>          // Import component logic (Renderer, Buttons, etc.)
#include <ftxui/component/screen_interactive.hpp> // Import the engine that manages the terminal window
#include <ftxui/dom/elements.hpp>                 // Import visual elements (text, border, vbox, filler)
#include "ftxui/component/event.hpp"

#include <thread>
#include <chrono>

#include "tabs/about-me.cpp"
#include "tabs/experience.cpp"
#include "tabs/projects.cpp"
#include "tabs/contact-me.cpp"
#include "components/navbar.cpp"

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

Element blinker() {
    FlexboxConfig config;
    config.justify_content = FlexboxConfig::JustifyContent::Center;

    return flexbox({
        text("shreetej hadge"),
        blink(text("█") | color(Color::RGB(77, 163, 255))) 
    }, config);
}


int main()
{
    bool show_blinker = true;
    int tab_index = 0;
    auto screen = ScreenInteractive::Fullscreen(); // Initialize the screen in "Alternate Buffer" mode (like vim)

    using namespace std::chrono_literals; // loader
    std::thread([&] {
        std::this_thread::sleep_for(0s); // Wait
        show_blinker = false;              // Flip switch
        screen.Post(Event::Custom);      // Wake up screen
    }).detach();                         // Run in background

    auto renderer = Renderer([&] { // Create a component that defines how to draw the UI
        if (show_blinker) {
            return blinker() | center;
        }
        else {
            Element navbar = Navbar(tab_index);
            Element body;
            switch (tab_index) {
                case 0: body = AboutMe() | borderEmpty; break;
                case 1: body = Experience() | borderEmpty; break;
                case 2: body = Projects() | borderEmpty; break;
                case 3: body = ContactMe() | borderEmpty; break; 
                default: body = AboutMe() | borderEmpty; break;
            }

            int width = Terminal::Size().dimx;

            return vbox({navbar,body})| borderEmpty;
        }
    });

    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('a')) { tab_index = 0; return true; }
        else if (event == Event::Character('e')){tab_index = 1; return true;}
        else if (event == Event::Character('p')){tab_index = 2; return true;}
        else if (event == Event::Character('c')){tab_index = 3; return true;}
        else if (event == Event::Character('q') || event == Event::Escape){screen.Exit(); return true;}
        return false;
    });

    screen.Loop(component);                         // Start the infinite event loop (blocks here until quit)


    return 0; // Exit program (only reached if the loop is broken)
}