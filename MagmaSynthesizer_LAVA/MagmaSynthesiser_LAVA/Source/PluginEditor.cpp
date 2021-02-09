/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

//==============================================================================
MagmaSynthesiser_lavaAudioProcessorEditor::MagmaSynthesiser_lavaAudioProcessorEditor (MagmaSynthesiser_lavaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(gainSlider);

    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, GAIN_ID, gainSlider);

    adsr1_attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR1_ATTACK_ID, adsr1_attackSlider);
    adsr1_decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR1_DECAY_ID, adsr1_decaySlider);
    adsr1_sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR1_SUSTAIN_ID, adsr1_sustainSlider);
    adsr1_releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR1_RELEASE_ID, adsr1_releaseSlider);

    adsr2_attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR2_ATTACK_ID, adsr2_attackSlider);
    adsr2_decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR2_DECAY_ID, adsr2_decaySlider);
    adsr2_sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR2_SUSTAIN_ID, adsr2_sustainSlider);
    adsr2_releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR2_RELEASE_ID, adsr2_releaseSlider);

    adsr3_attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR3_ATTACK_ID, adsr3_attackSlider);
    adsr3_decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR3_DECAY_ID, adsr3_decaySlider);
    adsr3_sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR3_SUSTAIN_ID, adsr3_sustainSlider);
    adsr3_releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, ADSR3_RELEASE_ID, adsr3_releaseSlider);

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
