#ifndef _CTD_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP
#define _CTD_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP

namespace ctd {

template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;

    typedef T value_type;
    typedef integral_constant<T, v> type;

    constexpr operator value_type()   const { return value; }
    constexpr value_type operator()() const { return value; }
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template<bool v>
using bool_constant = integral_constant<bool, v>;

}

#endif
