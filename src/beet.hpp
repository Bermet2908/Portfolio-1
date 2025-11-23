#pragma once

#include <string>
#include "plot.hpp"

class Beet : public Plot {
private:
    int age = 0;   // days since planting

public:
    std::string symbol() override;

    void tick() override {
        age += 1;  // one day passes
    }

    bool is_mature() const {
        // 2 days to sprout + 5 days to mature = 7
        return age >= 7;
    }
};
