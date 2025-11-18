#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if (age == 0) {
        return ":";   // tilled soil
    }
    else if (age == 1) {
        return "v";   // seedling
    }
    else {
        return "V";   // mature carrot
    }
}
