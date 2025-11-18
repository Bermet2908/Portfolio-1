#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.hpp"
#include "carrot.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
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
  for (auto& row : plots) {
    for (auto* p : row) {
      p->tick();
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

  if (current != "V" && current != "L") {
    return false;
  }

  delete plots[r][c];
  plots[r][c] = new Soil();
  return true;
}

