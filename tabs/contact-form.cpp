#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

// Store the data
std::string name = "";
std::string email = "";
std::string message = "";

// Initialize Components (Standard, Basic Inputs)
Component input_name = Input(&name, "Enter your name...");
Component input_email = Input(&email, "Enter your email...");
Component input_message = Input(&message, "Type your message here...");

// The Container allows navigation (Tab / Arrow Keys)
auto contact_form_container = Container::Vertical({
    input_name,
    input_email,
    input_message,
});

Element ContactForm(Component name_comp, Component email_comp, Component message_comp) {
    return vbox({
        text("send me a message") | bold | color(Color::RGB(77, 163, 255)),
        separator(),
        separatorEmpty(),
        vbox({
            text("name:") | color(Color::GrayDark), 
            hbox({
                text("> ") | color(Color::RGB(77, 163, 255)),
                name_comp->Render()
            })
        }),
        separatorEmpty(),
        vbox({
            text("email:") | color(Color::GrayDark), 
            hbox({
                text("> ") | color(Color::RGB(77, 163, 255)),
                email_comp->Render()
            })
        }),
        separatorEmpty(),
        vbox({
            text("message:") | color(Color::GrayDark), 
            hbox({
                text("> ") | color(Color::RGB(77, 163, 255)),
                message_comp->Render() 
            })
        }) | flex
    });
}