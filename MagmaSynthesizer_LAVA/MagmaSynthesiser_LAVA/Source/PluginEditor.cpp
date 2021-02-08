/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MagmaSynthesiser_lavaAudioProcessorEditor::MagmaSynthesiser_lavaAudioProcessorEditor (MagmaSynthesiser_lavaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(gainSlider);

    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", gainSlider);

    setSize (400, 300);
}

MagmaSynthesiser_lavaAudioProcessorEditor::~MagmaSynthesiser_lavaAudioProcessorEditor()
{
}

//==============================================================================
void MagmaSynthesiser_lavaAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MagmaSynthesiser_lavaAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 50, 200, 100);
}
