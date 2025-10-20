#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"

class Farm {
private:
    int rows;
    int columns;
    int day = 1;
    Player *player;
    std::vector<std::vector<Plot *>> plots;
    bool in_bounds(int r, int c) const;

public:
    Farm(int rows, int columns, Player *player);
    ~Farm();

    int number_of_rows();
    int number_of_columns();

    int current_day() const {
        return day;
    };
    void end_day();

    std::string get_symbol(int row, int column);
    bool plant_if_empty(int row, int column, Plot *plot);
    bool harvest_at (int row, int column);

    void move_player_up();
    void move_player_down();
    void move_player_left();
    void move_player_right();
};