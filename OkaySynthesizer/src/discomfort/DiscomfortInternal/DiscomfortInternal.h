#ifndef DISCOMFORT_H
#define DISCOMFORT_H

#include "daisysp.h"
#include "Follower.h"
#include "Clipper.h"
#include "FilterBank.h"
#include "DiscomfortInput.h"

#define FOLD_MODE_1 1
#define DIST_MODE_NOISE_PARTICLE 1

using namespace daisysp;

struct DiscomfortOutput {
  float audioOutput;
  float followerOutput;
};

class DiscomfortInternal {
  public:
    DiscomfortInternal();
    void init(float sampleRate);
    DiscomfortOutput process(DiscomfortInput input);
    static DiscomfortOutput createOutput(float audio, float follower);
  private:
    Follower *follower;
    FilterBank *filterBank;
    WhiteNoise noise;
    Particle noiseParticle;

    float getFold(float audioIn, DiscomfortInput input);
    float getDist(float audioIn, DiscomfortInput input);
};

#endif