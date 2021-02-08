/*
  ==============================================================================

    Osc2.cpp
    Created: 15 Dec 2020 10:23:08pm
    Author:  thirt

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Osc2.h"

//==============================================================================
Osc2::Osc2()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Osc2::~Osc2()
{
}

void Osc2::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Osc2", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void Osc2::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
