#ifndef _CTD_TYPE_TRAITS_IS_REFERENCE_HPP
#define _CTD_TYPE_TRAITS_IS_REFERENCE_HPP

#include <ctd/type_traits/integral_constant.hpp>

namespace ctd {

template<typename>   struct is_lvalue_reference      : false_type { };
template<typename T> struct is_lvalue_reference<T&>  : true_type  { };

template<typename>   struct is_rvalue_reference      : false_type { };
template<typename T> struct is_rvalue_reference<T&&> : true_type  { };

}

#endif
