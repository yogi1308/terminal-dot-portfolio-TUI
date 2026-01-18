#include <string>
#include <ftxui/screen/color.hpp>

using namespace ftxui;

bool validate_input(const std::string& name, const std::string& email, const std::string& message, std::string& status_msg, Color& status_color) {
    if (name.empty()) {
        status_msg = "Error: Name is required!";
        status_color = Color::Red;
        return false;
    }
    else if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
        status_msg = "Error: Invalid Email!";
        status_color = Color::Red;
        return false;
    }
    else if (message.empty()) {
        status_msg = "Error: Message cannot be empty!";
        status_color = Color::Red;
        return false;
    }
    
    status_msg = "Sending...";
    status_color = Color::Green;
    return true;
}