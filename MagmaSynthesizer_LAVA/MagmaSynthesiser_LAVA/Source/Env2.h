/*
  ==============================================================================

    Env2.h
    Created: 18 Dec 2020 3:32:30pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Env2  : public juce::Component
{
public:
    Env2();
    ~Env2() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Env2)
};
