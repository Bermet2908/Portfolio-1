#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE("carrot becomes mature V after one day") {
  Carrot c;
  c.tick();
  REQUIRE(c.is_mature() == true);
  REQUIRE(c.symbol() == "V");
}

TEST_CASE("carrot stays mature V after many days") {
  Carrot c;
  c.tick();
  for (int i = 0; i < 10; ++i) c.tick();
  REQUIRE(c.is_mature() == true);
  REQUIRE(c.symbol() == "V");
}