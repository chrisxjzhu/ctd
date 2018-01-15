#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/type_traits/is_same.hpp>

TEST_CASE("is_same", "[is_same]")
{
    REQUIRE(ctd::is_same<int, signed int>::value == true);
    REQUIRE(ctd::is_same<int, unsigned int>() == false);
    REQUIRE(ctd::is_same<char, signed char>() == false);
    REQUIRE(ctd::is_same<int, int&>() == false);
}
