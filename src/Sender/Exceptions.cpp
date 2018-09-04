#include <stdexcept>
#include <phpcpp.h>
#include "Exceptions.hpp"

using namespace BerryPwm::Sender;

zend_class_entry* Exceptions::_gioInitFailureException;
zend_class_entry* Exceptions::_invalidArgumentException;

void Exceptions::prepare()
{
    zend_class_entry classEntry;

    INIT_CLASS_ENTRY(classEntry, "Volantus\\BerryPwm\\BerryPwm\\InvalidArgumentException", NULL);
    _invalidArgumentException = zend_register_internal_class_ex(&classEntry, zend_exception_get_default());

    INIT_CLASS_ENTRY(classEntry, "Volantus\\BerryPwm\\BerryPwm\\GpioInitFailureException", NULL);
    _gioInitFailureException = zend_register_internal_class_ex(&classEntry, zend_exception_get_default());
}

void Exceptions::registerException(const char* name, zend_class_entry **memberClassEntry)
{
    zend_class_entry classEntry;
    INIT_CLASS_ENTRY(classEntry, name, NULL);
    *memberClassEntry = zend_register_internal_class_ex(&classEntry, zend_exception_get_default());
}

void Exceptions::InvalidArgumentException(const char* message)
{
    zend_throw_exception_ex(_invalidArgumentException, 0, message, __FILE__, __LINE__);
}

void Exceptions::GpioInitFailureException(const char* message)
{
    zend_throw_exception_ex(_gioInitFailureException, 0, message, __FILE__, __LINE__);
}