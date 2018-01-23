#ifndef _CTD_TYPE_TRAITS_REMOVE_REFERENCE_HPP
#define _CTD_TYPE_TRAITS_REMOVE_REFERENCE_HPP

namespace ctd {

template<typename T> struct remove_reference      { typedef T type; };
template<typename T> struct remove_reference<T&>  { typedef T type; };
template<typename T> struct remove_reference<T&&> { typedef T type; };

}

#endif
