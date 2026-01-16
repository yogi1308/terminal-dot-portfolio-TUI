#include <ftxui/component/component.hpp>          // Import component logic (Renderer, Buttons, etc.)
#include <ftxui/component/screen_interactive.hpp> // Import the engine that manages the terminal window
#include <ftxui/dom/elements.hpp>                 // Import visual elements (text, border, vbox, filler)

int main()
{
    using namespace ftxui; // Save typing: allows writing 'text' instead of 'ftxui::text'

    auto renderer = Renderer([] { // Create a component that defines how to draw the UI
        return filler() | border; // "filler()" takes all space, "| border" draws a box around it
    });

    auto screen = ScreenInteractive::Fullscreen(); // Initialize the screen in "Alternate Buffer" mode (like vim)
    screen.Loop(renderer);                         // Start the infinite event loop (blocks here until quit)

    return 0; // Exit program (only reached if the loop is broken)
}