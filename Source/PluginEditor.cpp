/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "TukyUI.h"

//==============================================================================
UITestAudioProcessorEditor::UITestAudioProcessorEditor (UITestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), slider(*audioProcessor.apvts.getParameter("Slider")), header("TukTuky2"),
    toggleButton1(), toggleButton2()
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

  /*  logoImage = juce::ImageFileFormat::loadFrom(BinaryData::TUKY_imagotipo_png, BinaryData::TUKY_imagotipo_pngSize);

    if (!logoImage.isValid())
        DBG("Error: No se pudo cargar el logo.");*/
    addAndMakeVisible(slider);
    addAndMakeVisible(label);
    addAndMakeVisible(header);

    toggleButton1.setButtonText("Normal");
    toggleButton2.setButtonText("Sync");
    toggleButton1.onClick = [this]() { toggle1Clicked(); };
    toggleButton2.onClick = [this]() { toggle2Clicked(); };
    addAndMakeVisible(toggleButton1);
    addAndMakeVisible(toggleButton2);
    setSize (600, 400);
}

UITestAudioProcessorEditor::~UITestAudioProcessorEditor()
{
}

//==============================================================================
void UITestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (TukyUI::Colors::background);
    //if (logoImage.isValid())
    //{
    //    // Dibuja el logo centrado en el área del componente
    //    auto bounds = getLocalBounds();
    //    g.drawImageWithin(logoImage, bounds.getX() + bounds.getWidth() * 0.5, bounds.getY(), bounds.getWidth() * 0.5, bounds.getHeight() * 0.5,
    //        juce::RectanglePlacement::xLeft);
    //}
}

void UITestAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto bounds = getLocalBounds();

    auto headerHeight = bounds.getHeight() * 0.1;
    header.setBounds(bounds.removeFromTop(headerHeight));

    auto labelBounds = bounds.removeFromBottom(bounds.getHeight() * 0.5);
    slider.setBounds(bounds);


    label.setBounds(labelBounds.withHeight(30).withY(bounds.getBottom() - 20));
    label.setText("DELAY", juce::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);
    label.setColour(juce::Label::textColourId, TukyUI::Colors::blue); // Cambiar color del texto
    label.setFont(TukyUI::Fonts::label); // Cambiar fuente del texto

    toggleButton1.setBounds(150, 220, 100, 20);
    toggleButton2.setBounds(150, 270, 100, 20);

}
