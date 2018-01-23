#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/type_traits/remove_reference.hpp>
#include <ctd/type_traits/is_same.hpp>

TEST_CASE("remove_reference", "[remove_reference]")
{
    REQUIRE((ctd::is_same<int, ctd::remove_reference<int>::type>()));
    REQUIRE((ctd::is_same<int, ctd::remove_reference<int&>::type>()));
    REQUIRE((ctd::is_same<int, ctd::remove_reference<int&&>::type>()));
}
