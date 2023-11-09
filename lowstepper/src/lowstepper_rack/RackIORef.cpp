#include "RackIORef.h"

float ParamRef::getValue()
{
    return param->getValue();
}

void ParamRef::setValue(float value)
{
    param->setValue(value);
}

bool InputRef::isConnected()
{
    return input->isConnected();
}

float InputRef::getVoltage()
{
    return input->getVoltage();
}

void InputRef::setVolage(float voltage)
{
    input->setVoltage(voltage);
}

bool OutputRef::isConnected()
{
    return output->isConnected();
}

float OutputRef::getVoltage()
{
    return output->getVoltage();
}

void OutputRef::setVolage(float voltage)
{
    output->setVoltage(voltage);
}

float LightRef::getBrightness()
{
    return light->getBrightness();
}

void LightRef::setBrightness(float brightness)
{
    light->setBrightness(brightness);
}


void InputTrigger::update(float voltage)
{
    const float HIGH = 2.f;
    const float CUTOFF = 0.1f;

    if(isTriggered) {
        if(voltage <= CUTOFF) {
            isTriggered = false;
        }
    }
    else {
        if(voltage >= HIGH) {
            isTriggered = true;
        }
    }
}