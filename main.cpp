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
#include "components/footer.cpp"
#include "tabs/contact-form.cpp"

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
    bool show_contact_form = false;
    int tab_index{0}, exp_tab{0}, proj_tab{0}, contact_tab{0};
    auto screen = ScreenInteractive::Fullscreen();

    using namespace std::chrono_literals; // loader
    std::thread([&] {
        std::this_thread::sleep_for(0s); // Wait
        show_blinker = false;              // Flip switch
        screen.Post(Event::Custom);      // Wake up screen
    }).detach();                         // Run in background

    auto renderer = Renderer([&] { 
        if (show_blinker) {
            return blinker() | center;
        }
        else {
            Element navbar = Navbar(tab_index);
            Element body;
            Element footer;
            if (tab_index == 3 && show_contact_form) {
                body = ContactForm(input_name, input_email, input_message) | borderEmpty;
                footer = Footer("contact form");
            }
            else {
                switch (tab_index) {
                    case 0: body = AboutMe() | borderEmpty; footer = Footer("about me"); break;
                    case 1: body = Experience(exp_tab) | borderEmpty; footer = Footer("experience"); break;
                    case 2: body = Projects(proj_tab) | borderEmpty; footer = Footer("projects"); break;
                    case 3: body = ContactMe(contact_tab) | borderEmpty; footer = Footer("contact me"); break; 
                    default: body = AboutMe() | borderEmpty; break;
                }
            }

            int width = Terminal::Size().dimx;

            return vbox({navbar, body | flex, separator() | color(Color::GrayDark), footer})| borderEmpty;
        }
    });

    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('a') && !show_contact_form) { tab_index = 0; return true; }
        else if (event == Event::Character('e') && !show_contact_form){tab_index = 1; return true;}
        else if (event == Event::Character('p') && !show_contact_form){tab_index = 2; return true;}
        else if (event == Event::Character('c') && !show_contact_form){tab_index = 3; return true;}
        else if (event == Event::Character('q') && !show_contact_form){screen.Exit(); return true;}
        else if (event == Event::ArrowUp && tab_index == 1 && !show_contact_form) {exp_tab--;}
        else if (event == Event::ArrowDown && tab_index == 1 && !show_contact_form) {exp_tab++;}
        else if (event == Event::ArrowUp && tab_index == 2 && !show_contact_form) {proj_tab--;}
        else if (event == Event::ArrowDown && tab_index == 2 && !show_contact_form) {proj_tab++;}
        else if (event == Event::ArrowUp && tab_index == 3 && !show_contact_form) {contact_tab--;}
        else if (event == Event::ArrowDown && tab_index == 3 && !show_contact_form) {contact_tab++;}
        else if (event == Event::Return && tab_index == 3 && !show_contact_form) {show_contact_form = true; return true;}
        else if (event == Event::Escape && show_contact_form) {show_contact_form = false; return true;}
        else if (show_contact_form) {if (contact_form_container->OnEvent(event)) return true;}

        return false;
    });

    screen.Loop(component);                      


    return 0; 
}