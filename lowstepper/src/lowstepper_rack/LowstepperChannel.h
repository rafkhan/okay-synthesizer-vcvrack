#pragma once

#include "RackIORef.h"
#include "../lowstepper/LowStepperLfo.h"
#include "../lowstepper/SyncManager.h"

enum class ChannelId {
    A,
    B
};

struct Channel {
    LowStepperLfo lfo;  
    SyncManager syncManager;
    LowStepperOutput lastOutput;
    ParamRef rateKnob;
    ParamRef morphKnob;
    ParamRef startKnob;
    ParamRef endKnob;
    ParamRef speedToggle;
    LightRef led;
    InputRef rateCv;
    InputRef morphCv;
    InputRef startCv;
    InputRef endCv;
    InputRef syncIn;
    InputRef resetIn;
    OutputRef cvOut;
    OutputRef eocOut;
    InputTrigger syncTrigger;
    InputTrigger resetTrigger;

    Channel(float sampleRate);
    bool eocHigh = false;
    int eocSampleTime = 0;
};