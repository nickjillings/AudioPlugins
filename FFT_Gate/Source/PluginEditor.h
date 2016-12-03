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

#ifndef __JUCE_HEADER_9D9ABCAC92C77E9F__
#define __JUCE_HEADER_9D9ABCAC92C77E9F__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Fft_gateAudioProcessorEditor  : public AudioProcessorEditor,
                                      public Timer,
                                      public SliderListener,
                                      public ButtonListener
{
public:
    //==============================================================================
    Fft_gateAudioProcessorEditor (Fft_gateAudioProcessor* ownerFilter);
    ~Fft_gateAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    void setSliderRange();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Fft_gateAudioProcessor* getProcessor() const
    {
        return static_cast <Fft_gateAudioProcessor*> (getAudioProcessor());
    }

    float locCutLim, locBoostLim;
    int modeIndex;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<TextEditor> maxFreq;
    ScopedPointer<TextEditor> meandB;
    ScopedPointer<Slider> ThreshSlide;
    ScopedPointer<Slider> CutLimit;
    ScopedPointer<Slider> BoostLimit;
    ScopedPointer<Slider> bandSlide;
    ScopedPointer<Slider> bandSlide2;
    ScopedPointer<Slider> bandSlide3;
    ScopedPointer<Slider> bandSlide4;
    ScopedPointer<Slider> bandSlide5;
    ScopedPointer<Slider> bandSlide6;
    ScopedPointer<Slider> bandSlide7;
    ScopedPointer<Slider> bandSlide8;
    ScopedPointer<Slider> bandSlide9;
    ScopedPointer<Slider> bandSlide10;
    ScopedPointer<Slider> bandMean;
    ScopedPointer<Slider> bandDiff;
    ScopedPointer<ToggleButton> detectToggle;
    ScopedPointer<ToggleButton> detectToggle2;
    ScopedPointer<ToggleButton> detectToggle3;
    ScopedPointer<ToggleButton> detectToggle4;
    ScopedPointer<ToggleButton> detectToggle5;
    ScopedPointer<ToggleButton> detectToggle6;
    ScopedPointer<ToggleButton> detectToggle7;
    ScopedPointer<ToggleButton> detectToggle8;
    ScopedPointer<ToggleButton> detectToggle9;
    ScopedPointer<ToggleButton> detectToggle10;
    ScopedPointer<ToggleButton> actToggle;
    ScopedPointer<ToggleButton> actToggle2;
    ScopedPointer<ToggleButton> actToggle3;
    ScopedPointer<ToggleButton> actToggle4;
    ScopedPointer<ToggleButton> actToggle5;
    ScopedPointer<ToggleButton> actToggle6;
    ScopedPointer<ToggleButton> actToggle7;
    ScopedPointer<ToggleButton> actToggle8;
    ScopedPointer<ToggleButton> actToggle9;
    ScopedPointer<ToggleButton> actToggle10;
    ScopedPointer<TextButton> Mode;
    ScopedPointer<Slider> Attack;
    ScopedPointer<Slider> Release;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Fft_gateAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9D9ABCAC92C77E9F__
