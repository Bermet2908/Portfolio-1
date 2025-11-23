#include "beet.hpp"

std::string Beet::symbol() {
    // Days 0–1: still underground
    if (age < 2) {
        return ":";   // tilled soil
    }

    // Days 2–6: seedling
    if (age < 7) {
        return "v";   // beet seedling
    }

    // Day 7+: mature beet
    return "B";
}
