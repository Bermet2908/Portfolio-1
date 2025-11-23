#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussels_sprouts.hpp"

TEST_CASE("brussels sprouts start as tilled soil and are not mature") {
    BrusselsSprouts b;
    REQUIRE(b.symbol() == ":");
    REQUIRE(b.is_mature() == false);
}

TEST_CASE("brussels sprouts become seedlings after five days") {
    BrusselsSprouts b;
    for (int i = 0; i < 5; ++i) {
        b.tick();
    }
    REQUIRE(b.symbol() == "v");
    REQUIRE(b.is_mature() == false);
}

TEST_CASE("brussels sprouts become mature after fifteen days") {
    BrusselsSprouts b;
    for (int i = 0; i < 15; ++i) {
        b.tick();
    }
    REQUIRE(b.symbol() == "R");
    REQUIRE(b.is_mature() == true);
}
