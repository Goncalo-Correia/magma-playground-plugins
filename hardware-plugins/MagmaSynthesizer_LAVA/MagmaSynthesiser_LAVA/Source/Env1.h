/*
  ==============================================================================

    Env1.h
    Created: 18 Dec 2020 3:32:22pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Env1  : public juce::Component
{
public:
    Env1();
    ~Env1() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Env1)
};
