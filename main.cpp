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
#include "helpers/validate-input.cpp"
#include "helpers/send-message.cpp"

using namespace ftxui;

const int MIN_WIDTH = 110;
const int TARGET_AREA = 3500;   // The "Total Space" you need (e.g. 100x30 = 3000)

// Helper to calculate height using INVERSE ratio
int get_min_height(int current_width) {
    if (current_width <= 0) return 999; // Safety check
    return TARGET_AREA / current_width;
}

Element blinker(bool is_visible) {
    return is_visible ? text("█") | color(Color::RGB(77, 163, 255)) : text(" ");
}


int main()
{
    bool show_blinker = true;
    bool show_contact_form = false;
    int tab_index{0}, exp_tab{0}, proj_tab{0}, contact_tab{0};
    auto screen = ScreenInteractive::Fullscreen();
    bool blink_state = true;
    std::string form_status = "";
    Color form_status_color = Color::Default;

    using namespace std::chrono_literals; // loader
    std::thread([&] {
        for (int i = 0; i < 7.5; ++i) {  // Loop 20 times: 20 * 0.5s = 10 seconds
            std::this_thread::sleep_for(0.5s); 
            blink_state = !blink_state;  
            screen.Post(Event::Custom);  
        }
        show_blinker = false; 
        screen.Post(Event::Custom);      
    }).detach();

    auto renderer = Renderer([&] { 
        auto term_size = Terminal::Size();
        int req_height = get_min_height(term_size.dimx);
        if (term_size.dimx < MIN_WIDTH || term_size.dimy < req_height) {
            return hbox({
                text("please resize your terminal, your terminal window is not big enough or zoom out") | bold, // blinker()
            }) | center ;
        }
        if (show_blinker) {
            FlexboxConfig config;
            config.justify_content = FlexboxConfig::JustifyContent::Center;

            return flexbox({
                text("shreetej hadge"),
                blinker(blink_state),
            }, config) | center;
        }
        else {
            Element navbar = Navbar(tab_index);
            Element body;
            Element footer;
            if (tab_index == 3 && show_contact_form) {
                body = ContactForm(input_name, input_email, input_message, form_status, form_status_color) | borderEmpty;
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
        auto term_size = Terminal::Size();
        int req_height = get_min_height(term_size.dimx);
        if (event == Event::Character('q') && !show_contact_form){screen.Exit(); return true;}
        else if (term_size.dimx < MIN_WIDTH || term_size.dimy < req_height) {return true;}
        else if (event == Event::Character('a') && !show_contact_form) { tab_index = 0; return true;}
        else if (event == Event::Character('e') && !show_contact_form){tab_index = 1; return true;}
        else if (event == Event::Character('p') && !show_contact_form){tab_index = 2; return true;}
        else if (event == Event::Character('c') && !show_contact_form){tab_index = 3; return true;}
        else if (event == Event::ArrowUp && tab_index == 1 && !show_contact_form) {exp_tab--;}
        else if (event == Event::ArrowDown && tab_index == 1 && !show_contact_form) {exp_tab++;}
        else if (event == Event::ArrowUp && tab_index == 2 && !show_contact_form) {proj_tab--;}
        else if (event == Event::ArrowDown && tab_index == 2 && !show_contact_form) {proj_tab++;}
        else if (event == Event::ArrowUp && tab_index == 3 && !show_contact_form) {contact_tab--;}
        else if (event == Event::ArrowDown && tab_index == 3 && !show_contact_form) {contact_tab++;}
        else if (event == Event::Return && tab_index == 3 && !show_contact_form) {show_contact_form = true; return true;}
        else if (event == Event::Escape && show_contact_form) {show_contact_form = false; return true;}
        else if (event == Event::Special({19}) && show_contact_form) {
            bool is_valid = validate_input(name, email, message, form_status, form_status_color); 
            if (is_valid) {
                form_status = "Sending...";
                form_status_color = Color::Yellow;
                
                std::thread([&, name_val=name, email_val=email, msg_val=message] { // Spawn a detached thread so the UI doesn't freeze while waiting for curl
                    
                    bool success = send_message(name_val, email_val, msg_val);

                    if (success) {
                        form_status = "Message Sent Successfully!";
                        form_status_color = Color::Green;
                        name = ""; email = ""; message = "";
                    } else {
                        form_status = "Error: Failed to send message.";
                        form_status_color = Color::Red;
                    }
                    
                    screen.Post(Event::Custom); // Wake up the UI to show the new status
                }).detach();
            }
            return true;
        }
        else if (show_contact_form) {if (contact_form_container->OnEvent(event)) return true;}

        return false;
    });

    screen.Loop(component);                      


    return 0; 
}