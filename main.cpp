#include "ColorCout.hpp"

int main() {
    std::cout << cc::red << " red "
              << cc::yellow << " yellow "
              << cc::green << " green "
              << cc::cyan << " cyan "
              << cc::blue << " blue "
              << cc::magenta << " magenta "
              << cc::grey << " grey "
              << cc::white << " white "
              << cc::reset << " reset"
              << std::endl;
    std::cout << cc::red << cc::on_cyan << " red "
              << cc::yellow << cc::on_blue << " yellow "
              << cc::green << cc::on_magenta << " green "
              << cc::cyan << cc::on_red << " cyan "
              << cc::blue << cc::on_yellow << " blue "
              << cc::magenta << cc::on_green << " magenta "
              << cc::grey << cc::on_white << " grey "
              << cc::white << cc::on_grey << " white "
              << cc::reset << " reset"
              << std::endl;
}