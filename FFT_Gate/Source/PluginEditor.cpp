/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

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
Fft_gateAudioProcessorEditor::Fft_gateAudioProcessorEditor (Fft_gateAudioProcessor* ownerFilter) : AudioProcessorEditor (ownerFilter)
{
    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Det.")));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("Act.")));

    addAndMakeVisible (maxFreq = new TextEditor ("new text editor"));
    maxFreq->setMultiLine (false);
    maxFreq->setReturnKeyStartsNewLine (false);
    maxFreq->setReadOnly (false);
    maxFreq->setScrollbarsShown (true);
    maxFreq->setCaretVisible (true);
    maxFreq->setPopupMenuEnabled (true);
    maxFreq->setText (String::empty);

    addAndMakeVisible (meandB = new TextEditor ("new text editor"));
    meandB->setMultiLine (false);
    meandB->setReturnKeyStartsNewLine (false);
    meandB->setReadOnly (false);
    meandB->setScrollbarsShown (true);
    meandB->setCaretVisible (true);
    meandB->setPopupMenuEnabled (true);
    meandB->setText (String::empty);

    addAndMakeVisible (ThreshSlide = new Slider ("new slider"));
    ThreshSlide->setRange (-90, 0, 0.5);
    ThreshSlide->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    ThreshSlide->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    ThreshSlide->addListener (this);

    addAndMakeVisible (CutLimit = new Slider ("new slider"));
    CutLimit->setRange (-36, 0, 3);
    CutLimit->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    CutLimit->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    CutLimit->addListener (this);

    addAndMakeVisible (BoostLimit = new Slider ("new slider"));
    BoostLimit->setRange (0, 36, 3);
    BoostLimit->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    BoostLimit->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    BoostLimit->addListener (this);

    addAndMakeVisible (bandSlide = new Slider ("new slider"));
    bandSlide->setRange (0, 10, 0);
    bandSlide->setSliderStyle (Slider::LinearVertical);
    bandSlide->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide->addListener (this);

    addAndMakeVisible (bandSlide2 = new Slider ("new slider"));
    bandSlide2->setRange (0, 10, 0);
    bandSlide2->setSliderStyle (Slider::LinearVertical);
    bandSlide2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide2->addListener (this);

    addAndMakeVisible (bandSlide3 = new Slider ("new slider"));
    bandSlide3->setRange (0, 10, 0);
    bandSlide3->setSliderStyle (Slider::LinearVertical);
    bandSlide3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide3->addListener (this);

    addAndMakeVisible (bandSlide4 = new Slider ("new slider"));
    bandSlide4->setRange (0, 10, 0);
    bandSlide4->setSliderStyle (Slider::LinearVertical);
    bandSlide4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide4->addListener (this);

    addAndMakeVisible (bandSlide5 = new Slider ("new slider"));
    bandSlide5->setRange (0, 10, 0);
    bandSlide5->setSliderStyle (Slider::LinearVertical);
    bandSlide5->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide5->addListener (this);

    addAndMakeVisible (bandSlide6 = new Slider ("new slider"));
    bandSlide6->setRange (0, 10, 0);
    bandSlide6->setSliderStyle (Slider::LinearVertical);
    bandSlide6->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide6->addListener (this);

    addAndMakeVisible (bandSlide7 = new Slider ("new slider"));
    bandSlide7->setRange (0, 10, 0);
    bandSlide7->setSliderStyle (Slider::LinearVertical);
    bandSlide7->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide7->addListener (this);

    addAndMakeVisible (bandSlide8 = new Slider ("new slider"));
    bandSlide8->setRange (0, 10, 0);
    bandSlide8->setSliderStyle (Slider::LinearVertical);
    bandSlide8->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide8->addListener (this);

    addAndMakeVisible (bandSlide9 = new Slider ("new slider"));
    bandSlide9->setRange (0, 10, 0);
    bandSlide9->setSliderStyle (Slider::LinearVertical);
    bandSlide9->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide9->addListener (this);

    addAndMakeVisible (bandSlide10 = new Slider ("new slider"));
    bandSlide10->setRange (0, 10, 0);
    bandSlide10->setSliderStyle (Slider::LinearVertical);
    bandSlide10->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandSlide10->addListener (this);

    addAndMakeVisible (bandMean = new Slider ("new slider"));
    bandMean->setRange (0, 10, 0);
    bandMean->setSliderStyle (Slider::LinearVertical);
    bandMean->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandMean->addListener (this);

    addAndMakeVisible (bandDiff = new Slider ("new slider"));
    bandDiff->setRange (-12, 12, 0);
    bandDiff->setSliderStyle (Slider::LinearVertical);
    bandDiff->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    bandDiff->addListener (this);

    addAndMakeVisible (detectToggle = new ToggleButton ("new toggle button"));
    detectToggle->setButtonText (String::empty);
    detectToggle->addListener (this);
    detectToggle->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle2 = new ToggleButton ("new toggle button"));
    detectToggle2->setButtonText (String::empty);
    detectToggle2->addListener (this);
    detectToggle2->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle3 = new ToggleButton ("new toggle button"));
    detectToggle3->setButtonText (String::empty);
    detectToggle3->addListener (this);
    detectToggle3->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle4 = new ToggleButton ("new toggle button"));
    detectToggle4->setButtonText (String::empty);
    detectToggle4->addListener (this);
    detectToggle4->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle5 = new ToggleButton ("new toggle button"));
    detectToggle5->setButtonText (String::empty);
    detectToggle5->addListener (this);
    detectToggle5->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle6 = new ToggleButton ("new toggle button"));
    detectToggle6->setButtonText (String::empty);
    detectToggle6->addListener (this);
    detectToggle6->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle7 = new ToggleButton ("new toggle button"));
    detectToggle7->setButtonText (String::empty);
    detectToggle7->addListener (this);
    detectToggle7->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle8 = new ToggleButton ("new toggle button"));
    detectToggle8->setButtonText (String::empty);
    detectToggle8->addListener (this);
    detectToggle8->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle9 = new ToggleButton ("new toggle button"));
    detectToggle9->setButtonText (String::empty);
    detectToggle9->addListener (this);
    detectToggle9->setToggleState (true, dontSendNotification);

    addAndMakeVisible (detectToggle10 = new ToggleButton ("new toggle button"));
    detectToggle10->setButtonText (String::empty);
    detectToggle10->addListener (this);
    detectToggle10->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle = new ToggleButton ("new toggle button"));
    actToggle->setButtonText (String::empty);
    actToggle->addListener (this);
    actToggle->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle2 = new ToggleButton ("new toggle button"));
    actToggle2->setButtonText (String::empty);
    actToggle2->addListener (this);
    actToggle2->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle3 = new ToggleButton ("new toggle button"));
    actToggle3->setButtonText (String::empty);
    actToggle3->addListener (this);
    actToggle3->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle4 = new ToggleButton ("new toggle button"));
    actToggle4->setButtonText (String::empty);
    actToggle4->addListener (this);
    actToggle4->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle5 = new ToggleButton ("new toggle button"));
    actToggle5->setButtonText (String::empty);
    actToggle5->addListener (this);
    actToggle5->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle6 = new ToggleButton ("new toggle button"));
    actToggle6->setButtonText (String::empty);
    actToggle6->addListener (this);
    actToggle6->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle7 = new ToggleButton ("new toggle button"));
    actToggle7->setButtonText (String::empty);
    actToggle7->addListener (this);
    actToggle7->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle8 = new ToggleButton ("new toggle button"));
    actToggle8->setButtonText (String::empty);
    actToggle8->addListener (this);
    actToggle8->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle9 = new ToggleButton ("new toggle button"));
    actToggle9->setButtonText (String::empty);
    actToggle9->addListener (this);
    actToggle9->setToggleState (true, dontSendNotification);

    addAndMakeVisible (actToggle10 = new ToggleButton ("new toggle button"));
    actToggle10->setButtonText (String::empty);
    actToggle10->addListener (this);
    actToggle10->setToggleState (true, dontSendNotification);

    addAndMakeVisible (Mode = new TextButton ("new button"));
    Mode->setButtonText (TRANS("Magnitude"));
    Mode->addListener (this);

    addAndMakeVisible (Attack = new Slider ("new slider"));
    Attack->setRange (5, 200, 0.1);
    Attack->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Attack->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    Attack->addListener (this);

    addAndMakeVisible (Release = new Slider ("new slider"));
    Release->setRange (50, 1000, 0.5);
    Release->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Release->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    Release->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (624, 424);


    //[Constructor] You can add your own custom stuff here..
    startTimer(50);
    locCutLim = 0.0;
    locBoostLim = 0.0;
    modeIndex = 0;
    setSliderRange();
    //[/Constructor]
}

