#ifndef _CTD_TYPE_TRAITS_IS_SAME_HPP
#define _CTD_TYPE_TRAITS_IS_SAME_HPP

#include <ctd/type_traits/integral_constant.hpp>

namespace ctd {

template<typename, typename> struct is_same       : false_type { };
template<typename T>         struct is_same<T, T> : true_type  { };

}

#endif
