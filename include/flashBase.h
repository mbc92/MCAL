#pragma once

#include "esp_err.h"
#include <cstdint>

template <typename Derived>
class FlashBase 
{

public:
    esp_err_t Init() {
        return static_cast<Derived*>(this)->Init();
    }
};