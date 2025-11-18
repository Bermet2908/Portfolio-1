#include "lettuce.hpp"

std::string Lettuce::symbol() {
    if (age < 2) {
        return ":";
    }
    if (age < 4) {
        return "v";
    }
    return "L";
}
