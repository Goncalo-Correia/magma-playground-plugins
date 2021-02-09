/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

//==============================================================================
MagmaSynthesiser_lavaAudioProcessor::MagmaSynthesiser_lavaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
        #if ! JucePlugin_IsMidiEffect
        #if ! JucePlugin_IsSynth
                .withInput("Input", juce::AudioChannelSet::stereo(), false)
        #endif
                .withOutput("Output", juce::AudioChannelSet::stereo(), true)
        #endif
            ),
    apvts(*this, nullptr, "Parameters", createParameters())
#endif
{
    synth.addSound(new SynthSound());
    synth.addVoice(new SynthVoice());
}

MagmaSynthesiser_lavaAudioProcessor::~MagmaSynthesiser_lavaAudioProcessor()
{
}

//==============================================================================
const juce::String MagmaSynthesiser_lavaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MagmaSynthesiser_lavaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MagmaSynthesiser_lavaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MagmaSynthesiser_lavaAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MagmaSynthesiser_lavaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MagmaSynthesiser_lavaAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MagmaSynthesiser_lavaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MagmaSynthesiser_lavaAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MagmaSynthesiser_lavaAudioProcessor::getProgramName (int index)
{
    return {};
}

void MagmaSynthesiser_lavaAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MagmaSynthesiser_lavaAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate(sampleRate);

    for (int i = 0; i < synth.getNumVoices(); i++)
    {
        if (auto voice = dynamic_cast<SynthVoice*>(synth.getVoice(i)))
        {
            voice->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumOutputChannels());
        }
    }
}

void MagmaSynthesiser_lavaAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MagmaSynthesiser_lavaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MagmaSynthesiser_lavaAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int i = 0; i < synth.getNumVoices(); ++i)
    {
        if (auto voice = dynamic_cast<juce::SynthesiserVoice*>(synth.getVoice(i)))
        {
            //Osc
            //Env
            //Filter
            //LFO
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool MagmaSynthesiser_lavaAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* MagmaSynthesiser_lavaAudioProcessor::createEditor()
{
    return new MagmaSynthesiser_lavaAudioProcessorEditor (*this);
}

//==============================================================================
void MagmaSynthesiser_lavaAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MagmaSynthesiser_lavaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MagmaSynthesiser_lavaAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout MagmaSynthesiser_lavaAudioProcessor::createParameters() 
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> parameters;

    parameters.push_back(std::make_unique<juce::AudioParameterFloat>(Parameters.GAIN_ID, "Gain", 0.0f, 1.0f, 0.5f));

    //ADD PARAMETERS
    //OSC
    //ADSR
    //FILTER

    return
    {
        parameters.begin(), parameters.end()
    };
}
