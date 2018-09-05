<?php
namespace Volantus\BerryPWM\Tests;

use PHPUnit\Framework\TestCase;
use Volantus\BerryPwm\PwmSender\PwmSender;

/**
 * Class PwmSenderTest
 *
 * @package Volantus\BerryPWM\Tests
 */
class PwmSenderTest extends TestCase
{
    /**
     * @var PwmSender
     */
    private $sender;

    protected function setUp()
    {
        $this->sender = new PwmSender();
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_setPulseWidth_negativeParameter_gpioPin()
    {
        $this->sender->setPulseWidth(-1, 1500);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <pulseWidth> parameter
     */
    public function test_setPulseWidth_negativeParameter_pulseWidth()
    {
        $this->sender->setPulseWidth(20, -100);
    }

    public function test_setPulseWidth_correct()
    {
        $this->sender->setPulseWidth(20, 1400);
        self::assertEquals(1400, $this->sender->getPulseWidth(20));
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_setDutyCycle_negativeParameter_gpioPin()
    {
        $this->sender->setDutyCycle(-1, 64);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <dutyCycle> parameter
     */
    public function test_setDutyCycle_negativeParameter_dutyCycle()
    {
        $this->sender->setDutyCycle(20, -100);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_setRange_negativeParameter_gpioPin()
    {
        $this->sender->setRange(-1, 1024);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <range> parameter
     */
    public function test_setRange_negativeParameter_range()
    {
        $this->sender->setRange(20, -100);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage gpioSetPWMrange() call failed => bad duty range given (PI_BAD_DUTYRANGE)
     */
    public function test_setRange_badRange()
    {
        $this->sender->setRange(20, 999999999);
    }

    public function test_setRange_correct()
    {
        $this->sender->setRange(20, 1024);
        self::assertEquals(1024, $this->sender->getRange(20));
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_setFrequency_negativeParameter_gpioPin()
    {
        $this->sender->setFrequency(-1, 128000);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <frequency> parameter
     */
    public function test_setFrequency_negativeParameter_frequency()
    {
        $this->sender->setFrequency(20, -100);
    }

    public function test_setFrequency_correct()
    {
        $this->sender->setFrequency(20, 500);
        self::assertEquals(500, $this->sender->getFrequency(20));
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_getPulseWidth_negativeParameter_gpioPin()
    {
        $this->sender->getPulseWidth(-1);
    }
    
    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage gpioPWM call failed => no active PWM signal on given GPIO (PI_NOT_SERVO_GPIO)
     */
    public function test_getPulseWidth_noActivePwmSignal()
    {
        $this->sender->getPulseWidth(10);
    }
    
    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_getRange_negativeParameter_gpioPin()
    {
        $this->sender->getRange(-1);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_getDutyCycle_negativeParameter_gpioPin()
    {
        $this->sender->getDutyCycle(-1);
    }

    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage gpioPWM call failed => no active PWM signal on given GPIO (PI_NOT_PWM_GPIO)
     */
    public function test_getDutyCycle_noActivePwmSignal()
    {
        $this->sender->getDutyCycle(10);
    }
    
    /**
     * @expectedException \Volantus\BerryPwm\PwmSender\InvalidArgumentException
     * @expectedExceptionMessage No negative values allowed for <gpioPin> parameter
     */
    public function test_getFrequency_negativeParameter_gpioPin()
    {
        $this->sender->getFrequency(-1);
    }
    
    protected function tearDown()
    {
        $this->sender->setPulseWidth(20, 0);
    }
}