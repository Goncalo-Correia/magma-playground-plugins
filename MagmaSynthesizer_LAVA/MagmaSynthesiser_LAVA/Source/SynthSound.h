/*
  ==============================================================================

    SynthSound.h
    Created: 15 Dec 2020 11:00:17pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }

    bool appliesToChannel (int midiChannel) override
    {
        return true;
    }

private:

};
