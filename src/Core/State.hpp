#ifndef BERRY_SPI_STAGE_H
#define BERRY_SPI_STAGE_H

namespace BerryPwm {
namespace Core {

    class State
    {
    private:
        static int pigpioInitRc;
        static bool initialized;

    public:
        static void startup();
        static void initDependencies();
        static void cleanDependencies();
        static int getPigpioInitRc();
        static bool isInitialized();
    };

}
}

#endif