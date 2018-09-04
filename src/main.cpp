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
