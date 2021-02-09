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
    
    juce::Slider adsr1_attackSlider;
    juce::Slider adsr1_decaySlider;
    juce::Slider adsr1_sustainSlider;
    juce::Slider adsr1_releaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr1_attackSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr1_decaySliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr1_sustainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr1_releaseSliderAttachment;

    juce::Slider adsr2_attackSlider;
    juce::Slider adsr2_decaySlider;
    juce::Slider adsr2_sustainSlider;
    juce::Slider adsr2_releaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr2_attackSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr2_decaySliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr2_sustainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr2_releaseSliderAttachment;

    juce::Slider adsr3_attackSlider;
    juce::Slider adsr3_decaySlider;
    juce::Slider adsr3_sustainSlider;
    juce::Slider adsr3_releaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr3_attackSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr3_decaySliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr3_sustainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsr3_releaseSliderAttachment;

    MagmaSynthesiser_lavaAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MagmaSynthesiser_lavaAudioProcessorEditor)
};
