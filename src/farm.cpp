#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.hpp"
#include "carrot.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
  for (int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    std::vector<bool> water_row;
    for (int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
      water_row.push_back(false);   // not watered at start
    }
    plots.push_back(row);
    watered.push_back(water_row);
  }
}


Farm::~Farm() {
  for (auto& row : plots) {
    for (auto* p : row) {
      delete p;
    }
  }
}

int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}

bool Farm::in_bounds(int r, int c) const {
  return (r >= 0 && r < rows && c >= 0 && c < columns);
}

void Farm::move_player_up() {
  int r = player->row();
  int c = player->column();
  int nr = r - 1;
  if (in_bounds(nr, c))
    player->set_position(nr, c);
}

void Farm::move_player_down() {
  int r = player->row();
  int c = player->column();
  int nr = r + 1;
  if (in_bounds(nr, c))
    player->set_position(nr, c);
}

void Farm::move_player_left() {
  int r = player->row();
  int c = player->column();
  int nc = c - 1;
  if (in_bounds(r, nc))
    player->set_position(r, nc);
}

void Farm::move_player_right() {
  int r = player->row();
  int c = player->column();
  int nc = c + 1;
  if (in_bounds(r, nc))
    player->set_position(r, nc);
}

void Farm::end_day() {
  day += 1;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      // Normal +1 day growth
      plots[r][c]->tick();

      // If this tile was watered, grow one extra day
      if (watered[r][c]) {
        plots[r][c]->tick();
        watered[r][c] = false;  // reset for the new day
      }
    }
  }
}


std::string Farm::get_symbol(int r, int c) {
  if (player->row() == r && player->column() == c) return "@";
  return plots.at(r).at(c)->symbol();
}

bool Farm::plant_if_empty(int r, int c, Plot* plot) {
  std::string current = plots.at(r).at(c)->symbol();
  if (current != ".") {
    delete plot;
    return false;
  }

  delete plots[r][c];
  plots[r][c] = plot;
  return true;
}

bool Farm::harvest_at(int r, int c) {
  std::string current = plots.at(r).at(c)->symbol();

  // Only harvest mature plants
  if (current != "V" && current != "L" && current != "S" && current != "B" && current != "R") {
    return false;
  }

  delete plots[r][c];
  plots[r][c] = new Soil();
  return true;
}

bool Farm::water_at(int r, int c) {
  // Safety: make sure it's inside the farm
  if (!in_bounds(r, c)) {
    return false;
  }

  std::string current = plots.at(r).at(c)->symbol();

  // If it's bare soil, nothing happens
  if (current == ".") {
    return false;
  }

  // If already watered this day, do nothing extra
  if (watered[r][c]) {
    return false;
  }

  // Mark this tile as watered for today
  watered[r][c] = true;
  return true;
}



