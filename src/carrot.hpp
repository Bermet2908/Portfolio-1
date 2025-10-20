#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot {
private:
    int age = 0;
public:
    std::string symbol() override;
    void tick() override {
        age += 1;
    }
    bool is_mature() const {
        return age >= 1;
    }
};