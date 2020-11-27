/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SynthEnvelope.h"
#include "SynthOscillator.h"
#include "SynthFilter.h"

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

    void sliderValueChanged(juce::Slider* slider) override; //inherited from juce::Slider::Listener

private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MagmaSynthesizer_lavaAudioProcessor& audioProcessor;

    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttachment;
    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;

    juce::Slider attackSlider_env1;
    juce::Slider decaySlider_env1;
    juce::Slider sustainSlider_env1;
    juce::Slider releaseSlider_env1;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MagmaSynthesizer_lavaAudioProcessorEditor)

        //==============================================================================

    SynthOscillator osc1;
    SynthOscillator osc2;
    SynthOscillator osc3;

    SynthEnvelope env1;
    SynthEnvelope env2;
    SynthEnvelope env3;

    SynthFilter filter1;
    SynthFilter filter2;
    SynthFilter filter3;
    SynthFilter masterFilter;
};
