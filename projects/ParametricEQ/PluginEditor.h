#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "MrtaLAF.h"

class ParametricEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ParametricEQAudioProcessorEditor (ParametricEQAudioProcessor&);
    ~ParametricEQAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    static const int BandWidth { 250 };
    static const int ParamHeight { 80 };
    static const int ParamsPerBand { 4 };
    static const int NumOfBands { 3 };

private:
    ParametricEQAudioProcessor& audioProcessor;
    mrta::GenericParameterEditor band0ParameterEditor;
    mrta::GenericParameterEditor band1ParameterEditor;
    mrta::GenericParameterEditor band2ParameterEditor;

    GUI::MrtaLAF laf;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParametricEQAudioProcessorEditor)
};