/*
  ==============================================================================

    SynthVoice.h
    Created: 15 Dec 2020 10:56:45pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "WaveForm.h"
#include "WaveType.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:

    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int numOutputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    WaveForm waveForm;
    
    juce::ADSR adsr1;
    juce::ADSR adsr2;
    juce::ADSR adsr3;
    juce::ADSR::Parameters adsr1_Parameters;
    juce::ADSR::Parameters adsr2_Parameters;
    juce::ADSR::Parameters adsr3_Parameters;

    juce::dsp::Oscillator<float> osc1
    {
        [](float x)
        {
            return std::sin(x);
        }
    };

    juce::dsp::Oscillator<float> osc2
    {
        [](float x)
        {
            return std::sin(x);
        }
    };

    juce::dsp::Oscillator<float> osc3
    {
        [](float x)
        {
            return std::sin(x);
        }
    };

    juce::dsp::Gain<float> masterGain;

    bool isPrepared { false };
};