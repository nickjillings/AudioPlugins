/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "IntegerInterpolation.h"


//==============================================================================
/**
*/
class PingPongDistortionAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PingPongDistortionAudioProcessor();
    ~PingPongDistortionAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    int numInputChannels, numOutputChannels, windowSize;
    float gSampleRate;
    
    float exponentialDistortion(float sample, float G);
    float halfwaveRectification(float sample, float G);
    float sineDistortion(float sample, float G);
    float fullWaveRectification(float sample, float G);
    float hardClipping(float sample, float G);
    
    // GUI Parameter Callbacks
    float getDelayTimeSeconds(bool isLeft);
    float getCrossFeedGains(bool isLeft);
    float getPreGains(bool isLeft);
    float getDistortionGain(bool isLeft);
    float getCutoffFrequency(bool isLeft);
    float getBypassGains(bool isLeft);
    float getCrossOverFrequency(bool isLeft);
    
    // GUI Buttons
    bool getCrossOverOnState(bool isLeft);
    bool getDelayMuteState(bool isLeft);
    bool getBypassMuteState(bool isLeft);
    
    int getDistortionMode(bool isLeft);
    
    void setDelayTimeSeconds(float time, bool isLeft);
    void setCrossFeedGains(float gain, bool isLeft);
    void setPreGains(float gain, bool isLeft);
    void setDistortionGains(float gain, bool isLeft);
    void setCutoffFrequency(float freq, bool isLeft);
    void setBypassGains(float gain, bool isLeft);
    void setCrossOverFrequency(float freq, bool isLeft);
    void setCrossOverState(bool newState, bool isLeft);
    void setDelayMuteState(bool newState, bool isLeft);
    void setBypassMuteState(bool newState, bool isLeft);
    void setDistortionMode(int newMode, bool isLeft);

private:
    //==============================================================================
    
    IntInterp interpolators[2];
    
    AudioSampleBuffer inputChannelBuffer;
    AudioSampleBuffer upSampleBuffer;
    
    AudioSampleBuffer filterBanks;
    
    Butterworth delayLP[2];
    IIR_LR4_Coeff delayLPCoeffs[2];
    
    float* sampleData;
    long delayTimeSamples[2];
    int upsampleRatio = 4;
    long maxDelaySamples;
    float* delayLine[2];
    
    int distortionMode[2] = {0, 0};
    
    float delayTimeSeconds[2] = {0.5f, 0.5f};
    float readGains[2] = {0.667f, 0.667f};
    float lowPassFrequencies[2] = {1000.0f, 1000.0f};
    float preGains[2] = {1.0f, 1.0f};
    float distortionG[2] = {1.0f, 1.0f};
    float distortionGRecip[2] = {1.0f, 1.0f};
    float bypassGains[2] = {1.0f, 1.0f};
    
    // Cross-Overs
    bool crossOversOn[2] = {false, false};
    // Store the states for the crossovers. True is highpass and false is lowpass
    float crossOverFrequency[2] = {1000.0, 1000.0};
    IIR_LR4_Coeff crossOverLeftHigh, crossOverLeftLow, crossOverRightHigh, crossOverRightLow;
    IIR_LR4 crossOverLeft[2], crossOverRight[2];
    
    // Mute memories
    bool delayInputMute[2] = {false, false};
    bool bypassMute[2] = {false, false};
    
    
    long readPointers[2];
    long writePointer;
    
    bool hasInitialised = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingPongDistortionAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
