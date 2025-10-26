#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"

TEST_CASE( "it can be initialized with a single plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.number_of_rows() == 2 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE("it allows us to plant a carrot") {
    Player player;
    Farm farm(1, 2, &player);

    REQUIRE(farm.plant_if_empty(0, 1, new Carrot()));
    REQUIRE(farm.get_symbol(0, 1) == "v");
}

TEST_CASE("player stays inside farm boundaries") {
    Player player;
    Farm farm(2, 2, &player);

    farm.move_player_up();
    farm.move_player_left();
    REQUIRE(player.row() == 0);
    REQUIRE(player.column() == 0);

    farm.move_player_right();
    farm.move_player_down();
    REQUIRE(player.row() == 1);
    REQUIRE(player.column() == 1);
}

TEST_CASE("planting works only on empty soil") {
    Player player;
    Farm farm(1, 2, &player);

    bool planted1 = farm.plant_if_empty(0, 1, new Carrot());
    REQUIRE(planted1);

    bool planted2 = farm.plant_if_empty(0, 1, new Carrot());
    REQUIRE_FALSE(planted2);
}

TEST_CASE("harvest works only for mature carrot") {
    Player player;
    Farm farm(1, 2, &player);

    REQUIRE(farm.plant_if_empty(0, 1, new Carrot()));
    REQUIRE_FALSE(farm.harvest_at(0, 1));


    farm.end_day();
    REQUIRE(farm.get_symbol(0, 1) == "V");
    REQUIRE(farm.harvest_at(0, 1));
    REQUIRE(farm.get_symbol(0, 1) == ".");
}

TEST_CASE("end_day increases day counter") {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE(farm.current_day() == 1);
    farm.end_day();
    REQUIRE(farm.current_day() == 2);
}



