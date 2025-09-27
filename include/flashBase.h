#pragma once

#include "esp_err.h"
#include <cstdint>

template <typename Derived>
class FlashBase 
{

public:
    esp_err_t init() {
        return static_cast<Derived*>(this)->init();
    }
};