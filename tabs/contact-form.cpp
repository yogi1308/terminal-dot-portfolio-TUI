#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

std::string name = "";
std::string email = "";
std::string message = "";

Component input_name = Input(&name);
Component input_email = Input(&email);
Component input_message = Input(&message);

auto contact_form_container = Container::Vertical({
    input_name,
    input_email,
    input_message,
});

Element ContactForm(Component name_comp, Component email_comp, Component message_comp, std::string status_message, Color status_color) {
    
    auto arrow_style = [&](Component comp) {
        auto visual = text("> ") | color(Color::RGB(77, 163, 255));
        if (comp->Focused()) {
            return visual | blink; 
        }
        return text("");
    };

    auto input_style = [&](Component comp) {
        if (comp->Focused()) {
            return comp->Render() | inverted;
        }
        return comp->Render();
    };

    return vbox({
        text("send me a message") | bold | color(Color::RGB(77, 163, 255)),
        separator(),
        separatorEmpty(),
        vbox({
            text("name:") | color(Color::Default), 
            hbox({
                arrow_style(name_comp),
                input_style(name_comp)
            })
        }),
        separatorEmpty(),
        vbox({
            text("email:") | color(Color::Default), 
            hbox({
                arrow_style(email_comp),
                input_style(email_comp)
            })
        }),
        separatorEmpty(),
        vbox({
            text("message:") | color(Color::Default), 
            hbox({
                arrow_style(message_comp),
                input_style(message_comp)
            })
        }) | flex,
        
        separatorEmpty(),
        text(status_message) | center | bold | color(status_color)
    });
}