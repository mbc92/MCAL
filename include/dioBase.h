#pragma once

#include <cstdint>

template <typename Derived>
class DioBase {
public:

    // // Common interface that uses derived implementation
    // void SomeCommonFunction() {
    //     static_cast<Derived*>(this)->WriteChannel(1, true);
    // }

    // Optional: expose a unified interface for other common operations
    void WriteChannel(const uint32_t channel, bool level) {
        static_cast<Derived*>(this)->WriteChannel(channel, level);
    }

    bool ReadChannel(const uint32_t channel) {
        return static_cast<Derived*>(this)->ReadChannel(channel);
    }
};