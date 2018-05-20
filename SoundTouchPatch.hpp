#ifndef __SoundTouchPatch_hpp__
#define __SoundTouchPatch_hpp__

#include "Patch.h"
#include "SoundTouch.h"

class SoundTouchPatch : public Patch {
private:
  soundtouch::SoundTouch st;
public:
  SoundTouchPatch() {
    st.setSampleRate(getSampleRate());
    st.setChannels(1);
    // st.setSetting(SETTING_USE_QUICKSEEK, params->quick);
    // st.setSetting(SETTING_USE_AA_FILTER, !(params->noAntiAlias));
    registerParameter(PARAMETER_A, "Pitch");
  }
  void processAudio(AudioBuffer &buffer) {
    float pitch = getParameterValue(PARAMETER_A)*24-12;
    FloatArray left = buffer.getSamples(LEFT_CHANNEL);
    FloatArray right = buffer.getSamples(RIGHT_CHANNEL);
    int size = buffer.getSize();
    st.setPitchSemiTones(pitch);
    // st.setTempoChange(params->tempoDelta);
    // st.setRateChange(params->rateDelta);
    st.putSamples(left, size);
    st.receiveSamples(left, size);
  }
};

#endif   // __SoundTouchPatch_hpp__
