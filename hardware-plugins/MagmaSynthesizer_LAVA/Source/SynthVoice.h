/*
  ==============================================================================

    SynthVoice.h
    Created: 21 Nov 2020 6:22:25pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "../../../external-libraries/Maximilian/src/maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:

    bool canPlaySound(juce::SynthesiserSound* synthesizerSound)
    {
        /*Description - Gonçalo Correia - 11/21/2020
        Will try to cast the sound as class SynthSound,
        if that cast is succesfull will return true, else false*/
        return dynamic_cast<SynthSound*>(synthesizerSound) != nullptr;
    }

    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, 
        int currentPitchWheelPosition)
    {
        env_osc1.trigger = 1;
        env_osc2.trigger = 1;
        env_osc3.trigger = 1;
        env_filter.trigger = 1;

        velocityLevel = velocity;
        midiNoteFrequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    void stopNote(float velocity, bool allowTailOff)
    {
        env_osc1.trigger = 0;
        env_osc2.trigger = 0;
        env_osc3.trigger = 0;
        env_filter.trigger = 0;

        allowTailOff = true;

        if (velocity == 0)
        {
            clearCurrentNote();
        }
    }

    void pitchWheelMoved(int newPitchWheelValue)
    {

    }

    void controllerMoved(int controllerNumber, int newControllerValue)
    {

    }

    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, 
        int numSamples)
    {
        env_osc1.setAttack(2000);
        env_osc1.setDecay(500);
        env_osc1.setSustain(0.8);
        env_osc1.setRelease(2000);

        env_osc2.setAttack(2000);
        env_osc2.setDecay(500);
        env_osc2.setSustain(0.8);
        env_osc2.setRelease(2000);

        env_osc3.setAttack(2000);
        env_osc3.setDecay(500);
        env_osc3.setSustain(0.8);
        env_osc3.setRelease(2000);

        for (int sample = 0; sample < numSamples; ++sample)
        {
            double osc1_wave = osc1.sinewave(midiNoteFrequency);
            double osc1_sound = env_osc1.adsr(osc1_wave, env_osc1.trigger) * velocityLevel;
            double osc1_filter1_sound = filter_osc1.lores(osc1_sound, filter_osc1_cutoffFrequency, filter_osc1_resonance);

            double osc2_wave = osc2.sinewave(midiNoteFrequency);
            double osc2_sound = env_osc2.adsr(osc2_wave, env_osc2.trigger) * velocityLevel;
            double osc2_filter2_sound = filter_osc2.lores(osc2_sound, filter_osc2_cutoffFrequency, filter_osc2_resonance);

            double osc3_wave = osc3.sinewave(midiNoteFrequency);
            double osc3_sound = env_osc3.adsr(osc3_wave, env_osc3.trigger) * velocityLevel;
            double osc3_filter3_sound = filter_osc3.lores(osc3_sound, filter_osc3_cutoffFrequency, filter_osc3_resonance);

            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, osc1_sound);
            }

            ++startSample;
        }
    }

private:
    double velocityLevel;
    double midiNoteFrequency;

    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;

    maxiEnv env_osc1;
    maxiEnv env_osc2;
    maxiEnv env_osc3;
    maxiEnv env_filter;

    maxiFilter filter_osc1;
    maxiFilter filter_osc2;
    maxiFilter filter_osc3;
    maxiFilter filter_master;

    double filter_osc1_cutoffFrequency;
    double filter_osc2_cutoffFrequency;
    double filter_osc3_cutoffFrequency;
    double filter_master_cutoffFrequency;

    double filter_osc1_resonance;
    double filter_osc2_resonance;
    double filter_osc3_resonance;
    double filter_master_resonance;

};