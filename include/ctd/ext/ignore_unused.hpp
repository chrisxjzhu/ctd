#ifndef _CTD_EXT_IGNORE_UNUSED_HPP
#define _CTD_EXT_IGNORE_UNUSED_HPP

namespace ctd {

template <typename... Ts>
inline constexpr void ignore_unused(Ts const& ...) { }

template <typename... Ts>
inline constexpr void ignore_unused() { }

}

#endif
