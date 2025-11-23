#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE("spinach starts as tilled soil and is not mature") {
    Spinach s;
    REQUIRE(s.symbol() == ":");
    REQUIRE(s.is_mature() == false);
}

TEST_CASE("spinach becomes a seedling after two days") {
    Spinach s;
    s.tick(); // day 1
    REQUIRE(s.symbol() == ":");
    s.tick(); // day 2
    REQUIRE(s.symbol() == "v");
    REQUIRE(s.is_mature() == false);
}

TEST_CASE("spinach becomes mature S after five days") {
    Spinach s;
    for (int i = 0; i < 5; ++i) {
        s.tick();
    }
    REQUIRE(s.symbol() == "S");
    REQUIRE(s.is_mature() == true);
}
