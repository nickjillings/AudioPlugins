/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PingPongDistortionAudioProcessorEditor::PingPongDistortionAudioProcessorEditor (PingPongDistortionAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (leftGain = new Slider ("new slider"));
    leftGain->setRange (-24, 24, 0);
    leftGain->setSliderStyle (Slider::RotaryHorizontalDrag);
    leftGain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    leftGain->addListener (this);

    addAndMakeVisible (rightGain = new Slider ("new slider"));
    rightGain->setRange (-24, 24, 0);
    rightGain->setSliderStyle (Slider::RotaryHorizontalDrag);
    rightGain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightGain->addListener (this);

    addAndMakeVisible (rightDelay = new Slider ("new slider"));
    rightDelay->setRange (100, 1000, 1);
    rightDelay->setSliderStyle (Slider::LinearHorizontal);
    rightDelay->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rightDelay->setColour (Slider::textBoxTextColourId, Colours::white);
    rightDelay->setColour (Slider::textBoxBackgroundColourId, Colours::black);
    rightDelay->addListener (this);

    addAndMakeVisible (leftDelay = new Slider ("new slider"));
    leftDelay->setRange (100, 1000, 1);
    leftDelay->setSliderStyle (Slider::LinearHorizontal);
    leftDelay->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    leftDelay->setColour (Slider::textBoxTextColourId, Colours::white);
    leftDelay->setColour (Slider::textBoxBackgroundColourId, Colours::black);
    leftDelay->addListener (this);

    addAndMakeVisible (rightLP = new Slider ("new slider"));
    rightLP->setRange (250, 5000, 0);
    rightLP->setSliderStyle (Slider::RotaryHorizontalDrag);
    rightLP->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightLP->addListener (this);

    addAndMakeVisible (leftLP = new Slider ("new slider"));
    leftLP->setRange (250, 5000, 0);
    leftLP->setSliderStyle (Slider::RotaryHorizontalDrag);
    leftLP->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    leftLP->addListener (this);

    addAndMakeVisible (rightDistGain = new Slider ("new slider"));
    rightDistGain->setRange (1, 10, 0);
    rightDistGain->setSliderStyle (Slider::RotaryHorizontalDrag);
    rightDistGain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightDistGain->setColour (Slider::thumbColourId, Colour (0xffffbbce));
    rightDistGain->setColour (Slider::rotarySliderFillColourId, Colour (0x7fff0046));
    rightDistGain->addListener (this);

    addAndMakeVisible (rightDistGain2 = new Slider ("new slider"));
    rightDistGain2->setRange (1, 10, 0);
    rightDistGain2->setSliderStyle (Slider::RotaryHorizontalDrag);
    rightDistGain2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightDistGain2->setColour (Slider::thumbColourId, Colour (0xffffbbce));
    rightDistGain2->setColour (Slider::rotarySliderFillColourId, Colour (0x7fff0046));
    rightDistGain2->addListener (this);

    addAndMakeVisible (feedCrossRight = new Slider ("new slider"));
    feedCrossRight->setRange (-12, 0, 0);
    feedCrossRight->setSliderStyle (Slider::RotaryHorizontalDrag);
    feedCrossRight->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    feedCrossRight->setColour (Slider::thumbColourId, Colour (0xfffffbbb));
    feedCrossRight->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffbf00));
    feedCrossRight->addListener (this);

    addAndMakeVisible (feedCrossLeft = new Slider ("new slider"));
    feedCrossLeft->setRange (-12, 0, 0);
    feedCrossLeft->setSliderStyle (Slider::RotaryHorizontalDrag);
    feedCrossLeft->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    feedCrossLeft->setColour (Slider::thumbColourId, Colour (0xfffffbbb));
    feedCrossLeft->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffbf00));
    feedCrossLeft->addListener (this);

    addAndMakeVisible (crossOverLeft = new Slider ("Left Cross Over"));
    crossOverLeft->setRange (500, 5000, 0);
    crossOverLeft->setSliderStyle (Slider::RotaryHorizontalDrag);
    crossOverLeft->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    crossOverLeft->addListener (this);

    addAndMakeVisible (crossOverRight = new Slider ("Right Cross Over"));
    crossOverRight->setRange (500, 5000, 0);
    crossOverRight->setSliderStyle (Slider::RotaryHorizontalDrag);
    crossOverRight->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    crossOverRight->addListener (this);

    addAndMakeVisible (leftBypassGain = new Slider ("new slider"));
    leftBypassGain->setRange (-24, 24, 0);
    leftBypassGain->setSliderStyle (Slider::RotaryHorizontalDrag);
    leftBypassGain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    leftBypassGain->setColour (Slider::thumbColourId, Colour (0xfffffbbb));
    leftBypassGain->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffbf00));
    leftBypassGain->addListener (this);

    addAndMakeVisible (rightBypassGain = new Slider ("new slider"));
    rightBypassGain->setRange (-24, 24, 0);
    rightBypassGain->setSliderStyle (Slider::RotaryHorizontalDrag);
    rightBypassGain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightBypassGain->setColour (Slider::thumbColourId, Colour (0xfffffbbb));
    rightBypassGain->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffbf00));
    rightBypassGain->addListener (this);

    addAndMakeVisible (leftBypassMute = new TextButton ("new button"));
    leftBypassMute->setButtonText (TRANS("mute"));
    leftBypassMute->addListener (this);

    addAndMakeVisible (rightBypassMute = new TextButton ("new button"));
    rightBypassMute->setButtonText (TRANS("mute"));
    rightBypassMute->addListener (this);

    addAndMakeVisible (leftDelayFeedMute = new TextButton ("new button"));
    leftDelayFeedMute->setButtonText (TRANS("mute"));
    leftDelayFeedMute->addListener (this);

    addAndMakeVisible (rightDelayFeedMute = new TextButton ("new button"));
    rightDelayFeedMute->setButtonText (TRANS("mute"));
    rightDelayFeedMute->addListener (this);

    addAndMakeVisible (rightCrossOverToggle = new TextButton ("new button"));
    rightCrossOverToggle->setButtonText (TRANS("off"));
    rightCrossOverToggle->addListener (this);

    addAndMakeVisible (leftCrossOverToggle = new TextButton ("new button"));
    leftCrossOverToggle->setButtonText (TRANS("off"));
    leftCrossOverToggle->addListener (this);

    addAndMakeVisible (leftDistortionMode = new ComboBox ("new combo box"));
    leftDistortionMode->setEditableText (false);
    leftDistortionMode->setJustificationType (Justification::centredLeft);
    leftDistortionMode->setTextWhenNothingSelected (TRANS("Distortion Mode"));
    leftDistortionMode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    leftDistortionMode->addItem (TRANS("Soft (exponential)"), 1);
    leftDistortionMode->addItem (TRANS("Soft (sine)"), 2);
    leftDistortionMode->addItem (TRANS("Hard"), 3);
    leftDistortionMode->addItem (TRANS("Half Wave Rect"), 4);
    leftDistortionMode->addItem (TRANS("Full Wave Rect"), 5);
    leftDistortionMode->addListener (this);

    addAndMakeVisible (righttDistortionMode = new ComboBox ("new combo box"));
    righttDistortionMode->setEditableText (false);
    righttDistortionMode->setJustificationType (Justification::centredLeft);
    righttDistortionMode->setTextWhenNothingSelected (TRANS("Distortion Mode"));
    righttDistortionMode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    righttDistortionMode->addItem (TRANS("Soft (exponential)"), 1);
    righttDistortionMode->addItem (TRANS("Soft (sine)"), 2);
    righttDistortionMode->addItem (TRANS("Hard"), 3);
    righttDistortionMode->addItem (TRANS("Half Wave Rect"), 4);
    righttDistortionMode->addItem (TRANS("Full Wave Rect"), 5);
    righttDistortionMode->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 500);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);

    // Initialise Parameters
    PingPongDistortionAudioProcessor *ourProcessor = getProcessor();
    leftGain->setValue(ourProcessor->getPreGains(true));
    rightGain->setValue(ourProcessor->getPreGains(true));
    leftDelay->setValue(ourProcessor->getDelayTimeSeconds(true));
    rightDelay->setValue(ourProcessor->getDelayTimeSeconds(false));
    rightLP->setValue(ourProcessor->getCutoffFrequency(false));
    leftLP->setValue(ourProcessor->getCutoffFrequency(true));
    rightDistGain->setValue(ourProcessor->getDistortionGain(false));
    rightDistGain2->setValue(ourProcessor->getDistortionGain(true));
    feedCrossRight->setValue(ourProcessor->getCrossFeedGains(false));
    feedCrossLeft->setValue(ourProcessor->getCrossFeedGains(true));
    crossOverLeft->setValue(ourProcessor->getCrossOverFrequency(true));
    crossOverRight->setValue(ourProcessor->getCrossOverFrequency(false));
    leftBypassGain->setValue(ourProcessor->getBypassGains(true));
    rightBypassGain->setValue(ourProcessor->getBypassGains(false));

    leftBypassMute->setToggleState(ourProcessor->getBypassMuteState(true), dontSendNotification);
    rightBypassMute->setToggleState(ourProcessor->getBypassMuteState(false), dontSendNotification);
    leftDelayFeedMute->setToggleState(ourProcessor->getDelayMuteState(true), dontSendNotification);
    rightDelayFeedMute->setToggleState(ourProcessor->getDelayMuteState(false), dontSendNotification);
    rightCrossOverToggle->setToggleState(ourProcessor->getCrossOverOnState(false), dontSendNotification);
    leftCrossOverToggle->setToggleState(ourProcessor->getCrossOverOnState(true), dontSendNotification);
    
    righttDistortionMode->setSelectedId(ourProcessor->getDistortionMode(false)+1);
    leftDistortionMode->setSelectedId(ourProcessor->getDistortionMode(true)+1);
    //[/Constructor]
}

