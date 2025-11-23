#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE("lettuce starts as tilled soil and is not mature") {
    Lettuce l;
    REQUIRE(l.symbol() == ":");
    REQUIRE(l.is_mature() == false);
}

TEST_CASE("lettuce becomes a seedling after two days") {
    Lettuce l;
    l.tick(); // day 1
    REQUIRE(l.symbol() == ":");
    l.tick(); // day 2
    REQUIRE(l.symbol() == "v");
    REQUIRE(l.is_mature() == false);
}

TEST_CASE("lettuce becomes mature L after four days") {
    Lettuce l;
    for (int i = 0; i < 4; ++i) {
        l.tick();
    }
    REQUIRE(l.symbol() == "L");
    REQUIRE(l.is_mature() == true);
}
