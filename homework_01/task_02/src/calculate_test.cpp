#include "catch2/catch_test_macros.hpp"
#include <catch2/catch_approx.hpp>


#include "utils.hpp"

TEST_CASE("Calculate", "[simple_sum]") {
  CHECK(Calculate("1+2") == 3);
  CHECK(Calculate("2+2") == 4);
  CHECK(Calculate("1+0") == 1);
  CHECK(Calculate("0+0") == 0);
}

TEST_CASE("Calculate", "[simple_difference]") {
  CHECK(Calculate("5-2") == 3);
  CHECK(Calculate("2-2") == 0);
  CHECK(Calculate("1-0") == 1);
  CHECK(Calculate("0-0") == 0);
}

TEST_CASE("Calculate", "[simple_multiply]") {
  CHECK(Calculate("5*2") == 10);
  CHECK(Calculate("2*2") == 4);
  CHECK(Calculate("1*0") == 0);
  CHECK(Calculate("0*0") == 0);
}

TEST_CASE("Calculate", "[simple_division]") {
  CHECK(Calculate("10/2") == 5);
  CHECK(Calculate("4/2") == 2);
  CHECK(Calculate("0/1") == 0);
}

TEST_CASE("Calculate", "[negative_numbers]") {
  CHECK(Calculate("-3-2") == -5);
  CHECK(Calculate("-6/2") == -3);
  CHECK(Calculate("-8+5") == -3);
  CHECK(Calculate("-6*2") == -12);
}

TEST_CASE("Calculate", "[simple_exponentiation]") {
  CHECK(Calculate("3^2") == 9);
  CHECK(Calculate("-2.5^2") == Catch::Approx(6.25));
  CHECK(Calculate("-3.5^0") == 1);
  CHECK(Calculate("0^2") == Catch::Approx(0));
}


TEST_CASE("Calculate", "[fractional numbers]") {
  CHECK(Calculate("6.2*10") == Catch::Approx(62));
  CHECK(Calculate("-1.5+2.5") == Catch::Approx(1));
  CHECK(Calculate("-3.5/3.5") == Catch::Approx(-1));
  CHECK(Calculate("-3.5-3.5") == Catch::Approx(-7));
}

TEST_CASE("Calculate", "[advanced_expressions]") {
  CHECK(Calculate("6+10/2*2/2-1") == 10);
  CHECK(Calculate("(2+3)+5") == 10);
  CHECK(Calculate("(-2)+(-2)*(-2)^2") == -10);
  CHECK(Calculate("(3/10)+(2.5*2)") == Catch::Approx(5.3));
  CHECK(Calculate("3+((-7)-5/(2+3))*(7-2.5)") == -33);
}