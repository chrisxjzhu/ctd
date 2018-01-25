#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/type_traits/is_reference.hpp>

struct A {};

TEST_CASE("is_lvalue_reference", "[is_reference]")
{
    REQUIRE(ctd::is_lvalue_reference<A>::value   == false);
    REQUIRE(ctd::is_lvalue_reference<A&>::value  == true);
    REQUIRE(ctd::is_lvalue_reference<A&&>::value == false);

    REQUIRE(ctd::is_lvalue_reference<int>::value   == false);
    REQUIRE(ctd::is_lvalue_reference<int&>::value  == true);
    REQUIRE(ctd::is_lvalue_reference<int&&>::value == false);
}

TEST_CASE("is_rvalue_reference", "[is_reference]")
{
    REQUIRE(ctd::is_rvalue_reference<A>::value   == false);
    REQUIRE(ctd::is_rvalue_reference<A&>::value  == false);
    REQUIRE(ctd::is_rvalue_reference<A&&>::value == true);

    REQUIRE(ctd::is_rvalue_reference<int>::value   == false);
    REQUIRE(ctd::is_rvalue_reference<int&>::value  == false);
    REQUIRE(ctd::is_rvalue_reference<int&&>::value == true);
}
