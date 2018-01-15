#ifndef _CTD_EXT_NONCOPYABLE_HPP
#define _CTD_EXT_NONCOPYABLE_HPP

namespace ctd {

class noncopyable {
protected:
    noncopyable() = default;
    ~noncopyable() = default;

    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

}

#endif
