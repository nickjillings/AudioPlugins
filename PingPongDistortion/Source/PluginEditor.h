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

#ifndef __JUCE_HEADER_751D9C72F9F29248__
#define __JUCE_HEADER_751D9C72F9F29248__

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
class PingPongDistortionAudioProcessorEditor  : public AudioProcessorEditor,
                                                public Timer,
                                                public SliderListener,
                                                public ButtonListener,
                                                public ComboBoxListener
{
public:
    //==============================================================================
    PingPongDistortionAudioProcessorEditor (PingPongDistortionAudioProcessor& ownerFilter);
    ~PingPongDistortionAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    PingPongDistortionAudioProcessor* getProcessor() const {
        return static_cast<PingPongDistortionAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> leftGain;
    ScopedPointer<Slider> rightGain;
    ScopedPointer<Slider> rightDelay;
    ScopedPointer<Slider> leftDelay;
    ScopedPointer<Slider> rightLP;
    ScopedPointer<Slider> leftLP;
    ScopedPointer<Slider> rightDistGain;
    ScopedPointer<Slider> rightDistGain2;
    ScopedPointer<Slider> feedCrossRight;
    ScopedPointer<Slider> feedCrossLeft;
    ScopedPointer<Slider> crossOverLeft;
    ScopedPointer<Slider> crossOverRight;
    ScopedPointer<Slider> leftBypassGain;
    ScopedPointer<Slider> rightBypassGain;
    ScopedPointer<TextButton> leftBypassMute;
    ScopedPointer<TextButton> rightBypassMute;
    ScopedPointer<TextButton> leftDelayFeedMute;
    ScopedPointer<TextButton> rightDelayFeedMute;
    ScopedPointer<TextButton> rightCrossOverToggle;
    ScopedPointer<TextButton> leftCrossOverToggle;
    ScopedPointer<ComboBox> leftDistortionMode;
    ScopedPointer<ComboBox> righttDistortionMode;
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;
    Path internalPath4;
    Path internalPath5;
    Path internalPath6;
    Path internalPath7;
    Path internalPath8;
    Path internalPath9;
    Path internalPath10;
    Path internalPath11;
    Path internalPath12;
    Path internalPath13;
    Path internalPath14;
    Path internalPath15;
    Path internalPath16;
    Path internalPath17;
    Path internalPath18;
    Path internalPath19;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingPongDistortionAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_751D9C72F9F29248__
