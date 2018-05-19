#ifndef __SoundTouchPatch_hpp__
#define __SoundTouchPatch_hpp__

#include "Patch.h"
#include "SoundTouch.h"

class SoundTouchPatch : public Patch {
private:
  soundtouch::SoundTouch st;
public:
  SoundTouchPatch() {
  }
  void processAudio(AudioBuffer &buffer) {
    float frequency = getParameterValue(PARAMETER_A) * 10000;
    float amplitude = getParameterValue(PARAMETER_B);
    FloatArray left = buffer.getSamples(LEFT_CHANNEL);
    FloatArray right = buffer.getSamples(RIGHT_CHANNEL);
  }
};

#endif   // __SoundTouchPatch_hpp__
