#pragma once
#include "VoleAPI.h"
#include <memory>

namespace Vole {
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