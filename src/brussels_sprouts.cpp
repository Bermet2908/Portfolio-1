#include "brussels_sprouts.hpp"

std::string BrusselsSprouts::symbol() {
    if (age < 5) {
        return ":";
    }

    if (age < 15) {
        return "v";
    }

    return "R";
}