#include <ftxui/component/component.hpp>          // Import component logic (Renderer, Buttons, etc.)
#include <ftxui/component/screen_interactive.hpp> // Import the engine that manages the terminal window
#include <ftxui/dom/elements.hpp>                 // Import visual elements (text, border, vbox, filler)

#include <thread>
#include <chrono>

#include "tabs/about-me.cpp"

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

Element RenderNavbar()
{
    FlexboxConfig config;
    config.justify_content = FlexboxConfig::JustifyContent::SpaceEvenly;

    return flexbox({
        text("shreetej hadge") | center,
        separatorLight() | color(Color::GrayDark),
        hbox({text("a"), text(" about me") | color(Color::GrayDark) | center}),
        separatorLight() | color(Color::GrayDark),
        hbox({text("e"), text(" experience") | color(Color::GrayDark) | center}),
        separatorLight() | color(Color::GrayDark),
        hbox({text("p"), text(" projects") | color(Color::GrayDark) | center}),
        separatorLight() | color(Color::GrayDark),
        hbox({text("c"), text(" contact me") | color(Color::GrayDark) | center})
    }, config) | borderStyled(LIGHT, Color::GrayDark);
}

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
    auto renderer = Renderer([&] { // Create a component that defines how to draw the UI
        if (show_blinker) {
            return blinker() | center;
        }
        else {
            Element navbar = RenderNavbar();

            auto body = aboutMe() | flex;

            int width = Terminal::Size().dimx;

            return vbox({navbar,body});
        }
    });

    auto screen = ScreenInteractive::Fullscreen(); // Initialize the screen in "Alternate Buffer" mode (like vim)

    using namespace std::chrono_literals;
    std::thread([&] {
        std::this_thread::sleep_for(0s); // Wait
        show_blinker = false;              // Flip switch
        screen.Post(Event::Custom);      // Wake up screen
    }).detach();                         // Run in background

    screen.Loop(renderer);                         // Start the infinite event loop (blocks here until quit)


    return 0; // Exit program (only reached if the loop is broken)
}