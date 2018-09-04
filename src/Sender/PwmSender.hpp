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

            void setPulseWidth(Php::Parameters &params);
            void setDutyCycle(Php::Parameters &params);
    };

}
}

#endif