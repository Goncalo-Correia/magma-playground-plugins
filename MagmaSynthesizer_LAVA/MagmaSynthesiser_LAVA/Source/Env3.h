/*
  ==============================================================================

    Env3.h
    Created: 18 Dec 2020 3:32:41pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Env3  : public juce::Component
{
public:
    Env3();
    ~Env3() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Env3)
};
