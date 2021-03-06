#include <phpcpp.h>
#include <pigpio.h>
#include "Core/State.hpp"
#include "Sender/Exceptions.hpp"
#include "Sender/PwmSender.hpp"

using namespace BerryPwm::Sender;
using namespace BerryPwm::Core;

extern "C" {

    PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension extension("berry-pwm", "0.1.0");

        Php::Interface senderInterface("Volantus\\BerryPwm\\SenderInterface");
        extension.add(senderInterface);

        Php::Class<PwmSender> pwmSender("Volantus\\BerryPwm\\PwmSender");
        pwmSender.implements(senderInterface);

        pwmSender.method<&PwmSender::isInitialized> ("isInitialized");
        pwmSender.method<&PwmSender::initialize> ("initialize");
        pwmSender.method<&PwmSender::setPulseWidth> ("setPulseWidth", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
            Php::ByVal("pulseWidth", Php::Type::Numeric, true)
        });
        pwmSender.method<&PwmSender::setDutyCycle> ("setDutyCycle", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
            Php::ByVal("dutyCycle", Php::Type::Numeric, true)
        });
        pwmSender.method<&PwmSender::setRange> ("setRange", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
            Php::ByVal("range", Php::Type::Numeric, true)
        });
        pwmSender.method<&PwmSender::setFrequency> ("setFrequency", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
            Php::ByVal("frequency", Php::Type::Numeric, true)
        });
        pwmSender.method<&PwmSender::getPulseWidth> ("getPulseWidth", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
        });
        pwmSender.method<&PwmSender::getRange> ("getRange", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
        });
        pwmSender.method<&PwmSender::getDutyCycle> ("getDutyCycle", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
        });
        pwmSender.method<&PwmSender::getFrequency> ("getFrequency", {
            Php::ByVal("gpioPin", Php::Type::Numeric, true),
        });
        
        extension.add(std::move(pwmSender));

        extension.onStartup([]() {
            State::startup();
            Exceptions::prepare();
        });

        extension.onShutdown([]() {
            State::cleanDependencies();
        });

        return extension;
    }
}
