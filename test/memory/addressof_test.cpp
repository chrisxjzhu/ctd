#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/memory/addressof.hpp>

TEST_CASE("addressof", "[addressof]")
{
    int x;
    REQUIRE(ctd::addressof(x) == &x);

    struct A {
        std::string s;
        double d[10];
    } a;
    REQUIRE(ctd::addressof(a.d[5]) == &a.d[5]);

    REQUIRE((noexcept(ctd::addressof(x))));
}
