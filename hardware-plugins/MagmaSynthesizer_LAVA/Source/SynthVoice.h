/*
  ==============================================================================

    SynthVoice.h
    Created: 21 Nov 2020 11:37:07pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include <src\maximilian.h>

class SynthVoice : public juce::SynthesiserVoice
{
public:

    bool canPlaySound (juce::SynthesiserSound* synthesiserSound)
    {
        return dynamic_cast<SynthSound*>(synthesiserSound) != nullptr;
    }

    void startNote (int midiNoteNumber, float velocity, 
        juce::SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env_osc1.trigger = 1;
        velocityLevel = velocity;
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    void stopNote (float velocity, bool allowTailOff)
    {
        env_osc1.trigger = 0;
        allowTailOff = true;

        if (velocity == 0)
        {
            clearCurrentNote();
        }
    }

    void renderNextBlock (juce::AudioBuffer< float >& outputBuffer, 
        int startSample, int numSamples)
    {
        env_osc1.setAttack(2000);
        env_osc1.setDecay(500);
        env_osc1.setSustain(0.8);
        env_osc1.setRelease(2000);

        for (int sample = 0; sample < numSamples; ++sample)
        {
            double osc1_wave = osc1.sinewave(frequency);
            double osc1_env1_sound = env_osc1.adsr(osc1_wave, env_osc1.trigger) * velocityLevel;
            double osc1_env1_filter1_sound = filter_osc1.lores(osc1_env1_sound, 200, 0.1);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, osc1_env1_filter1_sound);
            }

            ++startSample;
        }
    }

    void pitchWheelMoved (int newPitchWheelValue)
    {

    }

    void controllerMoved (int controllerNumber, int newControllerValue)
    {

    }

private:
    double velocityLevel;
    double frequency;

    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;

    maxiEnv env_osc1;
    maxiEnv env_osc2;
    maxiEnv env_osc3;

    maxiFilter filter_osc1;
    maxiFilter filter_osc2;
    maxiFilter filter_osc3;
    maxiFilter filter_master;
};