Fft_gateAudioProcessorEditor::~Fft_gateAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    groupComponent2 = nullptr;
    maxFreq = nullptr;
    meandB = nullptr;
    ThreshSlide = nullptr;
    CutLimit = nullptr;
    BoostLimit = nullptr;
    bandSlide = nullptr;
    bandSlide2 = nullptr;
    bandSlide3 = nullptr;
    bandSlide4 = nullptr;
    bandSlide5 = nullptr;
    bandSlide6 = nullptr;
    bandSlide7 = nullptr;
    bandSlide8 = nullptr;
    bandSlide9 = nullptr;
    bandSlide10 = nullptr;
    bandMean = nullptr;
    bandDiff = nullptr;
    detectToggle = nullptr;
    detectToggle2 = nullptr;
    detectToggle3 = nullptr;
    detectToggle4 = nullptr;
    detectToggle5 = nullptr;
    detectToggle6 = nullptr;
    detectToggle7 = nullptr;
    detectToggle8 = nullptr;
    detectToggle9 = nullptr;
    detectToggle10 = nullptr;
    actToggle = nullptr;
    actToggle2 = nullptr;
    actToggle3 = nullptr;
    actToggle4 = nullptr;
    actToggle5 = nullptr;
    actToggle6 = nullptr;
    actToggle7 = nullptr;
    actToggle8 = nullptr;
    actToggle9 = nullptr;
    actToggle10 = nullptr;
    Mode = nullptr;
    Attack = nullptr;
    Release = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Fft_gateAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xff82a1cb));
    g.fillRect (20, 20, 604, 404);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Max Frequency"),
                28, 36, 116, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Mean dB"),
                316, 36, 116, 30,
                Justification::centred, true);

    g.setColour (Colour (0xfff4f4f4));
    g.fillRect (36, 192, 572, 216);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Threshold"),
                156, 160, 68, 26,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Cut Limit"),
                244, 160, 116, 26,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Boost Limit"),
                356, 160, 116, 28,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("0-60"),
                84, 196, 28, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("60-120"),
                124, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("120-250"),
                164, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("250-500"),
                204, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("500-1k"),
                244, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("1k-2k"),
                284, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("2k-4k"),
                324, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("4k-8k"),
                364, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("8k-16k"),
                404, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("16k-20k"),
                444, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("Mean"),
                484, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (8.20f, Font::plain));
    g.drawText (TRANS("dB Change"),
                524, 196, 36, 10,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (11.80f, Font::plain));
    g.drawText (TRANS("Attack"),
                468, 68, 68, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (11.80f, Font::plain));
    g.drawText (TRANS("Release"),
                468, 124, 68, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Fft_gateAudioProcessorEditor::resized()
{
    groupComponent->setBounds (40, 344, 440, 32);
    groupComponent2->setBounds (40, 376, 440, 32);
    maxFreq->setBounds (144, 40, 150, 24);
    meandB->setBounds (416, 40, 150, 24);
    ThreshSlide->setBounds (144, 72, 96, 88);
    CutLimit->setBounds (256, 72, 88, 88);
    BoostLimit->setBounds (368, 72, 88, 88);
    bandSlide->setBounds (88, 200, 23, 152);
    bandSlide2->setBounds (128, 200, 23, 152);
    bandSlide3->setBounds (168, 200, 23, 152);
    bandSlide4->setBounds (208, 200, 23, 152);
    bandSlide5->setBounds (248, 200, 23, 152);
    bandSlide6->setBounds (288, 200, 23, 152);
    bandSlide7->setBounds (328, 200, 23, 152);
    bandSlide8->setBounds (368, 200, 23, 152);
    bandSlide9->setBounds (408, 200, 23, 152);
    bandSlide10->setBounds (448, 200, 23, 152);
    bandMean->setBounds (488, 200, 23, 152);
    bandDiff->setBounds (528, 200, 23, 152);
    detectToggle->setBounds (88, 352, 32, 24);
    detectToggle2->setBounds (128, 352, 32, 24);
    detectToggle3->setBounds (168, 352, 32, 24);
    detectToggle4->setBounds (208, 352, 32, 24);
    detectToggle5->setBounds (248, 352, 32, 24);
    detectToggle6->setBounds (288, 352, 32, 24);
    detectToggle7->setBounds (328, 352, 32, 24);
    detectToggle8->setBounds (368, 352, 32, 24);
    detectToggle9->setBounds (408, 352, 32, 24);
    detectToggle10->setBounds (448, 352, 32, 24);
    actToggle->setBounds (88, 384, 31, 24);
    actToggle2->setBounds (128, 384, 31, 24);
    actToggle3->setBounds (168, 384, 31, 24);
    actToggle4->setBounds (208, 384, 31, 24);
    actToggle5->setBounds (248, 384, 31, 24);
    actToggle6->setBounds (288, 384, 31, 24);
    actToggle7->setBounds (328, 384, 31, 24);
    actToggle8->setBounds (368, 384, 31, 24);
    actToggle9->setBounds (408, 384, 31, 24);
    actToggle10->setBounds (448, 384, 31, 24);
    Mode->setBounds (496, 360, 104, 40);
    Attack->setBounds (464, 72, 150, 56);
    Release->setBounds (464, 128, 150, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Fft_gateAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    float val = 0.0;
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == ThreshSlide)
    {
        //[UserSliderCode_ThreshSlide] -- add your slider handling code here..
        val = ThreshSlide->getValue();
        getProcessor()->setThreshold(val);
        //[/UserSliderCode_ThreshSlide]
    }
    else if (sliderThatWasMoved == CutLimit)
    {
        //[UserSliderCode_CutLimit] -- add your slider handling code here..
        val = CutLimit->getValue();
        getProcessor()->setCutLimit(val);
        //[/UserSliderCode_CutLimit]
    }
    else if (sliderThatWasMoved == BoostLimit)
    {
        //[UserSliderCode_BoostLimit] -- add your slider handling code here..
        val = BoostLimit->getValue();
        getProcessor()->setBoostLimit(val);
        //[/UserSliderCode_BoostLimit]
    }
    else if (sliderThatWasMoved == bandSlide)
    {
        //[UserSliderCode_bandSlide] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide]
    }
    else if (sliderThatWasMoved == bandSlide2)
    {
        //[UserSliderCode_bandSlide2] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide2]
    }
    else if (sliderThatWasMoved == bandSlide3)
    {
        //[UserSliderCode_bandSlide3] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide3]
    }
    else if (sliderThatWasMoved == bandSlide4)
    {
        //[UserSliderCode_bandSlide4] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide4]
    }
    else if (sliderThatWasMoved == bandSlide5)
    {
        //[UserSliderCode_bandSlide5] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide5]
    }
    else if (sliderThatWasMoved == bandSlide6)
    {
        //[UserSliderCode_bandSlide6] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide6]
    }
    else if (sliderThatWasMoved == bandSlide7)
    {
        //[UserSliderCode_bandSlide7] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide7]
    }
    else if (sliderThatWasMoved == bandSlide8)
    {
        //[UserSliderCode_bandSlide8] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide8]
    }
    else if (sliderThatWasMoved == bandSlide9)
    {
        //[UserSliderCode_bandSlide9] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide9]
    }
    else if (sliderThatWasMoved == bandSlide10)
    {
        //[UserSliderCode_bandSlide10] -- add your slider handling code here..
        //[/UserSliderCode_bandSlide10]
    }
    else if (sliderThatWasMoved == bandMean)
    {
        //[UserSliderCode_bandMean] -- add your slider handling code here..
        //[/UserSliderCode_bandMean]
    }
    else if (sliderThatWasMoved == bandDiff)
    {
        //[UserSliderCode_bandDiff] -- add your slider handling code here..
        //[/UserSliderCode_bandDiff]
    }
    else if (sliderThatWasMoved == Attack)
    {
        //[UserSliderCode_Attack] -- add your slider handling code here..
        getProcessor()->setAttack(getProcessor()->setTau(Attack->getValue()/1000.0));
        //[/UserSliderCode_Attack]
    }
    else if (sliderThatWasMoved == Release)
    {
        //[UserSliderCode_Release] -- add your slider handling code here..
        getProcessor()->setRelease(getProcessor()->setTau(Release->getValue()/1000.0));
        //[/UserSliderCode_Release]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Fft_gateAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == detectToggle)
    {
        //[UserButtonCode_detectToggle] -- add your button handler code here..
        getProcessor()->setDetect(0, detectToggle->getToggleState());
        //[/UserButtonCode_detectToggle]
    }
    else if (buttonThatWasClicked == detectToggle2)
    {
        //[UserButtonCode_detectToggle2] -- add your button handler code here..
        getProcessor()->setDetect(1, detectToggle2->getToggleState());
        //[/UserButtonCode_detectToggle2]
    }
    else if (buttonThatWasClicked == detectToggle3)
    {
        //[UserButtonCode_detectToggle3] -- add your button handler code here..
        getProcessor()->setDetect(2, detectToggle3->getToggleState());
        //[/UserButtonCode_detectToggle3]
    }
    else if (buttonThatWasClicked == detectToggle4)
    {
        //[UserButtonCode_detectToggle4] -- add your button handler code here..
        getProcessor()->setDetect(3, detectToggle4->getToggleState());
        //[/UserButtonCode_detectToggle4]
    }
    else if (buttonThatWasClicked == detectToggle5)
    {
        //[UserButtonCode_detectToggle5] -- add your button handler code here..
        getProcessor()->setDetect(4, detectToggle5->getToggleState());
        //[/UserButtonCode_detectToggle5]
    }
    else if (buttonThatWasClicked == detectToggle6)
    {
        //[UserButtonCode_detectToggle6] -- add your button handler code here..
        getProcessor()->setDetect(5, detectToggle6->getToggleState());
        //[/UserButtonCode_detectToggle6]
    }
    else if (buttonThatWasClicked == detectToggle7)
    {
        //[UserButtonCode_detectToggle7] -- add your button handler code here..
        getProcessor()->setDetect(6, detectToggle7->getToggleState());
        //[/UserButtonCode_detectToggle7]
    }
    else if (buttonThatWasClicked == detectToggle8)
    {
        //[UserButtonCode_detectToggle8] -- add your button handler code here..
        getProcessor()->setDetect(7, detectToggle8->getToggleState());
        //[/UserButtonCode_detectToggle8]
    }
    else if (buttonThatWasClicked == detectToggle9)
    {
        //[UserButtonCode_detectToggle9] -- add your button handler code here..
        getProcessor()->setDetect(8, detectToggle9->getToggleState());
        //[/UserButtonCode_detectToggle9]
    }
    else if (buttonThatWasClicked == detectToggle10)
    {
        //[UserButtonCode_detectToggle10] -- add your button handler code here..
        getProcessor()->setAct(9, detectToggle10->getToggleState());
        //[/UserButtonCode_detectToggle10]
    }
    else if (buttonThatWasClicked == actToggle)
    {
        //[UserButtonCode_actToggle] -- add your button handler code here..
        getProcessor()->setAct(0, actToggle->getToggleState());
        //[/UserButtonCode_actToggle]
    }
    else if (buttonThatWasClicked == actToggle2)
    {
        //[UserButtonCode_actToggle2] -- add your button handler code here..
        getProcessor()->setAct(1, actToggle2->getToggleState());
        //[/UserButtonCode_actToggle2]
    }
    else if (buttonThatWasClicked == actToggle3)
    {
        //[UserButtonCode_actToggle3] -- add your button handler code here..
        getProcessor()->setAct(2, actToggle3->getToggleState());
        //[/UserButtonCode_actToggle3]
    }
    else if (buttonThatWasClicked == actToggle4)
    {
        //[UserButtonCode_actToggle4] -- add your button handler code here..
        getProcessor()->setAct(3, actToggle4->getToggleState());
        //[/UserButtonCode_actToggle4]
    }
    else if (buttonThatWasClicked == actToggle5)
    {
        //[UserButtonCode_actToggle5] -- add your button handler code here..
        getProcessor()->setAct(4, actToggle5->getToggleState());
        //[/UserButtonCode_actToggle5]
    }
    else if (buttonThatWasClicked == actToggle6)
    {
        //[UserButtonCode_actToggle6] -- add your button handler code here..
        getProcessor()->setAct(5, actToggle6->getToggleState());
        //[/UserButtonCode_actToggle6]
    }
    else if (buttonThatWasClicked == actToggle7)
    {
        //[UserButtonCode_actToggle7] -- add your button handler code here..
        getProcessor()->setAct(6, actToggle7->getToggleState());
        //[/UserButtonCode_actToggle7]
    }
    else if (buttonThatWasClicked == actToggle8)
    {
        //[UserButtonCode_actToggle8] -- add your button handler code here..
        getProcessor()->setAct(7, actToggle8->getToggleState());
        //[/UserButtonCode_actToggle8]
    }
    else if (buttonThatWasClicked == actToggle9)
    {
        //[UserButtonCode_actToggle9] -- add your button handler code here..
        getProcessor()->setAct(8, actToggle9->getToggleState());
        //[/UserButtonCode_actToggle9]
    }
    else if (buttonThatWasClicked == actToggle10)
    {
        //[UserButtonCode_actToggle10] -- add your button handler code here..
        getProcessor()->setAct(9, actToggle10->getToggleState());
        //[/UserButtonCode_actToggle10]
    }
    else if (buttonThatWasClicked == Mode)
    {
        //[UserButtonCode_Mode] -- add your button handler code here..
        modeIndex++;
        if (modeIndex >= 2)
            modeIndex = 0;
        if (modeIndex == 0)
            Mode->setButtonText(TRANS("Magnitude"));
        else if (modeIndex == 1)
            Mode->setButtonText(TRANS("Gain"));
        setSliderRange();
        //[/UserButtonCode_Mode]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Fft_gateAudioProcessorEditor::timerCallback()
{

    int N = getProcessor()->N;
    maxFreq->setText(String(getProcessor()->freqMaxIndex),2);

    float dB = 0.0;
    for (int k=0; k<N/2+1; k++) {
        if (getProcessor()->freqMag[k] < std::numeric_limits<float>::infinity( ) && getProcessor()->freqMag[k] > -std::numeric_limits<float>::infinity( ))
            dB += getProcessor()->freqMag[k]/((float)N/2.0+1.0);
    }
    meandB->setText(String(dB),2);
    bandDiff->setValue(getProcessor()->dBDiff);
    if (locCutLim != getProcessor()->cutLim || locBoostLim != getProcessor()->boostLim)
        setSliderRange();
    if (modeIndex == 0) {
        bandSlide->setValue(getProcessor()->getBanddB(0));
        bandSlide2->setValue(getProcessor()->getBanddB(1));
        bandSlide3->setValue(getProcessor()->getBanddB(2));
        bandSlide4->setValue(getProcessor()->getBanddB(3));
        bandSlide5->setValue(getProcessor()->getBanddB(4));
        bandSlide6->setValue(getProcessor()->getBanddB(5));
        bandSlide7->setValue(getProcessor()->getBanddB(6));
        bandSlide8->setValue(getProcessor()->getBanddB(7));
        bandSlide9->setValue(getProcessor()->getBanddB(8));
        bandSlide10->setValue(getProcessor()->getBanddB(9));
        float temp = 0.0;
        for (int k=0; k<10; k++)
            temp += getProcessor()->getBanddB(k);
        bandMean->setValue(temp/10.0);
    } else if (modeIndex == 1) {
        bandSlide->setValue(getProcessor()->GBand[0]);
        bandSlide2->setValue(getProcessor()->GBand[1]);
        bandSlide3->setValue(getProcessor()->GBand[2]);
        bandSlide4->setValue(getProcessor()->GBand[3]);
        bandSlide5->setValue(getProcessor()->GBand[4]);
        bandSlide6->setValue(getProcessor()->GBand[5]);
        bandSlide7->setValue(getProcessor()->GBand[6]);
        bandSlide8->setValue(getProcessor()->GBand[7]);
        bandSlide9->setValue(getProcessor()->GBand[8]);
        bandSlide10->setValue(getProcessor()->GBand[9]);
        float temp = 0.0;
        for (int k=0; k<10; k++)
            temp += getProcessor()->GBand[k];
        bandMean->setValue(temp/10.0);
    }
    bandSlide->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide2->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide3->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide4->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide5->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide6->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide7->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide8->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide9->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    bandSlide10->setColour(Slider::ColourIds::thumbColourId, Colours::grey);
    int slider = getProcessor()->fftBinBand[getProcessor()->freqMaxIndex];
    switch (slider) {
        case 0:
            bandSlide->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 1:
            bandSlide2->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 2:
            bandSlide3->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 3:
            bandSlide4->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 4:
            bandSlide5->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 5:
            bandSlide6->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 6:
            bandSlide7->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 7:
            bandSlide8->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 8:
            bandSlide9->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        case 9:
            bandSlide10->setColour(Slider::ColourIds::thumbColourId, Colours::blue);
            break;
        default:
            break;
    }
}

void Fft_gateAudioProcessorEditor::setSliderRange()
{
    locCutLim = getProcessor()->cutLim;
    locBoostLim = getProcessor()->boostLim;
    int setMin, setMax;
    if (modeIndex == 0) {
        setMin = -90;
        setMax = 12;
    } else if (modeIndex == 1) {
        setMin = (int)20*log10f(locCutLim);
        setMax = (int)20*log10f(locBoostLim);
    }
    bandSlide->setRange(setMin, setMax);
    bandSlide2->setRange(setMin, setMax);
    bandSlide3->setRange(setMin, setMax);
    bandSlide4->setRange(setMin, setMax);
    bandSlide5->setRange(setMin, setMax);
    bandSlide6->setRange(setMin, setMax);
    bandSlide7->setRange(setMin, setMax);
    bandSlide8->setRange(setMin, setMax);
    bandSlide9->setRange(setMin, setMax);
    bandSlide10->setRange(setMin, setMax);
    bandMean->setRange(setMin, setMin);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Fft_gateAudioProcessorEditor"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="624" initialHeight="424">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="20 20 604 404" fill="solid: ff82a1cb" hasStroke="0"/>
    <TEXT pos="28 36 116 30" fill="solid: ff000000" hasStroke="0" text="Max Frequency"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="316 36 116 30" fill="solid: ff000000" hasStroke="0" text="Mean dB"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <RECT pos="36 192 572 216" fill="solid: fff4f4f4" hasStroke="0"/>
    <TEXT pos="156 160 68 26" fill="solid: ff000000" hasStroke="0" text="Threshold"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="244 160 116 26" fill="solid: ff000000" hasStroke="0" text="Cut Limit"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="356 160 116 28" fill="solid: ff000000" hasStroke="0" text="Boost Limit"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="84 196 28 10" fill="solid: ff000000" hasStroke="0" text="0-60"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="124 196 36 10" fill="solid: ff000000" hasStroke="0" text="60-120"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="164 196 36 10" fill="solid: ff000000" hasStroke="0" text="120-250"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="204 196 36 10" fill="solid: ff000000" hasStroke="0" text="250-500"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="244 196 36 10" fill="solid: ff000000" hasStroke="0" text="500-1k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="284 196 36 10" fill="solid: ff000000" hasStroke="0" text="1k-2k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="324 196 36 10" fill="solid: ff000000" hasStroke="0" text="2k-4k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="364 196 36 10" fill="solid: ff000000" hasStroke="0" text="4k-8k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="404 196 36 10" fill="solid: ff000000" hasStroke="0" text="8k-16k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="444 196 36 10" fill="solid: ff000000" hasStroke="0" text="16k-20k"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="484 196 36 10" fill="solid: ff000000" hasStroke="0" text="Mean"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="524 196 36 10" fill="solid: ff000000" hasStroke="0" text="dB Change"
          fontname="Default font" fontsize="8.1999999999999992895" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="468 68 68 30" fill="solid: ff000000" hasStroke="0" text="Attack"
          fontname="Default font" fontsize="11.800000000000000711" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="468 124 68 30" fill="solid: ff000000" hasStroke="0" text="Release"
          fontname="Default font" fontsize="11.800000000000000711" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="ea065853a5a3adff" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="40 344 440 32" title="Det."/>
  <GROUPCOMPONENT name="new group" id="53f58804e364b482" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="40 376 440 32" title="Act."/>
  <TEXTEDITOR name="new text editor" id="bd845eba953ca6b7" memberName="maxFreq"
              virtualName="" explicitFocusOrder="0" pos="144 40 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="58fb9d4502815190" memberName="meandB"
              virtualName="" explicitFocusOrder="0" pos="416 40 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="new slider" id="c8a35b44aa1a2594" memberName="ThreshSlide"
          virtualName="" explicitFocusOrder="0" pos="144 72 96 88" min="-90"
          max="0" int="0.5" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="90358e98cab6608d" memberName="CutLimit"
          virtualName="" explicitFocusOrder="0" pos="256 72 88 88" min="-36"
          max="-6" int="3" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="3d75330292252ad9" memberName="BoostLimit"
          virtualName="" explicitFocusOrder="0" pos="368 72 88 88" min="6"
          max="36" int="3" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="38b9789dc4a195df" memberName="bandSlide"
          virtualName="" explicitFocusOrder="0" pos="88 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="eff55a683f69b2d7" memberName="bandSlide2"
          virtualName="" explicitFocusOrder="0" pos="128 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="68c88038bde39c44" memberName="bandSlide3"
          virtualName="" explicitFocusOrder="0" pos="168 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="6f829b68728c851b" memberName="bandSlide4"
          virtualName="" explicitFocusOrder="0" pos="208 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="3cc5e8964804be09" memberName="bandSlide5"
          virtualName="" explicitFocusOrder="0" pos="248 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="b9bd5f147eec10ab" memberName="bandSlide6"
          virtualName="" explicitFocusOrder="0" pos="288 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="89fdb8576b9be76d" memberName="bandSlide7"
          virtualName="" explicitFocusOrder="0" pos="328 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="426a185907f8d5d8" memberName="bandSlide8"
          virtualName="" explicitFocusOrder="0" pos="368 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="278c26fd6d0733b0" memberName="bandSlide9"
          virtualName="" explicitFocusOrder="0" pos="408 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d6ff8f3f66448cad" memberName="bandSlide10"
          virtualName="" explicitFocusOrder="0" pos="448 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="7ad6d7dab92c479" memberName="bandMean"
          virtualName="" explicitFocusOrder="0" pos="488 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="9d73bfccaea8e5b5" memberName="bandDiff"
          virtualName="" explicitFocusOrder="0" pos="528 200 23 152" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="3ccce9b890b72417" memberName="detectToggle"
                virtualName="" explicitFocusOrder="0" pos="88 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="50e6e92dd6e902ba" memberName="detectToggle2"
                virtualName="" explicitFocusOrder="0" pos="128 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="964d78d46c1b8097" memberName="detectToggle3"
                virtualName="" explicitFocusOrder="0" pos="168 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="209ee103c0f8253" memberName="detectToggle4"
                virtualName="" explicitFocusOrder="0" pos="208 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="40d74e653a644989" memberName="detectToggle5"
                virtualName="" explicitFocusOrder="0" pos="248 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="9d9f30f644c445b6" memberName="detectToggle6"
                virtualName="" explicitFocusOrder="0" pos="288 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="9a81be0313c78649" memberName="detectToggle7"
                virtualName="" explicitFocusOrder="0" pos="328 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="835f92274115890b" memberName="detectToggle8"
                virtualName="" explicitFocusOrder="0" pos="368 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="e6e0f4ca991c178d" memberName="detectToggle9"
                virtualName="" explicitFocusOrder="0" pos="408 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="68b11f6aff790d68" memberName="detectToggle10"
                virtualName="" explicitFocusOrder="0" pos="448 352 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="966681fa411a7001" memberName="actToggle"
                virtualName="" explicitFocusOrder="0" pos="88 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="5e1bcb8775a9f0b" memberName="actToggle2"
                virtualName="" explicitFocusOrder="0" pos="128 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="8369a943a28638dd" memberName="actToggle3"
                virtualName="" explicitFocusOrder="0" pos="168 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="da0e116270188c59" memberName="actToggle4"
                virtualName="" explicitFocusOrder="0" pos="208 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="ce3c3becca13d3cb" memberName="actToggle5"
                virtualName="" explicitFocusOrder="0" pos="248 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="d5f7998108c296f5" memberName="actToggle6"
                virtualName="" explicitFocusOrder="0" pos="288 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="893d154497bdc749" memberName="actToggle7"
                virtualName="" explicitFocusOrder="0" pos="328 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="cc9a2d122b3ac344" memberName="actToggle8"
                virtualName="" explicitFocusOrder="0" pos="368 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="95fa0ed2da706d47" memberName="actToggle9"
                virtualName="" explicitFocusOrder="0" pos="408 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="9c1478a792fd9345" memberName="actToggle10"
                virtualName="" explicitFocusOrder="0" pos="448 384 31 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="new button" id="359dda12a4da4673" memberName="Mode" virtualName=""
              explicitFocusOrder="0" pos="496 360 104 40" buttonText="Magnitude"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="f44987255188232e" memberName="Attack" virtualName=""
          explicitFocusOrder="0" pos="464 72 150 56" min="5" max="200"
          int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="bb4a6fbcf463625a" memberName="Release"
          virtualName="" explicitFocusOrder="0" pos="464 128 150 56" min="50"
          max="1000" int="0.5" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
