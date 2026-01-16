#include <ftxui/component/component.hpp>          // Import component logic (Renderer, Buttons, etc.)
#include <ftxui/component/screen_interactive.hpp> // Import the engine that manages the terminal window
#include <ftxui/dom/elements.hpp>                 // Import visual elements (text, border, vbox, filler)

using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

Element RenderNavbar()
{
    FlexboxConfig config;
    config.justify_content = FlexboxConfig::JustifyContent::SpaceEvenly;

    return flexbox({
        text(" shreetej hadge ") | center,
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

// Element blinker() {
    
// }


int main()
{

    auto renderer = Renderer([] { // Create a component that defines how to draw the UI
        Element navbar = RenderNavbar();
        
        auto body = filler() | border;

        return vbox({navbar,body});
    });

    auto screen = ScreenInteractive::Fullscreen(); // Initialize the screen in "Alternate Buffer" mode (like vim)
    screen.Loop(renderer);                         // Start the infinite event loop (blocks here until quit)

    return 0; // Exit program (only reached if the loop is broken)
}