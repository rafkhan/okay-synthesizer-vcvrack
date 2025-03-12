#ifndef DISCOMFORT_INPUT_H
#define DISCOMFORT_INPUT_H

#include "Follower.h"
#include "Folder.h"
#include "Clipper.h"
#include "FilterBank.h"
#include "util.h"

class DiscomfortInput
{
public:
  float input;
  float inputGain;
  float outputGain;

  // wavefolder
  float foldGain;     // 0 ... N
  float foldOffset;   // -1 ... +1
  float foldSymmetry; // -1 ... +1

  // Clipper
  float clipperGain;
  float clipperBend;
  ClipperType clipperType;

  // Crush
  float crushValue;

  // Follower
  float attack;
  float decay;
  float envGain;

  float foldDryWet;
  float clipperDryWet;

  void setFolderValues(float gain, float offset, float symmetry, float dryWet)
  {
    this->foldGain = map(gain, 0, 1, FOLDER_MIN_GAIN, FOLDER_MAX_GAIN);
    // this->foldOffset = map(offset, -1, 1, FOLDER_MIN_OFFSET, FOLDER_MAX_OFFSET);
    // this->foldSymmetry = map(symmetry, -1, 1, FOLDER_MIN_SYMMETRY, FOLDER_MAX_SYMMETRY);
    this->foldDryWet = dryWet;
  }

  void setClipperValues(float gain, float bend, float dryWet)
  {
    this->clipperGain = map(gain, 0, 1, CLIPPER_MIN_GAIN, CLIPPER_MAX_GAIN);
    this->clipperBend = map(bend, 0, 1, CLIPPER_MIN_BEND, CLIPPER_MAX_BEND);
    this->clipperDryWet = dryWet;
  }

  // void setEnvelopeValues(float gain, float attack, float decay) {
  //   this->envGain = 1;
  //   this->attack = 1;
  //   this->decay = 1;
  // }

  // empty values for development
  static DiscomfortInput create()
  {
    DiscomfortInput dcInput;
    dcInput.inputGain = 1;
    dcInput.outputGain = 1;
    dcInput.foldGain = FOLDER_MIN_GAIN;
    dcInput.foldOffset = 0;
    dcInput.foldSymmetry = 0;
    dcInput.clipperGain = CLIPPER_MIN_GAIN;
    dcInput.clipperBend = 0;
    dcInput.clipperType = CLIPPER_SOFT;
    dcInput.crushValue = 0;
    dcInput.attack = 1;
    dcInput.decay = 50;
    dcInput.envGain = 1;
    dcInput.foldDryWet = 0;
    dcInput.clipperDryWet = 0;

    return dcInput;
  }

  static DiscomfortInput create(float audioIn)
  {
    DiscomfortInput dcInput = DiscomfortInput::create();
    dcInput.input = audioIn;
    return dcInput;
  }
};

#endif