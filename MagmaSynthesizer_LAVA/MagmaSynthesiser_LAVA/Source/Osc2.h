/*
  ==============================================================================

    Osc2.h
    Created: 15 Dec 2020 10:23:08pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Osc2  : public juce::Component
{
public:
    Osc2();
    ~Osc2() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Osc2)
};
