#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if (age == 0) {
        return ":";
    }
    else if (age == 1) {
        return "v";
    }
    else {
        return "V";
    }
}
