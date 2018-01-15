#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/type_traits/integral_constant.hpp>

TEST_CASE("integral_constant", "[integral_constant]")
{
    typedef ctd::integral_constant<int, 2> two_t;
    typedef ctd::integral_constant<int, 4> four_t;
    REQUIRE((two_t::value * 2 == four_t::value));

    two_t  two;
    REQUIRE(two == 2);
    REQUIRE(two() == 2);
    REQUIRE(two_t() == 2);
}

TEST_CASE("bool_constant", "[bool_constant]")
{
    ctd::bool_constant<true> t;
    ctd::bool_constant<false> f;
    REQUIRE(t);
    REQUIRE(!f);
}
