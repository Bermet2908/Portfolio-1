#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE("beet starts as tilled soil and is not mature") {
    Beet b;
    REQUIRE(b.symbol() == ":");
    REQUIRE(b.is_mature() == false);
}

TEST_CASE("beet becomes a seedling after 2 days") {
    Beet b;
    b.tick(); // day 1
    REQUIRE(b.symbol() == ":");
    b.tick(); // day 2
    REQUIRE(b.symbol() == "v");
    REQUIRE(b.is_mature() == false);
}

TEST_CASE("beet becomes mature B after 7 days") {
    Beet b;
    for (int i = 0; i < 7; ++i) {
        b.tick();
    }
    REQUIRE(b.symbol() == "B");
    REQUIRE(b.is_mature() == true);
}
