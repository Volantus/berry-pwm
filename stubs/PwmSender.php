<?php
namespace Volantus\BerryPwm;

/**
 * Class PwmSender
 *
 * @package Volantus\BerryPwm
 */
class PwmSender
{
    /**
     * Sets the pulse width of the PWM signal
     *
     * @param int $gpioPin    GPIO pin (0-31)
     * @param int $pulseWidth Pulse with in microseconds (usually between 1000 and 2000)
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function setPulseWidth(int $gpioPin, int $pulseWidth)
    {
    }

    /**
     * Sets the duty cycle of the PWM signal
     *
     * @param int $gpioPin    GPIO pin (0-31)
     * @param int $dutyCycle  0 - range (default 255), while 0 is stopping the PWM signal
     *                        s. getRange() and setRange() methods
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function setDutyCycle(int $gpioPin, int $dutyCycle)
    {
    }

    /**
     * Sets the "sampling" range
     * The real range internally used depends on the frequency
     *
     * @param int $gpioPin GPIO pin (0-31)
     * @param int $range   25-40000
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function setRange(int $gpioPin, int $range)
    {
    }

    /**
     * Set the frequency (in Hz) of the PWM to be used on the GPIO.
     *
     * @param int $gpioPin    GPIO pin (0-31)
     * @param int $frequency  >=0 Hz
     *                        The selectable frequencies depend upon the sample rate (follow link for details)
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     *
     * @see http://abyz.me.uk/rpi/pigpio/pdif2.html#set_PWM_frequency
     */
    public function setFrequency(int $gpioPin, int $frequency)
    {
    }

    /**
     * Return the servo pulsewidth in use on a GPIO.
     *
     * @param int $gpioPin GPIO pin (0-31)
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function getPulseWidth(int $gpioPin): int
    {
    }

    /**
     * Returns the dutycycle range used for the GPIO
     *
     * @param int $gpioPin GPIO pin (0-31)
     *
     * @return int
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function getRange(int $gpioPin): int
    {
    }

    /**
     * Return the PWM dutycycle in use on a GPIO.
     *
     * @param int $gpioPin GPIO pin (0-31)
     *
     * @return int
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function getDutyCycle(int $gpioPin): int
    {
    }

    /**
     * Get the frequency of PWM being used on the GPIO.
     *
     * @param int $gpioPin GPIO pin (0-31)
     *
     * @return int Frequency in hertz
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    public function getFrequency(int $gpioPin): int
    {
    }
}