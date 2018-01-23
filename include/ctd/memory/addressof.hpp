#ifndef _CTD_MEMORY_ADDRESSOF_HPP
#define _CTD_MEMORY_ADDRESSOF_HPP

namespace ctd {

template<typename T>
constexpr T* addressof(T& arg)
{
    return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(arg)));
}

template<typename T>
const T* addressof(const T&&) = delete;

}

#endif
