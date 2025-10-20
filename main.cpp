#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"
#include "src/legend.hpp"

int main() {
    printLegend();

    Player player;
    Farm farm(7, 8, &player);
    FarmPrinter printer(&farm);
    bool game_in_progress = true;
    char key;

    while(game_in_progress) {
        ansi_clear();

        std::cout << "Day: " << farm.current_day() << "\n";
        std::cout << printer.pp() << std::endl;
        std::cout << "(W/A/S/D to move, P, H, E, Q to quit) > ";

        if (!(std::cin >> key))
            break;
        if (key >= 'A' && key <= 'Z') key = char(key - 'A' + 'a');

        switch (key) {
            case 'w': farm.move_player_up();
                break;
            case 'a': farm.move_player_left();
                break;
            case 's': farm.move_player_down();
                break;
            case 'd': farm.move_player_right();
                break;

            case 'q': game_in_progress = false;
                break;
            case 'p': {
                farm.plant_if_empty(player.row(), player.column(), new Carrot());
            } break;

            case 'h': {
                farm.harvest_at(player.row(), player.column());
            } break;

            case 'e': {
                farm.end_day();
            } break;

            case '?': printLegend(); break;


            default:
                break;
        }
    }
}