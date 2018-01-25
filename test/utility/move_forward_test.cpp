#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/utility/move_forward.hpp>
#include <vector>

TEST_CASE("move", "[move_forward]")
{
    std::string str = "Hello";
    std::vector<std::string> vec;

    vec.push_back(ctd::move(str));
    REQUIRE(str.empty());
}

bool r1{false}, r2{false}, r3{false}, r4{false};

void func(int&)        { r1 = true; }
void func(int&&)       { r2 = true; }
void func(const int&)  { r3 = true; }
void func(const int&&) { r4 = true; }

template<typename T>
void run_func(T&& t)
{
    func(ctd::forward<T>(t));
}

TEST_CASE("forward", "[move_forward]")
{
    int i = 1;
    const int j = 1;

    run_func(i);
    REQUIRE(r1);

    run_func(2);
    REQUIRE(r2);

    run_func(j);
    REQUIRE(r3);

    run_func(ctd::move(j));
    REQUIRE(r4);
}
