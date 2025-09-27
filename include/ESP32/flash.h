#pragma once

#include "flashBase.h"

class FlashESP32 : public FlashBase<FlashESP32>
{

public:
    esp_err_t Init();

};