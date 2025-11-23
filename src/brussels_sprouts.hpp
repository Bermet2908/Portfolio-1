#pragma once

#include <string>
#include "plot.hpp"

class BrusselsSprouts : public Plot {
private:
    int age = 0;   // days since planting

public:
    std::string symbol() override;

    void tick() override {
        age += 1;  // one day passes
    }

    bool is_mature() const {
        // 5 days to sprout + 10 days to mature = 15
        return age >= 15;
    }
};
