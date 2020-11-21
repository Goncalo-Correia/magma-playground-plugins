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
        midiNoteFrequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    void stopNote(float velocity, bool allowTailOff)
    {

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

    }

private:
    double velocityLevel;
    double midiNoteFrequency;

};