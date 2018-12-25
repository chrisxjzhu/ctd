#ifndef _CTD_TYPE_TRAITS_ENABLE_IF_HPP
#define _CTD_TYPE_TRAITS_ENABLE_IF_HPP

namespace ctd {

template<bool, typename T = void>
struct enable_if { };

template<typename T>
struct enable_if<true, T> { typedef T type; };

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

}

#endif
