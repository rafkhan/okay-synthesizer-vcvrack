#pragma once

#include <rack.hpp>

struct ParamRef {
    rack::engine::Param* param;

    ParamRef() : param(nullptr) {}
    float getValue();
    void setValue(float value);
};

struct InputRef {
    rack::engine::Input* input;

    InputRef() : input(nullptr) {}
    bool isConnected();
    float getVoltage();
    void setVolage(float voltage);

};

struct OutputRef {
    rack::engine::Output* output;

    OutputRef() : output(nullptr) {}
    bool isConnected();
    float getVoltage();
    void setVolage(float voltage);
};

struct GreenRedLightRef {
    rack::engine::Light* redLight;
    rack::engine::Light* greenLight;

    GreenRedLightRef() : redLight(nullptr), greenLight(nullptr) {}
    void setRedBrightness(float brightness);
    void setGreenBrightness(float brightness);
};

struct InputTrigger {
    bool isGateHigh;
    bool isTriggered;

    InputTrigger() : isGateHigh(false), isTriggered(false) {}
    void update(float voltage);
    bool triggerCheck();
};