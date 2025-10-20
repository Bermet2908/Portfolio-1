#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    return (age >= 1) ? "V" : "v";
}
