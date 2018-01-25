#ifndef _CTD_FUNCTIONAL_REFERENCE_WRAPPER_HPP
#define _CTD_FUNCTIONAL_REFERENCE_WRAPPER_HPP

#include <ctd/memory/addressof.hpp>

namespace ctd {

template<typename T>
class reference_wrapper {
public:
    typedef T type;

    reference_wrapper(T& ref) noexcept
        : ptr_(addressof(ref))
    { }

    reference_wrapper(T&&) = delete;

    reference_wrapper(const reference_wrapper&) = default;

    reference_wrapper& operator=(const reference_wrapper&) = default;

    operator T&() const noexcept
    { return get(); }

    T& get() const noexcept
    { return *ptr_; }

private:
    T* ptr_;
};

template<typename T>
inline reference_wrapper<T> ref(T& t) noexcept
{ return reference_wrapper<T>(t); }

/* ref overload to prevent wrapping a reference_wrapper */
template<typename T>
inline reference_wrapper<T> ref(reference_wrapper<T> t) noexcept
{ return ref(t.get()); }

template<typename T>
void ref(const T&&) = delete;


template<typename T>
inline reference_wrapper<const T> cref(const T& t) noexcept
{ return reference_wrapper<const T>(t); }

/* cref overload to prevent wrapping a reference_wrapper */
template<typename T>
inline reference_wrapper<const T> cref(reference_wrapper<T> t) noexcept
{ return cref(t.get()); }

template<typename T>
void cref(const T&&) = delete;

}

#endif
