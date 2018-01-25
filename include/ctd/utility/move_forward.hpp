#ifndef _CTD_UTILITY_MOVE_FORWARD_HPP
#define _CTD_UTILITY_MOVE_FORWARD_HPP

#include <ctd/type_traits/is_reference.hpp>
#include <ctd/type_traits/remove_reference.hpp>

namespace ctd {

template<typename T>
constexpr typename remove_reference<T>::type&& move(T&& t) noexcept
{
    return static_cast<typename remove_reference<T>::type&&>(t);
}


template<typename T>
constexpr T&& forward(typename remove_reference<T>::type& t) noexcept
{
    return static_cast<T&&>(t);
}

template<typename T>
constexpr T&& forward(typename remove_reference<T>::type&& t) noexcept
{
    static_assert(!is_lvalue_reference<T>::value);
    return static_cast<T&&>(t);
}

}

#endif
