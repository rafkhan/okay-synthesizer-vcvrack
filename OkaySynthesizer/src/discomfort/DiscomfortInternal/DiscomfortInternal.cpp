#include <cmath>

#include "DiscomfortInternal.h"
#include "Folder.h"
#include "Clipper.h"
#include "DryWet.h"
#include "DiscomfortInput.h"

DiscomfortInternal::DiscomfortInternal() {}

void DiscomfortInternal::init(float sampleRate)
{
  this->follower = new Follower(sampleRate, 1.0f, 1.0f);
  this->filterBank = new FilterBank(sampleRate);
  noise.Init();
}

DiscomfortOutput DiscomfortInternal::process(DiscomfortInput input)
{
  // Add envelope gain!!!
  float followerAmplitude = this->follower->process(input.input * input.envGain, input.attack, input.decay);

  float gainStagedInput = input.input * input.inputGain;
  float foldOut = Folder::fold(gainStagedInput, input.foldGain, input.foldOffset, input.foldSymmetry);
  float foldBlend = DryWet::blend(gainStagedInput, foldOut, pow(input.foldDryWet, 2));
  float clippedOut = Clipper::clip(foldBlend, input.clipperGain, input.clipperBend);
  float clippedBlend = DryWet::blend(foldBlend, clippedOut, pow(input.clipperDryWet, 2));
  float output = clippedBlend * input.outputGain;

  return this->createOutput(output * 0.7, followerAmplitude);
}

DiscomfortOutput DiscomfortInternal::createOutput(float audio, float follower)
{
  DiscomfortOutput dcOutput;
  dcOutput.audioOutput = audio;
  dcOutput.followerOutput = follower;
  return dcOutput;
}
