#include "RackIORef.h"
#include <math.h>

#define M_PI_2 1.57079632679489661923

extern rack::Plugin* pluginInstance;

SlowMedFastSwitch::SlowMedFastSwitch()
    : currentMode(MEDIUM)
{
    // Load shared_ptr svgs from plugin resources
    // https://github.com/VCVRack/Rack/blob/v2/src/app/SvgKnob.cpp

    this->slowSvg = rack::Svg::load(rack::asset::plugin(pluginInstance, "res/3-way-switch-slow.svg"));
    this->mediumSvg = rack::Svg::load(rack::asset::plugin(pluginInstance, "res/3-way-switch-medium.svg"));
    this->fastSvg = rack::Svg::load(rack::asset::plugin(pluginInstance, "res/3-way-switch-fast.svg"));

    this->horizontal = true;
    this->speed = 1.5;
    this->minAngle = -M_PI_2;
    this->maxAngle = M_PI_2;

	setSvg(this->mediumSvg);
}

void SlowMedFastSwitch::onChange(const ChangeEvent &e)
{
    // https://github.com/VCVRack/Rack/blob/8c6f41b778b4bf8860b89b36d5503fd37924077f/src/app/SvgKnob.cpp#L40
    //SvgKnob::onChange(e);

    float angle = 0.f;

	// Calculate angle from value
	rack::engine::ParamQuantity* pq = getParamQuantity();
    if(pq) {
		float value = pq->getValue();
        if(value == 0.f) {
            this->currentMode = MEDIUM;
            setSvg(this->mediumSvg);
        }
        else if(value > 0.f) {
            this->currentMode = FAST;
            setSvg(this->fastSvg);
        }
        else {
            this->currentMode = SLOW;
            setSvg(this->slowSvg);
        }
    }


	// if (pq) {
	// 	float value = pq->getValue();
	// 	if (!pq->isBounded()) {
	// 		// Number of rotations equals value for unbounded range
	// 		angle = value * (2 * M_PI);
	// 	}
	// 	else if (pq->getRange() == 0.f) {
	// 		// Center angle for zero range
	// 		angle = (minAngle + maxAngle) / 2.f;
	// 	}
	// 	else {
	// 		// Proportional angle for finite range
	// 		angle = rack::math::rescale(value, pq->getMinValue(), pq->getMaxValue(), minAngle, maxAngle);
	// 	}
	// 	angle = std::fmod(angle, 2 * M_PI);
	// }

	//tw->identity();
	// Rotate SVG
	//math::Vec center = sw->box.getCenter();
	// tw->translate(center);
	// tw->rotate(angle);
	//tw->translate(center.neg());
	fb->setDirty();

	Knob::onChange(e);

    INFO("on change!");
}

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

void GreenRedLightRef::setRedBrightness(float brightness) 
{
    redLight->setBrightness(brightness);
}

void GreenRedLightRef::setGreenBrightness(float brightness)
{
    greenLight->setBrightness(brightness);
}

void InputTrigger::update(float voltage)
{
    const float HIGH = 2.f;
    const float CUTOFF = 0.1f;

    if(isGateHigh) {
        if(voltage <= CUTOFF) {
            isGateHigh = false;
        }
    }
    else {
        if(voltage >= HIGH && !isGateHigh) {
            isGateHigh = true;
            isTriggered = true;
        }
    }
}

bool InputTrigger::triggerCheck()
{
    if(isTriggered) {
        isTriggered = false;
        return true;
    }
    return false;
}
