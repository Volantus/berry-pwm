# berry-pwm
Native PHP extension for sending PWM signals based on [PHP-CPP](http://www.php-cpp.com) and the great [Pigpiod library](http://abyz.me.uk/rpi/pigpio) on RaspberryPi.

# Installation
## Compile from source
Please make sure you installed the PHP-CPP library ([guide](http://www.php-cpp.com/documentation/install)) + pigpio ([Guide](http://abyz.me.uk/rpi/pigpio/download.html)).
Clone and compile the source code:
```bash
git clone https://github.com/Volantus/berry-spi
cd berry-spi
make
sudo make install
```

# Usage
## Setup
PWM signals are managed by class `PwmSender`.
````php
use Volantus\BerryPwm\PwmSender;

$sender = new PwmSender();
````

### Setting pulse width
Sets the pulse width to 1600 microseconds on GPIO pin 14:
````php
$sender->setPulseWidth(14, 1500);
````

### Setting duty cycle
Duty cycle is controlled by setting a integer value out of a valid range.
Default range: 255

The range may be modified by using  `$sender->setRange()` method.

Example: Setting duty cycle to 150 out of 255 => ~59% on GPIO pin 14:
````php
$sender->setDutyCycle(14, 150);
````

### Setting range
Range of duty cycle may be modified for gaining more precision.
Note: The real range used internally depends on the frequency and sample size, s. official [Pigpiod documentation](http://abyz.me.uk/rpi/pigpio/pdif2.html#set_PWM_range) for more details.

Example: Setting range to 1024 on GPIO pin 14:
````php
$sender->setRange(14, 1024);
````

### Setting frequency
Set the frequency (in Hz) of the PWM to be used on the GPIO.
The selectable frequencies depend upon the sample rate, s. official [Pigpiod documentation](http://abyz.me.uk/rpi/pigpio/pdif2.html#set_PWM_frequency) for more details.

Example: Setting frequency to 250 Hz on GPIO pin 14:
````php
$sender->setFrequency(14, 250);
````

### Getting values
All configurable values may be read as well.

Reading different kind of values of GPIO pin 14:
````php
$sender->getPulseWidth(14);
$sender->getDutyCycle(14);
$sender->getRange(14);
$sender->getFrequency(14);
````