#pragma once

#include <string>

class Plot {
public:
    virtual ~Plot() = default;
    virtual std::string symbol() = 0;
    virtual void tick() {}
};