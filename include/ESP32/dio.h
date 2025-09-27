#pragma once

#include "dioBase.h"

class DioESP32 : public DioBase<DioESP32>
{
public:
    void WriteChannel(const uint32_t channel, bool level);
    bool ReadChannel(const uint32_t channel);
};