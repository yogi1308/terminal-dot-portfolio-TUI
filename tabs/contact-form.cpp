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


ButtonOption send_style = []() {
    ButtonOption opt = ButtonOption::Simple();
    opt.transform = [](const EntryState& s) {
        // Basic element: Text with some padding
        auto element = text(s.label) | borderRounded | center; 

        if (s.focused) {
            // FOCUSED: Blue Background, White Text (Looks like a filled button)
            element |= color(Color::RGB(77, 163, 255)) | bold;
        } else {
            // UN-FOCUSED: Blue Text, Transparent Background (Looks like an outlined button)
            element |= color(Color::White);
        }
        return element;
    };
    return opt;
}();
Component btn_send = Button("   Send Message   ", []{}, send_style);

// The Container allows navigation (Tab / Arrow Keys)
auto contact_form_container = Container::Vertical({
    input_name,
    input_email,
    input_message,
    btn_send
});

Element ContactForm(Component name_comp, Component email_comp, Component message_comp, Component btn_comp, std::string status_message, Color status_color) {
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
        }) | flex,
        btn_comp->Render() | center, 
        separatorEmpty(),
        text(status_message) | center | bold | color(status_color)
    });
}