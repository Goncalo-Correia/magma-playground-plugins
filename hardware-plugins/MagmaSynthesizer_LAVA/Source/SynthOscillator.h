/*
  ==============================================================================

    SynthOscillator.h
    Created: 26 Nov 2020 11:25:00pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SynthOscillator  : public juce::Component
{
public:
    SynthOscillator();
    ~SynthOscillator() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthOscillator)
};
