#ifndef PWM_SENDER_H
#define PWM_SENDER_H

namespace BerryPwm {
namespace Sender {

    class PwmSender: public Php::Base
    {
        public:
            PwmSender() = default;
            virtual ~PwmSender() = default;

            /* Initializes the Pigpio library */
            static Php::Value initialize();

            /* Is the Pigpio library initialized? */
            static Php::Value isInitialized();

            /* Start/stop PWM pulses on a GPIO */
            void setPulseWidth(Php::Parameters &params);
    };

}
}

#endif