
#include <MCAL/include>

class DioEsp32 : public DioBase<DioEsp32>
{
public:
    void WriteChannel(const uint32_t channel, bool level);
    bool ReadChannel(const uint32_t channel);
};