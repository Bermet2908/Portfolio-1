#include "brussels_sprouts.hpp"

std::string BrusselsSprouts::symbol() {
    // Days 0–4: still underground
    if (age < 5) {
        return ":";    // tilled soil
    }

    // Days 5–14: seedling
    if (age < 15) {
        return "v";    // brussels sprouts seedling
    }

    // Day 15+: mature brussels sprouts
    return "R";        // adult plant (unique symbol)
}
