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
class MagmaSynthesiser_lavaAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MagmaSynthesiser_lavaAudioProcessorEditor (MagmaSynthesiser_lavaAudioProcessor&);
    ~MagmaSynthesiser_lavaAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider gainSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;

    MagmaSynthesiser_lavaAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MagmaSynthesiser_lavaAudioProcessorEditor)
};
