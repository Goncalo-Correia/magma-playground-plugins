/*
  ==============================================================================

    SynthSound.h
    Created: 21 Nov 2020 11:37:16pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote (int midiNoteNumber)
    {
        return true;
    }

    bool appliesToChannel (int midiChannel)
    {
        return true;
    }
};