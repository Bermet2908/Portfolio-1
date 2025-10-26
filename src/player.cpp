#include "player.hpp"

int Player::row() {
    return current_row;
}

int Player::column() {
    return current_column;
}

void Player::set_position(int r, int c) {
    current_row = r;
    current_column = c;
}