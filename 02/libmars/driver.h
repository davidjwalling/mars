#pragma once
#include "api.h"
#include <memory>

namespace mars {
class IDriver
{
    class Driver;
    std::unique_ptr<Driver> _impl;
public:
    EXPORT IDriver();
    EXPORT ~IDriver();
    EXPORT void Hello();
};
}