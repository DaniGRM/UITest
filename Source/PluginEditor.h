/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "TukyUI.h"


class UITestAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    UITestAudioProcessorEditor (UITestAudioProcessor&);
    ~UITestAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    UITestAudioProcessor& audioProcessor;

    TukyUI::Components::TukyRotarySlider slider;
    juce::Label label;

    //juce::Image logoImage;

    TukyUI::Components::TukyHeader header;

    TukyUI::Components::TukyToggleButton toggleButton1, toggleButton2;



    void toggle1Clicked()
    {
        // Lógica para el evento onClick del ToggleButton
        if (toggleButton1.getToggleState())
        {

            toggleButton2.setToggleState(false, true);
        }
        else
        {
            toggleButton2.setToggleState(true, true);
        }
    }


    void toggle2Clicked()
    {
        // Lógica para el evento onClick del ToggleButton
        if (toggleButton2.getToggleState())
        {
            toggleButton1.setToggleState(false, true);
        }
        else
        {
            toggleButton1.setToggleState(true, true);
        }
    }
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UITestAudioProcessorEditor)
};
