#pragma once

using namespace std;
void printLegend() {
    cout << "Welcome to Farming Stimulator! 🧑‍🌾\n\n";

    cout<< "Your goal is to take care of your farm — move around, plant vegetables, harvest them, and end your day.\n"
           <<"Each new day, your plants grow and your farm comes to life!\n\n";

    cout<< "🌱Game rules \n"
<< " 1) The game starts on Day 1. \n"
<< " 2) You can only plant on empty soil.\n"
<< " 3) You can harvest only mature plants.\n"
<< " 4) You can’t move outside the farm — the borders keep you inside.\n"
<< " 5) End the day when you’re done planting or harvesting.\n\n";

cout<< "How to move your character?\n"
    << "Use these keys to move your farmer around the farm:\n";

    cout << "W/A/S/D - Move Up/Left/Down/Right\n";
    cout << "P - Plant a vegetable\n";
    cout << "H - Harvest vegetables\n";
    cout << "E - End the day\n";
    cout << "Q - Quit game\n";
    cout << "? - Show legend again\n";

    cout << "========================\n";
}