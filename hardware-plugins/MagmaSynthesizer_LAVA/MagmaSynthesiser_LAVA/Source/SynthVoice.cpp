/*
  ==============================================================================

    SynthVoice.cpp
    Created: 15 Dec 2020 10:56:45pm
    Author:  thirt

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*> (sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    osc1.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    osc2.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    osc3.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));

    adsr1.noteOn();
    adsr2.noteOn();
    adsr3.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr1.noteOff();
    adsr2.noteOff();
    adsr3.noteOff();
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{

}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int numOutputChannels)
{
    juce::dsp::ProcessSpec processSpec;
    processSpec.maximumBlockSize = samplesPerBlock;
    processSpec.sampleRate = sampleRate;
    processSpec.numChannels = numOutputChannels;

    adsr1.setSampleRate(sampleRate);
    adsr2.setSampleRate(sampleRate);
    adsr3.setSampleRate(sampleRate);

    osc1.prepare (processSpec);
    osc2.prepare (processSpec);
    osc3.prepare (processSpec);

    masterGain.prepare(processSpec);
    masterGain.setGainLinear(0.01f);

    isPrepared = true;
}
 
void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    jassert(isPrepared);

    juce::dsp::AudioBlock<float> audioBlock
    {
        outputBuffer
    };

    adsr1.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
    adsr2.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
    adsr3.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);

    osc1.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    osc2.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    osc3.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

    masterGain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}
