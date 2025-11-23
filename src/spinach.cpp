#include "spinach.hpp"

std::string Spinach::symbol() {
    // Days 0–1: still underground
    if (age < 2) {
        return ":";   // tilled soil
    }

    // Days 2–4: seedling (2, 3, 4)
    if (age < 5) {
        return "v";   // spinach seedling
    }

    // Day 5+: mature spinach
    return "S";
}
