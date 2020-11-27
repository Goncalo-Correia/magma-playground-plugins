/*
  ==============================================================================

    SynthEnvelope.h
    Created: 26 Nov 2020 11:25:10pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Parameters.h"

//==============================================================================
/*
*/
class SynthEnvelope  : public juce::Component
{
public:
    SynthEnvelope();
    ~SynthEnvelope() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthEnvelope)
};
