/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

//==============================================================================
MagmaSynthesizer_lavaAudioProcessorEditor::MagmaSynthesizer_lavaAudioProcessorEditor (MagmaSynthesizer_lavaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    attackSlider_env1.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider_env1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 30); 
    attackSlider_env1.setRange(0.1f, 5000.0f);
    attackSlider_env1.setValue(0.1f);
    attackSlider_env1.addListener(this);
    addAndMakeVisible(&attackSlider_env1);

    attackSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.apvts, ATTACK_ENV1_ID, attackSlider_env1);
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
    attackSlider_env1.setBounds(10, 10, 50, 150);
}

void MagmaSynthesizer_lavaAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &attackSlider_env1)
    {
        audioProcessor.attackTime_env1 = attackSlider_env1.getValue();
    }
}
