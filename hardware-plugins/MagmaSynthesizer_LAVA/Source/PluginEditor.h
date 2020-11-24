/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MagmaSynthesizer_lavaAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    MagmaSynthesizer_lavaAudioProcessorEditor (MagmaSynthesizer_lavaAudioProcessor&);
    ~MagmaSynthesizer_lavaAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    juce::Slider attackSlider_env1;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MagmaSynthesizer_lavaAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MagmaSynthesizer_lavaAudioProcessorEditor)
};
