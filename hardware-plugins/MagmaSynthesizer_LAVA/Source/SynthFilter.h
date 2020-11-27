/*
  ==============================================================================

    SynthFilter.h
    Created: 26 Nov 2020 11:25:19pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SynthFilter  : public juce::Component
{
public:
    SynthFilter();
    ~SynthFilter() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFilter)
};
