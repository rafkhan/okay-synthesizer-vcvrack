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

struct LightRef {
    rack::engine::Light* light;

    LightRef() : light(nullptr) {}
    float getBrightness();
    void setBrightness(float brightness);
};

struct InputTrigger {
    bool isTriggered;

    InputTrigger() : isTriggered(false) {}
    void update(float voltage);
};