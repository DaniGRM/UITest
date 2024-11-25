/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "TukyComponents.h"
#include "TukyColors.h"
#include "BinaryData.h"

class TukyHeader : public juce::Component
{
public:
    TukyHeader() {}

    void paint(juce::Graphics& g) override
    {
        auto bounds = getLocalBounds();

        // Fondo
        g.fillAll(TukyUI::Colors::bluegray);

        // Dibujar el logo
        auto logoHeight = bounds.getHeight() * 0.8;// Ajustamos el tamaño del logo
        auto logoWidth = (logoHeight * 3.0f); // Relación de aspecto 4:3
        auto logoBounds = juce::Rectangle<float>(10.0f, (bounds.getHeight() - logoHeight) / 2.0f, logoWidth, logoHeight);


        auto logoImage = juce::ImageFileFormat::loadFrom(BinaryData::TUKY_imagotipo2_png, BinaryData::TUKY_imagotipo2_pngSize);

        if (logoImage.isValid())
        {
            g.drawImage(logoImage, logoBounds);

        }


        
    }
};
//==============================================================================
/**
*/

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

    TukyHeader header;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UITestAudioProcessorEditor)
};