PingPongDistortionAudioProcessorEditor::~PingPongDistortionAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    leftGain = nullptr;
    rightGain = nullptr;
    rightDelay = nullptr;
    leftDelay = nullptr;
    rightLP = nullptr;
    leftLP = nullptr;
    rightDistGain = nullptr;
    rightDistGain2 = nullptr;
    feedCrossRight = nullptr;
    feedCrossLeft = nullptr;
    crossOverLeft = nullptr;
    crossOverRight = nullptr;
    leftBypassGain = nullptr;
    rightBypassGain = nullptr;
    leftBypassMute = nullptr;
    rightBypassMute = nullptr;
    leftDelayFeedMute = nullptr;
    rightDelayFeedMute = nullptr;
    rightCrossOverToggle = nullptr;
    leftCrossOverToggle = nullptr;
    leftDistortionMode = nullptr;
    righttDistortionMode = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PingPongDistortionAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff383838));

    g.setColour (Colour (0xff383838));
    g.fillRoundedRectangle (198.0f, 395.0f, 100.0f, 98.0f, 10.000f);

    g.setColour (Colour (0xff90a52a));
    g.drawRoundedRectangle (198.0f, 395.0f, 100.0f, 98.0f, 10.000f, 5.000f);

    g.setColour (Colour (0xff383838));
    g.fillRoundedRectangle (198.0f, 3.0f, 100.0f, 98.0f, 10.000f);

    g.setColour (Colour (0xff90a52a));
    g.drawRoundedRectangle (198.0f, 3.0f, 100.0f, 98.0f, 10.000f, 5.000f);

    g.setColour (Colour (0xff5e2aa5));
    g.fillPath (internalPath1);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath1, PathStrokeType (5.000f));

    g.setColour (Colour (0xff2aa597));
    g.fillPath (internalPath2);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath2, PathStrokeType (5.000f));

    g.setColour (Colour (0xff3a2aa5));
    g.fillPath (internalPath3);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath3, PathStrokeType (5.000f));

    g.setColour (Colour (0xff592aa5));
    g.fillPath (internalPath4);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath4, PathStrokeType (5.000f));

    g.setColour (Colour (0xff712aa5));
    g.fillPath (internalPath5);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath5, PathStrokeType (5.000f));

    g.setColour (Colour (0xff2aa557));
    g.fillPath (internalPath6);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath6, PathStrokeType (5.000f));

    g.setColour (Colour (0xff942aa5));
    g.fillPath (internalPath7);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath7, PathStrokeType (5.000f));

    g.setColour (Colour (0xff36a52a));
    g.fillPath (internalPath8);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath8, PathStrokeType (5.000f));

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Left In"),
                4, 70, 60, 30,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Right In"),
                4, 406, 60, 30,
                Justification::centred, true);

    g.setColour (Colour (0xff2a74a5));
    g.fillEllipse (76.0f, 54.0f, 64.0f, 64.0f);

    g.setColour (Colour (0xff2a74a5));
    g.fillEllipse (76.0f, 390.0f, 64.0f, 64.0f);

    g.setColour (Colour (0xff2aa1a5));
    g.fillRect (508, 64, 156, 40);

    g.setColour (Colour (0xff2aa1a5));
    g.fillRect (508, 398, 156, 40);

    g.setColour (Colours::black);
    g.setFont (Font (10.50f, Font::italic));
    g.drawText (TRANS("Delay"),
                508, 70, 156, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (10.50f, Font::italic));
    g.drawText (TRANS("Delay"),
                508, 406, 156, 30,
                Justification::centred, true);

    g.setColour (Colour (0xff2a72a5));
    g.fillEllipse (516.0f, 334.0f, 56.0f, 54.0f);

    g.setColour (Colour (0xffa52a7b));
    g.fillRoundedRectangle (604.0f, 334.0f, 60.0f, 56.0f, 10.000f);

    g.setColour (Colour (0xff2a72a5));
    g.fillEllipse (516.0f, 110.0f, 56.0f, 54.0f);

    g.setColour (Colour (0xffa52a7b));
    g.fillRoundedRectangle (604.0f, 110.0f, 60.0f, 56.0f, 10.000f);

    g.setColour (Colour (0xffb3b3b3));
    g.setFont (Font (9.90f, Font::plain));
    g.drawText (TRANS("Gain"),
                84, 366, 44, 30,
                Justification::centred, true);

    g.setColour (Colour (0xffb3b3b3));
    g.setFont (Font (9.90f, Font::plain));
    g.drawText (TRANS("Gain"),
                84, 30, 44, 30,
                Justification::centred, true);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Low Pass"),
                516, 168, 56, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Distortion Gain"),
                600, 168, 64, 24,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("250Hz"),
                500, 382, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("250Hz"),
                500, 158, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("5kHz"),
                548, 382, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("5kHz"),
                548, 158, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("0dB"),
                588, 382, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("0dB"),
                588, 158, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("20dB"),
                644, 158, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("20dB"),
                644, 382, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-24dB"),
                68, 110, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("+24dB"),
                116, 110, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-24dB"),
                68, 446, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("+24dB"),
                116, 446, 32, 16,
                Justification::centred, true);

    g.setColour (Colour (0xffa52a58));
    g.fillEllipse (308.0f, 406.0f, 36.0f, 34.0f);

    g.setColour (Colour (0xffa52a58));
    g.fillEllipse (364.0f, 70.0f, 36.0f, 34.0f);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Low Pass"),
                516, 312, 56, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Distortion Gain"),
                600, 312, 64, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffa55e2a));
    g.fillPath (internalPath9);

    g.setColour (Colour (0xffa55e2a));
    g.fillPath (internalPath10);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Crossfeed Gains"),
                330, 198, 68, 24,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-12dB"),
                292, 262, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("0dB"),
                396, 278, 32, 16,
                Justification::centred, true);

    g.setColour (Colour (0xffa5672a));
    g.fillPath (internalPath11);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath11, PathStrokeType (5.000f));

    g.setColour (Colour (0xff2a9ba5));
    g.fillPath (internalPath12);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath12, PathStrokeType (5.000f));

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("100ms"),
                500, 46, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("1000ms"),
                636, 46, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("100ms"),
                500, 438, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("1000ms"),
                636, 438, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("0dB"),
                332, 262, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-12dB"),
                348, 278, 32, 16,
                Justification::centred, true);

    g.setColour (Colour (0xff2a6ba5));
    g.fillPath (internalPath13);

    g.setColour (Colour (0xff2a6ba5));
    g.fillPath (internalPath14);

    g.setColour (Colour (0xff5e2aa5));
    g.fillPath (internalPath15);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath15, PathStrokeType (5.000f));

    g.setColour (Colour (0xffa52a78));
    g.fillPath (internalPath16);
    g.setColour (Colour (0xff2a96a5));
    g.strokePath (internalPath16, PathStrokeType (5.000f));

    g.setColour (Colour (0xff5e2aa5));
    g.fillPath (internalPath17);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath17, PathStrokeType (5.000f));

    g.setColour (Colour (0xff5e2aa5));
    g.fillPath (internalPath18);
    g.setColour (Colour (0xffa5962a));
    g.strokePath (internalPath18, PathStrokeType (5.000f));

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Crossover"),
                200, 4, 96, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Crossover"),
                200, 396, 96, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffa52a9c));
    g.fillPath (internalPath19);
    g.setColour (Colour (0xff962aa5));
    g.strokePath (internalPath19, PathStrokeType (5.000f));

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Bypass Gain"),
                387, 44, 68, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffebebeb));
    g.setFont (Font (9.60f, Font::plain));
    g.drawText (TRANS("Bypass Gain"),
                371, 428, 68, 24,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-24dB"),
                371, 44, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("-24dB"),
                355, 484, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("+24dB"),
                435, 44, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("+24dB"),
                419, 484, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("500Hz"),
                203, 68, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("500Hz"),
                203, 460, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("5kHz"),
                259, 68, 32, 16,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font (6.90f, Font::plain));
    g.drawText (TRANS("5kHz"),
                259, 460, 32, 16,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PingPongDistortionAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    leftGain->setBounds (76, 54, 64, 64);
    rightGain->setBounds (76, 390, 64, 64);
    rightDelay->setBounds (512, 400, 152, 64);
    leftDelay->setBounds (512, 40, 152, 64);
    rightLP->setBounds (520, 336, 48, 48);
    leftLP->setBounds (520, 112, 48, 48);
    rightDistGain->setBounds (608, 336, 56, 56);
    rightDistGain2->setBounds (608, 112, 56, 56);
    feedCrossRight->setBounds (360, 232, 56, 56);
    feedCrossLeft->setBounds (304, 216, 56, 56);
    crossOverLeft->setBounds (200, 40, 96, 40);
    crossOverRight->setBounds (200, 432, 96, 40);
    leftBypassGain->setBounds (392, 0, 56, 56);
    rightBypassGain->setBounds (376, 448, 56, 56);
    leftBypassMute->setBounds (320, 24, 48, 16);
    rightBypassMute->setBounds (320, 472, 48, 16);
    leftDelayFeedMute->setBounds (456, 80, 48, 16);
    rightDelayFeedMute->setBounds (456, 416, 48, 16);
    rightCrossOverToggle->setBounds (192, 392, 24, 16);
    leftCrossOverToggle->setBounds (192, 0, 24, 16);
    leftDistortionMode->setBounds (584, 192, 128, 24);
    righttDistortionMode->setBounds (584, 288, 128, 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (184.0f, 32.0f);
    internalPath1.lineTo (736.0f, 32.0f);
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (752.0f, 480.0f);
    internalPath2.lineTo (184.0f, 480.0f);
    internalPath2.closeSubPath();

    internalPath3.clear();
    internalPath3.startNewSubPath (328.0f, 144.0f);
    internalPath3.lineTo (328.0f, 424.0f);
    internalPath3.closeSubPath();

    internalPath4.clear();
    internalPath4.startNewSubPath (752.0f, 144.0f);
    internalPath4.lineTo (328.0f, 144.0f);
    internalPath4.closeSubPath();

    internalPath5.clear();
    internalPath5.startNewSubPath (384.0f, 88.0f);
    internalPath5.lineTo (384.0f, 360.0f);
    internalPath5.closeSubPath();

    internalPath6.clear();
    internalPath6.startNewSubPath (728.0f, 360.0f);
    internalPath6.lineTo (384.0f, 360.0f);
    internalPath6.closeSubPath();

    internalPath7.clear();
    internalPath7.startNewSubPath (232.0f, 424.0f);
    internalPath7.lineTo (792.0f, 424.0f);
    internalPath7.lineTo (140.0f, 424.0f);
    internalPath7.closeSubPath();

    internalPath8.clear();
    internalPath8.startNewSubPath (240.0f, 88.0f);
    internalPath8.lineTo (792.0f, 88.0f);
    internalPath8.lineTo (140.0f, 88.0f);
    internalPath8.closeSubPath();

    internalPath9.clear();
    internalPath9.startNewSubPath (386.0f, 230.0f);
    internalPath9.lineTo (416.0f, 280.0f);
    internalPath9.lineTo (356.0f, 280.0f);
    internalPath9.closeSubPath();

    internalPath10.clear();
    internalPath10.startNewSubPath (330.0f, 272.0f);
    internalPath10.lineTo (360.0f, 224.0f);
    internalPath10.lineTo (300.0f, 224.0f);
    internalPath10.closeSubPath();

    internalPath11.clear();
    internalPath11.startNewSubPath (728.0f, 360.0f);
    internalPath11.lineTo (728.0f, 424.0f);
    internalPath11.closeSubPath();

    internalPath12.clear();
    internalPath12.startNewSubPath (752.0f, 88.0f);
    internalPath12.lineTo (752.0f, 144.0f);
    internalPath12.closeSubPath();

    internalPath13.clear();
    internalPath13.startNewSubPath (394.0f, 6.0f);
    internalPath13.lineTo (450.0f, 32.0f);
    internalPath13.lineTo (394.0f, 54.0f);
    internalPath13.closeSubPath();

    internalPath14.clear();
    internalPath14.startNewSubPath (378.0f, 446.0f);
    internalPath14.lineTo (437.0f, 476.0f);
    internalPath14.lineTo (378.0f, 502.0f);
    internalPath14.closeSubPath();

    internalPath15.clear();
    internalPath15.startNewSubPath (184.0f, 448.0f);
    internalPath15.lineTo (184.0f, 480.0f);
    internalPath15.lineTo (184.0f, 424.0f);
    internalPath15.closeSubPath();

    internalPath16.clear();
    internalPath16.startNewSubPath (752.0f, 424.0f);
    internalPath16.lineTo (752.0f, 480.0f);
    internalPath16.closeSubPath();

    internalPath17.clear();
    internalPath17.startNewSubPath (184.0f, 32.0f);
    internalPath17.lineTo (184.0f, 88.0f);
    internalPath17.closeSubPath();

    internalPath18.clear();
    internalPath18.startNewSubPath (736.0f, 88.0f);
    internalPath18.lineTo (736.0f, 32.0f);
    internalPath18.closeSubPath();

    internalPath19.clear();
    internalPath19.startNewSubPath (768.0f, 88.0f);
    internalPath19.lineTo (768.0f, 424.0f);
    internalPath19.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PingPongDistortionAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    PingPongDistortionAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == leftGain)
    {
        //[UserSliderCode_leftGain] -- add your slider handling code here..
        float gain = leftGain->getValue();
        gain = powf(10.0, gain/20.0);
        ourProcessor->setPreGains(gain, true);
        //[/UserSliderCode_leftGain]
    }
    else if (sliderThatWasMoved == rightGain)
    {
        //[UserSliderCode_rightGain] -- add your slider handling code here..
        float gain = rightGain->getValue();
        gain = powf(10.0, gain/20.0);
        ourProcessor->setPreGains(gain, false);
        //[/UserSliderCode_rightGain]
    }
    else if (sliderThatWasMoved == rightDelay)
    {
        //[UserSliderCode_rightDelay] -- add your slider handling code here..
        ourProcessor->setDelayTimeSeconds(rightDelay->getValue()/1000.0, false);
        //[/UserSliderCode_rightDelay]
    }
    else if (sliderThatWasMoved == leftDelay)
    {
        //[UserSliderCode_leftDelay] -- add your slider handling code here..
        ourProcessor->setDelayTimeSeconds(leftDelay->getValue()/1000.0, true);
        //[/UserSliderCode_leftDelay]
    }
    else if (sliderThatWasMoved == rightLP)
    {
        //[UserSliderCode_rightLP] -- add your slider handling code here..
        ourProcessor->setCutoffFrequency(rightLP->getValue(), false);
        //[/UserSliderCode_rightLP]
    }
    else if (sliderThatWasMoved == leftLP)
    {
        //[UserSliderCode_leftLP] -- add your slider handling code here..
        ourProcessor->setCutoffFrequency(leftLP->getValue(), true);
        //[/UserSliderCode_leftLP]
    }
    else if (sliderThatWasMoved == rightDistGain)
    {
        //[UserSliderCode_rightDistGain] -- add your slider handling code here..
        float gain = rightDistGain->getValue();
        gain = powf(10.0,gain/20.0);
        ourProcessor->setDistortionGains(gain, false);
        //[/UserSliderCode_rightDistGain]
    }
    else if (sliderThatWasMoved == rightDistGain2)
    {
        //[UserSliderCode_rightDistGain2] -- add your slider handling code here..
        float gain = rightDistGain2->getValue();
        gain = powf(10.0,gain/20.0);
        ourProcessor->setDistortionGains(gain, true);
        //[/UserSliderCode_rightDistGain2]
    }
    else if (sliderThatWasMoved == feedCrossRight)
    {
        //[UserSliderCode_feedCrossRight] -- add your slider handling code here..
        float gain = feedCrossRight->getValue();
        gain = powf(10.0,gain/20.0);
        ourProcessor->setCrossFeedGains(gain, false);
        //[/UserSliderCode_feedCrossRight]
    }
    else if (sliderThatWasMoved == feedCrossLeft)
    {
        //[UserSliderCode_feedCrossLeft] -- add your slider handling code here..
        float gain = feedCrossLeft->getValue();
        gain = powf(10.0,gain/20.0);
        ourProcessor->setCrossFeedGains(gain, true);
        //[/UserSliderCode_feedCrossLeft]
    }
    else if (sliderThatWasMoved == crossOverLeft)
    {
        //[UserSliderCode_crossOverLeft] -- add your slider handling code here..
        ourProcessor->setCrossOverFrequency(crossOverLeft->getValue(), true);
        //[/UserSliderCode_crossOverLeft]
    }
    else if (sliderThatWasMoved == crossOverRight)
    {
        //[UserSliderCode_crossOverRight] -- add your slider handling code here..
        ourProcessor->setCrossOverFrequency(crossOverRight->getValue(), true);
        //[/UserSliderCode_crossOverRight]
    }
    else if (sliderThatWasMoved == leftBypassGain)
    {
        //[UserSliderCode_leftBypassGain] -- add your slider handling code here..
        float gain = leftBypassGain->getValue();
        gain = powf(10.0, gain/20.0);
        ourProcessor->setBypassGains(gain, true);
        //[/UserSliderCode_leftBypassGain]
    }
    else if (sliderThatWasMoved == rightBypassGain)
    {
        //[UserSliderCode_rightBypassGain] -- add your slider handling code here..
        float gain = rightBypassGain->getValue();
        gain = powf(10.0, gain/20.0);
        ourProcessor->setBypassGains(gain, false);
        //[/UserSliderCode_rightBypassGain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PingPongDistortionAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    PingPongDistortionAudioProcessor* ourProcessor = getProcessor();
    buttonThatWasClicked->setToggleState(!buttonThatWasClicked->getToggleState(), dontSendNotification);
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == leftBypassMute)
    {
        //[UserButtonCode_leftBypassMute] -- add your button handler code here..
        ourProcessor->setBypassMuteState(leftBypassMute->getToggleState(), true);
        //[/UserButtonCode_leftBypassMute]
    }
    else if (buttonThatWasClicked == rightBypassMute)
    {
        //[UserButtonCode_rightBypassMute] -- add your button handler code here..
        ourProcessor->setBypassMuteState(rightBypassMute->getToggleState(), false);
        //[/UserButtonCode_rightBypassMute]
    }
    else if (buttonThatWasClicked == leftDelayFeedMute)
    {
        //[UserButtonCode_leftDelayFeedMute] -- add your button handler code here..
        ourProcessor->setDelayMuteState(leftDelayFeedMute->getToggleState(), true);
        //[/UserButtonCode_leftDelayFeedMute]
    }
    else if (buttonThatWasClicked == rightDelayFeedMute)
    {
        //[UserButtonCode_rightDelayFeedMute] -- add your button handler code here..
        ourProcessor->setDelayMuteState(rightDelayFeedMute->getToggleState(), false);
        //[/UserButtonCode_rightDelayFeedMute]
    }
    else if (buttonThatWasClicked == rightCrossOverToggle)
    {
        //[UserButtonCode_rightCrossOverToggle] -- add your button handler code here..
        ourProcessor->setCrossOverState(rightCrossOverToggle->getToggleState(), false);
        //[/UserButtonCode_rightCrossOverToggle]
    }
    else if (buttonThatWasClicked == leftCrossOverToggle)
    {
        //[UserButtonCode_leftCrossOverToggle] -- add your button handler code here..
        ourProcessor->setCrossOverState(leftCrossOverToggle->getToggleState(), true);
        //[/UserButtonCode_leftCrossOverToggle]
    }

    //[UserbuttonClicked_Post]
    
    //[/UserbuttonClicked_Post]
}

void PingPongDistortionAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    PingPongDistortionAudioProcessor* ourProcessor = getProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == leftDistortionMode)
    {
        //[UserComboBoxCode_leftDistortionMode] -- add your combo box handling code here..
        ourProcessor->setDistortionMode(leftDistortionMode->getSelectedId()-1, true);
        //[/UserComboBoxCode_leftDistortionMode]
    }
    else if (comboBoxThatHasChanged == righttDistortionMode)
    {
        //[UserComboBoxCode_righttDistortionMode] -- add your combo box handling code here..
        ourProcessor->setDistortionMode(righttDistortionMode->getSelectedId()-1, false);
        //[/UserComboBoxCode_righttDistortionMode]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PingPongDistortionAudioProcessorEditor::timerCallback() {
    PingPongDistortionAudioProcessor* ourProcessor = getProcessor();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PingPongDistortionAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PingPongDistortionAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="800" initialHeight="500">
  <BACKGROUND backgroundColour="ff383838">
    <ROUNDRECT pos="198 395 100 98" cornerSize="10" fill="solid: ff383838" hasStroke="1"
               stroke="5, mitered, butt" strokeColour="solid: ff90a52a"/>
    <ROUNDRECT pos="198 3 100 98" cornerSize="10" fill="solid: ff383838" hasStroke="1"
               stroke="5, mitered, butt" strokeColour="solid: ff90a52a"/>
    <PATH pos="0 0 100 100" fill="solid: ff5e2aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 184 32 l 736 32 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff2aa597" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 752 480 l 184 480 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff3a2aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 328 144 l 328 424 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff592aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 752 144 l 328 144 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff712aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 384 88 l 384 360 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff2aa557" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 728 360 l 384 360 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff942aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 232 424 l 792 424 l 140 424 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff36a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 240 88 l 792 88 l 140 88 x</PATH>
    <TEXT pos="4 70 60 30" fill="solid: ffffffff" hasStroke="0" text="Left In"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="4 406 60 30" fill="solid: ffffffff" hasStroke="0" text="Right In"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <ELLIPSE pos="76 54 64 64" fill="solid: ff2a74a5" hasStroke="0"/>
    <ELLIPSE pos="76 390 64 64" fill="solid: ff2a74a5" hasStroke="0"/>
    <RECT pos="508 64 156 40" fill="solid: ff2aa1a5" hasStroke="0"/>
    <RECT pos="508 398 156 40" fill="solid: ff2aa1a5" hasStroke="0"/>
    <TEXT pos="508 70 156 30" fill="solid: ff000000" hasStroke="0" text="Delay"
          fontname="Default font" fontsize="10.5" bold="0" italic="1" justification="36"/>
    <TEXT pos="508 406 156 30" fill="solid: ff000000" hasStroke="0" text="Delay"
          fontname="Default font" fontsize="10.5" bold="0" italic="1" justification="36"/>
    <ELLIPSE pos="516 334 56 54" fill="solid: ff2a72a5" hasStroke="0"/>
    <ROUNDRECT pos="604 334 60 56" cornerSize="10" fill="solid: ffa52a7b" hasStroke="0"/>
    <ELLIPSE pos="516 110 56 54" fill="solid: ff2a72a5" hasStroke="0"/>
    <ROUNDRECT pos="604 110 60 56" cornerSize="10" fill="solid: ffa52a7b" hasStroke="0"/>
    <TEXT pos="84 366 44 30" fill="solid: ffb3b3b3" hasStroke="0" text="Gain"
          fontname="Default font" fontsize="9.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="84 30 44 30" fill="solid: ffb3b3b3" hasStroke="0" text="Gain"
          fontname="Default font" fontsize="9.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="516 168 56 24" fill="solid: ffebebeb" hasStroke="0" text="Low Pass"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="600 168 64 24" fill="solid: ffebebeb" hasStroke="0" text="Distortion Gain"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="500 382 32 16" fill="solid: ffffffff" hasStroke="0" text="250Hz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="500 158 32 16" fill="solid: ffffffff" hasStroke="0" text="250Hz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="548 382 32 16" fill="solid: ffffffff" hasStroke="0" text="5kHz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="548 158 32 16" fill="solid: ffffffff" hasStroke="0" text="5kHz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="588 382 32 16" fill="solid: ffffffff" hasStroke="0" text="0dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="588 158 32 16" fill="solid: ffffffff" hasStroke="0" text="0dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="644 158 32 16" fill="solid: ffffffff" hasStroke="0" text="20dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="644 382 32 16" fill="solid: ffffffff" hasStroke="0" text="20dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="68 110 32 16" fill="solid: ffffffff" hasStroke="0" text="-24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="116 110 32 16" fill="solid: ffffffff" hasStroke="0" text="+24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="68 446 32 16" fill="solid: ffffffff" hasStroke="0" text="-24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="116 446 32 16" fill="solid: ffffffff" hasStroke="0" text="+24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <ELLIPSE pos="308 406 36 34" fill="solid: ffa52a58" hasStroke="0"/>
    <ELLIPSE pos="364 70 36 34" fill="solid: ffa52a58" hasStroke="0"/>
    <TEXT pos="516 312 56 24" fill="solid: ffebebeb" hasStroke="0" text="Low Pass"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="600 312 64 24" fill="solid: ffebebeb" hasStroke="0" text="Distortion Gain"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <PATH pos="0 0 100 100" fill="solid: ffa55e2a" hasStroke="0" nonZeroWinding="1">s 386 230 l 416 280 l 356 280 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ffa55e2a" hasStroke="0" nonZeroWinding="1">s 330 272 l 360 224 l 300 224 x</PATH>
    <TEXT pos="330 198 68 24" fill="solid: ffebebeb" hasStroke="0" text="Crossfeed Gains"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="292 262 32 16" fill="solid: ffffffff" hasStroke="0" text="-12dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="396 278 32 16" fill="solid: ffffffff" hasStroke="0" text="0dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <PATH pos="0 0 100 100" fill="solid: ffa5672a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 728 360 l 728 424 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff2a9ba5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 752 88 l 752 144 x</PATH>
    <TEXT pos="500 46 32 16" fill="solid: ffffffff" hasStroke="0" text="100ms"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="636 46 32 16" fill="solid: ffffffff" hasStroke="0" text="1000ms"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="500 438 32 16" fill="solid: ffffffff" hasStroke="0" text="100ms"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="636 438 32 16" fill="solid: ffffffff" hasStroke="0" text="1000ms"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="332 262 32 16" fill="solid: ffffffff" hasStroke="0" text="0dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="348 278 32 16" fill="solid: ffffffff" hasStroke="0" text="-12dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <PATH pos="0 0 100 100" fill="solid: ff2a6ba5" hasStroke="0" nonZeroWinding="1">s 394 6 l 450 32 l 394 54 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff2a6ba5" hasStroke="0" nonZeroWinding="1">s 378 446 l 437 476 l 378 502 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff5e2aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 184 448 l 184 480 l 184 424 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ffa52a78" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff2a96a5" nonZeroWinding="1">s 752 424 l 752 480 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff5e2aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 184 32 l 184 88 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff5e2aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffa5962a" nonZeroWinding="1">s 736 88 l 736 32 x</PATH>
    <TEXT pos="200 4 96 24" fill="solid: ffebebeb" hasStroke="0" text="Crossover"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="200 396 96 24" fill="solid: ffebebeb" hasStroke="0" text="Crossover"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <PATH pos="0 0 100 100" fill="solid: ffa52a9c" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff962aa5" nonZeroWinding="1">s 768 88 l 768 424 x</PATH>
    <TEXT pos="387 44 68 24" fill="solid: ffebebeb" hasStroke="0" text="Bypass Gain"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="371 428 68 24" fill="solid: ffebebeb" hasStroke="0" text="Bypass Gain"
          fontname="Default font" fontsize="9.5999999999999996447" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="371 44 32 16" fill="solid: ffffffff" hasStroke="0" text="-24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="355 484 32 16" fill="solid: ffffffff" hasStroke="0" text="-24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="435 44 32 16" fill="solid: ffffffff" hasStroke="0" text="+24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="419 484 32 16" fill="solid: ffffffff" hasStroke="0" text="+24dB"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="203 68 32 16" fill="solid: ffffffff" hasStroke="0" text="500Hz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="203 460 32 16" fill="solid: ffffffff" hasStroke="0" text="500Hz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="259 68 32 16" fill="solid: ffffffff" hasStroke="0" text="5kHz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="259 460 32 16" fill="solid: ffffffff" hasStroke="0" text="5kHz"
          fontname="Default font" fontsize="6.9000000000000003553" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="c451de938eb9ffb1" memberName="leftGain"
          virtualName="" explicitFocusOrder="0" pos="76 54 64 64" min="-24"
          max="24" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="a25d6bae70dc101d" memberName="rightGain"
          virtualName="" explicitFocusOrder="0" pos="76 390 64 64" min="-24"
          max="24" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="cfa5a9eaef59fb9f" memberName="rightDelay"
          virtualName="" explicitFocusOrder="0" pos="512 400 152 64" textboxtext="ffffffff"
          textboxbkgd="ff000000" min="100" max="1000" int="1" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="a1ef174b6477908a" memberName="leftDelay"
          virtualName="" explicitFocusOrder="0" pos="512 40 152 64" textboxtext="ffffffff"
          textboxbkgd="ff000000" min="100" max="1000" int="1" style="LinearHorizontal"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="af6333ad53c87c68" memberName="rightLP"
          virtualName="" explicitFocusOrder="0" pos="520 336 48 48" min="250"
          max="5000" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="a555c5210e43f990" memberName="leftLP" virtualName=""
          explicitFocusOrder="0" pos="520 112 48 48" min="250" max="5000"
          int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="39b127d44605abc0" memberName="rightDistGain"
          virtualName="" explicitFocusOrder="0" pos="608 336 56 56" thumbcol="ffffbbce"
          rotarysliderfill="7fff0046" min="1" max="10" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e4796593493775a" memberName="rightDistGain2"
          virtualName="" explicitFocusOrder="0" pos="608 112 56 56" thumbcol="ffffbbce"
          rotarysliderfill="7fff0046" min="1" max="10" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="c8e738ec876c4247" memberName="feedCrossRight"
          virtualName="" explicitFocusOrder="0" pos="360 232 56 56" thumbcol="fffffbbb"
          rotarysliderfill="7fffbf00" min="-12" max="0" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="2ea4e3fb86f58bcf" memberName="feedCrossLeft"
          virtualName="" explicitFocusOrder="0" pos="304 216 56 56" thumbcol="fffffbbb"
          rotarysliderfill="7fffbf00" min="-12" max="0" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Left Cross Over" id="1fea699ffbf18c3d" memberName="crossOverLeft"
          virtualName="" explicitFocusOrder="0" pos="200 40 96 40" min="500"
          max="5000" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Right Cross Over" id="d3c6162217609135" memberName="crossOverRight"
          virtualName="" explicitFocusOrder="0" pos="200 432 96 40" min="500"
          max="5000" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="768d3131568d19e3" memberName="leftBypassGain"
          virtualName="" explicitFocusOrder="0" pos="392 0 56 56" thumbcol="fffffbbb"
          rotarysliderfill="7fffbf00" min="-24" max="24" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d82db036b42385f7" memberName="rightBypassGain"
          virtualName="" explicitFocusOrder="0" pos="376 448 56 56" thumbcol="fffffbbb"
          rotarysliderfill="7fffbf00" min="-24" max="24" int="0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="b88b5405805cd682" memberName="leftBypassMute"
              virtualName="" explicitFocusOrder="0" pos="320 24 48 16" buttonText="mute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3646a71903ce6f3f" memberName="rightBypassMute"
              virtualName="" explicitFocusOrder="0" pos="320 472 48 16" buttonText="mute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ddf797efebff1778" memberName="leftDelayFeedMute"
              virtualName="" explicitFocusOrder="0" pos="456 80 48 16" buttonText="mute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d9cb93fad3eebfca" memberName="rightDelayFeedMute"
              virtualName="" explicitFocusOrder="0" pos="456 416 48 16" buttonText="mute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="9a01beb45d7c77c3" memberName="rightCrossOverToggle"
              virtualName="" explicitFocusOrder="0" pos="192 392 24 16" buttonText="off"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6bfd73cb035c9b3e" memberName="leftCrossOverToggle"
              virtualName="" explicitFocusOrder="0" pos="192 0 24 16" buttonText="off"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="994a440eb0c1f977" memberName="leftDistortionMode"
            virtualName="" explicitFocusOrder="0" pos="584 192 128 24" editable="0"
            layout="33" items="Soft (exponential)&#10;Soft (sine)&#10;Hard&#10;Half Wave Rect&#10;Full Wave Rect"
            textWhenNonSelected="Distortion Mode" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="88f5cac01496108d" memberName="righttDistortionMode"
            virtualName="" explicitFocusOrder="0" pos="584 288 128 24" editable="0"
            layout="33" items="Soft (exponential)&#10;Soft (sine)&#10;Hard&#10;Half Wave Rect&#10;Full Wave Rect"
            textWhenNonSelected="Distortion Mode" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
