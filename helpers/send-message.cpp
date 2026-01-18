#include <cstdlib>
#include <string>
#include <regex>

std::string CleanString(std::string input) { // Helper to escape quotes so the shell command doesn't break
    return std::regex_replace(input, std::regex("\""), "\\\"");
}

bool send_message(std::string name, std::string email, std::string message) {
    std::string cmd = "curl -X POST -H \"Accept: application/json\" ";
    cmd += "-H \"Referer: https://yogi-portfolio.eastus.cloudapp.azure.com\" ";
    cmd += "https://formspree.io/f/xkoooazy "; 
    cmd += "-d \"name=" + CleanString(name) + "\" ";
    cmd += "-d \"email=" + CleanString(email) + "\" ";
    cmd += "-d \"message=" + CleanString(message) + "\"";
    cmd += " > /dev/null 2>&1"; // Silence output so it doesn't mess up the TUI

    int result = std::system(cmd.c_str());
    return (result == 0);
}