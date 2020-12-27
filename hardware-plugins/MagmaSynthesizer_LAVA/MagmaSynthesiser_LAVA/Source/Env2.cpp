/*
  ==============================================================================

    Env2.cpp
    Created: 18 Dec 2020 3:32:30pm
    Author:  thirt

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Env2.h"

//==============================================================================
Env2::Env2()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Env2::~Env2()
{
}

void Env2::paint (juce::Graphics& g)
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
    g.drawText ("Env2", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void Env2::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
