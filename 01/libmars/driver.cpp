#include "driver.h"
#include <iostream>

namespace mars {
class IDriver::Driver
{
public:
    void Hello();
};

void IDriver::Driver::Hello()
{
    std::cout << "Hello, Driver!" << std::endl;
}

IDriver::IDriver()
: _impl(std::make_unique<Driver>())
{
}

IDriver::~IDriver() = default;

void IDriver::Hello()
{
    _impl->Hello();
}
}