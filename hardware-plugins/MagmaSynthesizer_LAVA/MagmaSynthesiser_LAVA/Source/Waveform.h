/*
  ==============================================================================

    Waveform.h
    Created: 15 Dec 2020 10:49:56pm
    Author:  thirt

  ==============================================================================
*/

#pragma once

#include "WaveType.h"

class WaveForm 
{
public:

    float WaveForm::generateWaveForm (WaveType waveType, float x)
    {
        return calculateWaveForm(waveType, x);
    }

private:

    float calculateWaveForm(WaveType waveType, float x)
    {
        if (waveType == WaveType::SINE)
        {
            return std::sin(x);
        }

        if (waveType == WaveType::SAW)
        {
            return x / juce::MathConstants<float>::pi;
        }

        if (waveType == WaveType::SQUARE)
        {
            return x < 0.0f ? -1.0f : 1.0f;
        }
    }
};