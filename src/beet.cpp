#include "beet.hpp"

std::string Beet::symbol() {
    if (age < 2) {
        return ":";
    }

    if (age < 7) {
        return "v";
    }

    return "B";
}
