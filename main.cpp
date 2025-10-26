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

        if (key == 'w') {
            farm.move_player_up();
        }
        else if (key == 'a') {
            farm.move_player_left();
        }
        else if (key == 's') {
            farm.move_player_down();
        }
        else if (key == 'd') {
            farm.move_player_right();
        }
        else if (key == 'p') {
            farm.plant_if_empty(player.row(), player.column(), new Carrot());
        }
        else if (key == 'h') {
            farm.harvest_at(player.row(), player.column());
        }
        else if (key == 'e') {
            farm.end_day();
        }
        else if (key == 'q') {
            game_in_progress = false;
        }
        else if (key == '?') {
            printLegend();
        }
        else {
            std::cout << "Unknown command. Type ? for help.\n";
        }

    }
}