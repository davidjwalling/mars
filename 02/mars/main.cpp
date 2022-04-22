#include "driver.h"

using namespace mars;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    IDriver Driver;
    Driver.Hello();
    return 0;
}