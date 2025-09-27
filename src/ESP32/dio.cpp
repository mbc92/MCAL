#include "ESP32/dio.h"

#include <cstdint>
#include <driver/gpio.h>

void DioESP32::WriteChannel(const uint32_t channel, bool level)
{
     gpio_set_level((gpio_num_t)channel, level ? 1 : 0);
}

bool DioESP32::ReadChannel(const uint32_t channel) 
{
     return gpio_get_level((gpio_num_t)channel) == 1;
}
