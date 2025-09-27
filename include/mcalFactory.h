#pragma once

// Expandable board-specific selection
#if defined(BOARD_ESP32)
    #include "ESP32/dio.h"
    #include "ESP32/flash.h"
    namespace MCAL {
        using Dio = DioESP32;
        using Flash = FlashESP32;
    }

#elif defined(BOARD_STM32)
    #include "stm32/dio_stm32.hpp"
    namespace MCAL {
        using Dio = DioStm32;
    }

#else
    #error "Unsupported BOARD. Please define -DBOARD=ESP32 or -DBOARD=STM32."
#endif