#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE("carrot starts as tilled soil and is not mature") {
    Carrot c;
    REQUIRE(c.symbol() == ":");
    REQUIRE(c.is_mature() == false);
}

TEST_CASE("carrot becomes a seedling after one day") {
    Carrot c;
    c.tick(); // 1 day
    REQUIRE(c.symbol() == "v");
    REQUIRE(c.is_mature() == false);
}

TEST_CASE("carrot becomes mature V after two days") {
    Carrot c;
    c.tick(); // day 1
    c.tick(); // day 2
    REQUIRE(c.symbol() == "V");
    REQUIRE(c.is_mature() == true);
}

