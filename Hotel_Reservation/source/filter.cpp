#include "../header/filter.hpp"

Filter::Filter(const std::string& _name) {
    name = _name;
}

std::string Filter::get_name() {return name;}

