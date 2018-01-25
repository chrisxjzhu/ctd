#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/functional/reference_wrapper.hpp>
#include <functional>

int foo(int& n1, int& n2, const int& /* n3 */)
{
    ++n1;
    ++n2;
    return n1;
}

TEST_CASE("ref, cref", "[reference_wrapper]")
{
    int n1 = 0, n2 = 0, n3 = 0;

    std::function<int()> bound_foo = std::bind(foo, n1, ctd::ref(n2), ctd::cref(n3));

    n1 = n2 = n3 = 10;

    REQUIRE(bound_foo() == 1);
    REQUIRE(n1 == 10);
    REQUIRE(n2 == 11);
    REQUIRE(n3 == 10);
}
