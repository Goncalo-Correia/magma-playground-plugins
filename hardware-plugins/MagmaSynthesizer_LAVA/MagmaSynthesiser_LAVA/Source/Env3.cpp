/*
  ==============================================================================

    Env3.cpp
    Created: 18 Dec 2020 3:32:41pm
    Author:  thirt

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Env3.h"

//==============================================================================
Env3::Env3()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Env3::~Env3()
{
}

void Env3::paint (juce::Graphics& g)
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
    g.drawText ("Env3", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void Env3::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
