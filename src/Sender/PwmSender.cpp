#include <phpcpp.h>
#include <stdint.h>
#include <pigpio.h>
#include "../Core/State.hpp"

using namespace BerryPwm::Sender;
using namespace BerryPwm::Core;

Php::Value PwmSender::initialize()
{
    State::initDependencies();
    return State::getPigpioInitRc() >= 0;
}

Php::Value PwmSender::isInitialized()
{
    return State::isInitialized();
}
