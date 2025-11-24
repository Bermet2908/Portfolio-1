#include "spinach.hpp"

std::string Spinach::symbol() {
    if (age < 2) {
        return ":";
    }

    if (age < 5) {
        return "v";
    }

    return "S";
}
