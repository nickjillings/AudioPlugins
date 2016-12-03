/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits>
#ifdef _WINDOWS
	#include <assert.h>
#endif
#include "pffft/pffft.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class Fft_gateAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Fft_gateAudioProcessor();
    ~Fft_gateAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    
    bool _justConstructed;
    
    PFFFT_Setup *s;
    double T;
    float* fftIn;
    float* fftOut;
    float dt, Fs;
    float bins;
    int N;
    int NStep;
    int winSize;
    bool process;
    bool setup;
    int bufferWritePos;
    int bufferReadPos;
    int bufferRunLength;
    int bufferSampleSize;
    int nBuf;
    int M;
    float scale;
    float cutLim, boostLim;
    int freqMaxIndex;
    double dBDiff;
    float attackAlpha;
    float releaseAlpha;
    
    HeapBlock <float> w;
    HeapBlock <float> G;
    HeapBlock <float> freqMag;
    HeapBlock <float> fM;
    HeapBlock <float> fA;
    HeapBlock <bool> act;
    HeapBlock <bool> detect;
    
    bool getAct(int index);
    bool getDetect(int index);
    void setAct(int index, bool val);
    void setDetect(int index, bool val);
    
    HeapBlock <int> fftBinBand;
    HeapBlock <int> fftBinCount;
    HeapBlock <float> bandMag;
    HeapBlock <float> bandMagdB;
    HeapBlock <float> bandMagMax;
    HeapBlock <float> GBand;
    
    float getBanddB(int index);
    
    float getThreshold();
    void setThreshold(float val);
    void setCutLimit(float val);
    void setBoostLimit(float val);
    
    float setTau(float secs);
    void setAttack(float tau);
    void setRelease(float tau);

private:
    //==============================================================================
    AudioSampleBuffer inputBuffer;
    AudioSampleBuffer outputBuffer;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Fft_gateAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
