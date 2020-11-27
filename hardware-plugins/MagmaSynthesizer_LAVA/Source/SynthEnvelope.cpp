/*
  ==============================================================================

    SynthEnvelope.cpp
    Created: 26 Nov 2020 11:25:10pm
    Author:  thirt

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SynthEnvelope.h"

//==============================================================================
SynthEnvelope::SynthEnvelope()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SynthEnvelope::~SynthEnvelope()
{
}

void SynthEnvelope::paint (juce::Graphics& g)
{
    juce::Rectangle<float> envelope(0.0f, 0.0f, 300.0f, 150.0f);
    g.setColour(juce::Colours::darkgrey);
    g.fillRect(envelope);
    g.drawRoundedRectangle(envelope, 0.0f, 0.0f);
}

void SynthEnvelope::resized()
{

}
