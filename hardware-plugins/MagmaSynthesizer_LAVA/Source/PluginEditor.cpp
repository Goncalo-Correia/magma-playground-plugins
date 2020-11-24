/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MagmaSynthesizer_lavaAudioProcessorEditor::MagmaSynthesizer_lavaAudioProcessorEditor (MagmaSynthesizer_lavaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    attackSlider_env1.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider_env1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20, 20);
    attackSlider_env1.setRange(0.1f, 5000.0f);
    attackSlider_env1.addListener(this);

    addAndMakeVisible(&attackSlider_env1);
}

MagmaSynthesizer_lavaAudioProcessorEditor::~MagmaSynthesizer_lavaAudioProcessorEditor()
{
}

//==============================================================================
void MagmaSynthesizer_lavaAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void MagmaSynthesizer_lavaAudioProcessorEditor::resized()
{
    attackSlider_env1.setBounds(10, 10, 20, 100);
}

void MagmaSynthesizer_lavaAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &attackSlider_env1)
    {
        audioProcessor.attackSliderValue_env1 = attackSlider_env1.getValue();
    }
}
