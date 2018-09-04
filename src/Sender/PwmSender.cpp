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

void PwmSender::setPulseWidth(Php::Parameters &params)
{
    int _gpioPin = params[0];
    int _pulseWidth = params[1];

    if (_gpioPin < 0) {
        Exceptions::InvalidArgumentException("No negative values allowed for <gpioPin> parameter"); return;
    }
    if (_pulseWidth < 0) {
        Exceptions::InvalidArgumentException("No negative values allowed for <pulseWidth> parameter"); return;
    }

    unsigned gpioPin = _gpioPin;
    unsigned pulseWidth = _pulseWidth;

    int rc = gpioServo(gpioPin, pulseWidth);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioServo call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        case PI_BAD_PULSEWIDTH:
            Exceptions::InvalidArgumentException("gpioServo call failed => bad pulse width given (PI_BAD_PULSEWIDTH)"); return;
        default:
            throw new CommandFailedException('gpioServo call failed => unknown error with negative RC');
    }
}

void PwmSender::setDutyCycle(Php::Parameters &params)
{
    int _gpioPin = params[0];
    int _dutyCacle = params[1];

    if (_gpioPin < 0) {
        Exceptions::InvalidArgumentException("No negative values allowed for <gpioPin> parameter"); return;
    }
    if (_dutyCacle < 0) {
        Exceptions::InvalidArgumentException("No negative values allowed for <dutyCacle> parameter"); return;
    }

    unsigned gpioPin = _gpioPin;
    unsigned dutyCacle = _dutyCacle;

    int rc = gpioServo(gpioPin, pulseWidth);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioPWM call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        case PI_BAD_DUTYCYCLE:
            Exceptions::InvalidArgumentException("gpioPWM call failed => bad duty cycle given (PI_BAD_DUTYCYCLE)"); return;
        default:
            throw new CommandFailedException('gpioPWM call failed => unknown error with negative RC');
    }
}