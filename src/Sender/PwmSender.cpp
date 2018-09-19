#include <phpcpp.h>
#include <stdint.h>
#include <pigpio.h>
#include "../Core/State.hpp"
#include "PwmSender.hpp"
#include "Exceptions.hpp"

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

    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return;}
    if (_pulseWidth < 0) {Exceptions::NoNegativeValues("pulseWidth"); return;}

    unsigned gpioPin = _gpioPin;
    unsigned pulseWidth = _pulseWidth;

    int rc = gpioServo(gpioPin, pulseWidth);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioServo() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        case PI_BAD_PULSEWIDTH:
            Exceptions::InvalidArgumentException("gpioServo() call failed => bad pulse width given (PI_BAD_PULSEWIDTH)"); return;
        default:
            Exceptions::RuntimeException("gpioServo() call failed => unknown error with negative RC");
    }
}

void PwmSender::setDutyCycle(Php::Parameters &params)
{
    int _gpioPin = params[0];
    int _dutyCycle = params[1];

    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return;}
    if (_dutyCycle < 0) {Exceptions::NoNegativeValues("dutyCacle"); return;}

    unsigned gpioPin = _gpioPin;
    unsigned dutyCacle = _dutyCycle;

    int rc = gpioServo(gpioPin, pulseWidth);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioServo() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        case PI_BAD_DUTYCYCLE:
            Exceptions::InvalidArgumentException("gpioServo() call failed => bad duty cycle given (PI_BAD_DUTYCYCLE)"); return;
        default:
            Exceptions::RuntimeException("gpioServo() call failed => unknown error with negative RC");
    }
}

void PwmSender::setRange(Php::Parameters &params)
{
    int _gpioPin = params[0];
    int _range = params[1];

    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return;}
    if (_range < 0) {Exceptions::NoNegativeValues("range"); return;}

    unsigned gpioPin = _gpioPin;
    unsigned range = _range;

    int rc = gpioSetPWMrange(gpioPin, range);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioSetPWMrange() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        case PI_BAD_DUTYRANGE:
            Exceptions::InvalidArgumentException("gpioSetPWMrange() call failed => bad duty range given (PI_BAD_DUTYRANGE)"); return;
        default:
            Exceptions::RuntimeException("gpioSetPWMrange() call failed => unknown error with negative RC");
    }
}

void PwmSender::setFrequency(Php::Parameters &params)
{
    int _gpioPin = params[0];
    int _frequency = params[1];

    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return;}
    if (_frequency < 0) {Exceptions::NoNegativeValues("frequency"); return;}

    unsigned gpioPin = _gpioPin;
    unsigned frequency = _frequency;

    int rc = gpioSetPWMfrequency(gpioPin, frequency);
    if (rc >= 0) {
        return;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioSetPWMfrequency() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return;
        default:
            Exceptions::RuntimeException("gpioSetPWMfrequency() call failed => unknown error with negative RC");
    }
}

Php::Value PwmSender::getPulseWidth(Php::Parameters &params)
{
    int _gpioPin = params[0];
    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return 0;}
    unsigned gpioPin = _gpioPin;

    int rc = gpioGetServoPulsewidth(gpioPin);
    if (rc >= 0) {
        return rc;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioGetServoPulsewidth() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return PI_BAD_USER_GPIO;
        case PI_NOT_SERVO_GPIO:
            Exceptions::RuntimeException("gpioGetServoPulsewidth() call failed => no active PWM signal on given GPIO (PI_NOT_SERVO_GPIO)"); return PI_NOT_SERVO_GPIO;
        default:
            Exceptions::RuntimeException("gpioGetServoPulsewidth() call failed => unknown error with negative RC"); return rc;
    }
}

Php::Value PwmSender::getRange(Php::Parameters &params)
{
    int _gpioPin = params[0];
    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return 0;}
    unsigned gpioPin = _gpioPin;

    int rc = gpioGetPWMrange(gpioPin);
    if (rc < 0) {
        Exceptions::RuntimeException("gpioGetPWMrange() call failed => unknown error with negative RC");
    }

    return rc;
}

Php::Value PwmSender::getDutyCycle(Php::Parameters &params)
{
    int _gpioPin = params[0];
    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return 0;}
    unsigned gpioPin = _gpioPin;

    int rc = gpioGetPWMdutycycle(gpioPin);
    if (rc >= 0) {
        return rc;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioGetPWMdutycycle() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return PI_BAD_USER_GPIO;
        case PI_NOT_PWM_GPIO:
            Exceptions::RuntimeException("gpioGetPWMdutycycle() call failed => no active PWM signal on given GPIO (PI_NOT_PWM_GPIO)"); return PI_NOT_PWM_GPIO;
        default:
            Exceptions::RuntimeException("gpioGetPWMdutycycle() call failed => unknown error with negative RC"); return rc;
    }
}

Php::Value PwmSender::getFrequency(Php::Parameters &params)
{
    int _gpioPin = params[0];
    if (_gpioPin < 0) {Exceptions::NoNegativeValues("gpioPin"); return 0;}
    unsigned gpioPin = _gpioPin;

    int rc = gpioGetPWMfrequency(gpioPin);
    if (rc >= 0) {
        return rc;
    }

    switch (rc) {
        case PI_BAD_USER_GPIO:
            Exceptions::InvalidArgumentException("gpioGetPWMfrequency() call failed => bad GPIO pin given (PI_BAD_USER_GPIO)"); return PI_BAD_USER_GPIO;
        default:
            Exceptions::RuntimeException("gpioGetPWMfrequency() call failed => unknown error with negative RC"); return rc;
    }
}