#include "VoleDriver.h"

using namespace Vole;

int __cdecl main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    IDriver Driver;
    Driver.Hello();
    return 0;
}