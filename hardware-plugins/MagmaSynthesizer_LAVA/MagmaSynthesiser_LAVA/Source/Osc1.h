/*
  ==============================================================================

    Osc1.h
    Created: 15 Dec 2020 10:23:02pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Osc1  : public juce::Component
{
public:
    Osc1();
    ~Osc1() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Osc1)
};
