#pragma once

#include <string>
#include "plot.hpp"

class Spinach : public Plot {
private:
    int age = 0;   // days since planting

public:
    std::string symbol() override;

    void tick() override {
        age += 1;  // one day passes
    }

    bool is_mature() const {
        // for now: mature starting at age 3 (you can tweak later)
        return age >= 5;
    }
};
