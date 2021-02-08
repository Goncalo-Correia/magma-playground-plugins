/*
  ==============================================================================

    Osc3.h
    Created: 15 Dec 2020 10:23:14pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Osc3  : public juce::Component
{
public:
    Osc3();
    ~Osc3() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Osc3)
};
