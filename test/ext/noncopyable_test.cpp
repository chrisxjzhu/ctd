#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ctd/ext/noncopyable.hpp>
#include <type_traits>

class CopyableSocket : private ctd::noncopyable {
public:
    CopyableSocket() = default;
    CopyableSocket(const CopyableSocket&)
        : ctd::noncopyable()  /* add this line to avoid an extra warning */
    { }
    CopyableSocket& operator=(const CopyableSocket&) { return *this; }
};

class NonCopyableSocket : private ctd::noncopyable {
public:
    NonCopyableSocket() = default;
    NonCopyableSocket(const NonCopyableSocket&) = default;
    NonCopyableSocket& operator=(const NonCopyableSocket&) = default;
};

TEST_CASE("noncopyable", "[noncopyable]")
{
    REQUIRE(!std::is_constructible<ctd::noncopyable>::value );
    REQUIRE(!std::is_copy_constructible<ctd::noncopyable>::value );
    REQUIRE(!std::is_move_constructible<ctd::noncopyable>::value );
    REQUIRE(!std::is_copy_assignable<ctd::noncopyable>::value );
    REQUIRE(!std::is_move_assignable<ctd::noncopyable>::value );
}

TEST_CASE("copyable derived", "[copyable derived]")
{
    REQUIRE( std::is_constructible<CopyableSocket>::value );
    REQUIRE( std::is_copy_constructible<CopyableSocket>::value );
    REQUIRE( std::is_move_constructible<CopyableSocket>::value );
    REQUIRE( std::is_copy_assignable<CopyableSocket>::value );
    REQUIRE( std::is_move_assignable<CopyableSocket>::value );
}

TEST_CASE("noncopyable derived", "[noncopyable derived]")
{
    REQUIRE( std::is_constructible<NonCopyableSocket>::value );
    REQUIRE(!std::is_copy_constructible<NonCopyableSocket>::value );
    REQUIRE(!std::is_move_constructible<NonCopyableSocket>::value );
    REQUIRE(!std::is_copy_assignable<NonCopyableSocket>::value );
    REQUIRE(!std::is_move_assignable<NonCopyableSocket>::value );
}
