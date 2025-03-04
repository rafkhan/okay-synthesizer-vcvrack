#ifndef DISCOMFORT_H
#define DISCOMFORT_H

// #include "daisysp.h"
#include "Follower.h"
#include "Clipper.h"
// #include "FilterBank.h"
#include "DiscomfortInput.h"


struct DiscomfortOutput {
  float audioOutput;
  float followerOutput;
};

class Discomfort {
  public:
    Discomfort();
    void init(float sampleRate);
    DiscomfortOutput process(DiscomfortInput input);
    static DiscomfortOutput createOutput(float audio, float follower);
  private:
    Follower *follower;
    // WhiteNoise noise;
};

#endif