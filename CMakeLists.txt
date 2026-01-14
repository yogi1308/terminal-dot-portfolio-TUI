cmake_minimum_required(VERSION 3.14)
project(TerminalPortfolioTUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(portfolio 
    ./main.cpp
)

target_link_libraries(portfolio PRIVATE
    # Chose a submodule
    ftxui::component
    ftxui::dom
    ftxui::screen
)