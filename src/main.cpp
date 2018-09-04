#include <phpcpp.h>
#include <pigpio.h>
#include "BerrySpiState.hpp"
#include "BerrySpiExceptions.hpp"
#include "AbstractSpiInterface.hpp"
#include "SpiRegularInterface.hpp"
#include "SpiBitBangingInterface.hpp"

using namespace BerryPwm::Sender;
using namespace BerryPwm::Core;

extern "C" {
    /**
     *  @return void*   a pointer to an address that is understood by PHP
     */
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
            State::prepare();
        });

        extension.onShutdown([]() {
            State::cleanDependencies();
        });

        return extension;
    }
}
