#include <pigpio.h>
#include <stdint.h>
#include <stdio.h>
#include "State.hpp"

using namespace BerryPwm::Core;

int State::pigpioInitRc;
bool State::initialized;

void State::startup()
{
    initialized = false;
}

void State::initDependencies()
{
    pigpioInitRc = gpioInitialise();
    initialized = true;
}

void State::cleanDependencies()
{
    gpioTerminate();
    initialized = false;
}

int State::getPigpioInitRc()
{
    return pigpioInitRc;
}

bool State::isInitialized()
{
    return initialized;
}