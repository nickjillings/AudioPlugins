/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "pffft/pffft.h"

//==============================================================================
Fft_gateAudioProcessor::Fft_gateAudioProcessor()
: inputBuffer(1,1),
outputBuffer(1,1)
{
}

Fft_gateAudioProcessor::~Fft_gateAudioProcessor()
{
}

//==============================================================================
const String Fft_gateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int Fft_gateAudioProcessor::getNumParameters()
{
    return 0;
}

float Fft_gateAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void Fft_gateAudioProcessor::setParameter (int index, float newValue)
{
}

const String Fft_gateAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String Fft_gateAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String Fft_gateAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String Fft_gateAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool Fft_gateAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool Fft_gateAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool Fft_gateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Fft_gateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Fft_gateAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double Fft_gateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Fft_gateAudioProcessor::getNumPrograms()
{
    return 0;
}

int Fft_gateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Fft_gateAudioProcessor::setCurrentProgram (int index)
{
}

const String Fft_gateAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void Fft_gateAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Fft_gateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    if (!_justConstructed) {
        M = getNumInputChannels();
        winSize = samplesPerBlock;
        T = -10.0;
        N = 2048;
        scale = 1.0/(float)N;
        NStep = 256;
        Fs = sampleRate;
        bins = Fs/(float)N;
        dt = 1.0/sampleRate;
        inputBuffer.setSize(getNumInputChannels(), N+winSize);
        outputBuffer.setSize(getNumInputChannels(), N+winSize);
        process = false;
        bufferWritePos = 0;
        bufferReadPos = 0;
        bufferSampleSize = N+winSize;
        bufferRunLength = bufferSampleSize / winSize;
        nBuf = winSize/NStep;
        s = pffft_new_setup(N, PFFFT_REAL);
        _justConstructed = true;
        G.allocate(N/2+1, true);
        GBand.allocate(N/2+1,true);
        freqMag.allocate(N/2+1, true);
        fM.allocate(N/2+1,true);
        fA.allocate(N/2+1,true);
        setup = false;
        w.allocate(N,true);
        
        cutLim = 0;
        boostLim = 0;
        
        act.allocate(10, false);
        detect.allocate(10, false);
        for (int k=0; k<10; k++) {
            act[k] = true;
            detect[k] = true;
        }
        
        setAttack(setTau(0.02));
        setRelease(setTau(0.02));
        
        bandMag.allocate(10, true);
        bandMagdB.allocate(10, true);
        bandMagMax.allocate(10, true);
        fftBinBand.allocate(N/2+1, false);
        fftBinCount.allocate(10, true);
        for (int k=0; k<N/2+1; k++) {
            if (k*bins <= 60) {
                fftBinBand[k] = 0;
                fftBinCount[0]++;
            }
            else if (k*bins <= 120){
                fftBinBand[k] = 1;
                fftBinCount[1]++;
            }
            else if (k*bins <= 250){
                fftBinBand[k] = 2;
                fftBinCount[2]++;
            }
            else if (k*bins <= 500){
                fftBinBand[k] = 3;
                fftBinCount[3]++;
            }
            else if (k*bins <= 1000){
                fftBinBand[k] = 4;
                fftBinCount[4]++;
            }
            else if (k*bins <= 2000){
                fftBinBand[k] = 5;
                fftBinCount[5]++;
            }
            else if (k*bins <= 4000){
                fftBinBand[k] = 6;
                fftBinCount[6]++;
            }
            else if (k*bins <= 8000){
                fftBinBand[k] = 7;
                fftBinCount[7]++;
            }
            else if (k*bins <= 16000){
                fftBinBand[k] = 8;
                fftBinCount[8]++;
            }
            else{
                fftBinBand[k] = 9;
                fftBinCount[9]++;
            }
        }
    }
}

void Fft_gateAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    pffft_aligned_free(fftIn);
    pffft_aligned_free(fftOut);
    process = false;
    setup = false;
}

void Fft_gateAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // Process Chain
    
    if (!setup)
    {
        fftIn = (float*)pffft_aligned_malloc(N*sizeof(float)*2);
        fftOut = (float*)pffft_aligned_malloc((N/2+1)*sizeof(float)*2);
        setup = true;
        dBDiff = 0.0;
        for (int k=0; k<N; k++)
            fftIn[k] = 0.0;
        for (int k=0; k<N/2+1; k++) {
            G[k] = 1.0;
            fftOut[k] = 0.0;
        }
        for (int k=0; k<N; k++)
            w[k] = 0.5*(1.0-cos((2.0*M_PI*k)/((float)N-1.0)));
        
        for (int channelId=0; channelId<getNumInputChannels(); channelId++) {
            for (int k=0; k<bufferSampleSize; k++) {
                inputBuffer.setSample(channelId, k, 0.0);
                outputBuffer.setSample(channelId, k, 0.0);
            }
        }
        if (outputBuffer.getMagnitude(0, bufferSampleSize) != 0)
            assert(outputBuffer.getMagnitude(0, bufferSampleSize) == 0);
        assert(outputBuffer.getMagnitude(0, N+winSize) == 0);
        bufferReadPos = 0;
        bufferWritePos = 0;
        
    }
    
    // Buffer Data to 2048+WinSize
    // Calculate number of frames for step size available
    // Send frame to fftIn
    
    for (int sample=0; sample<winSize; sample++)
    {
        for (int c=0; c<getNumInputChannels(); c ++) {
            inputBuffer.setSample(c, bufferWritePos*winSize + sample, buffer.getSample(c, sample));
            buffer.setSample(c, sample, 0);
        }
    }
    bufferWritePos++;
    if (bufferWritePos >= bufferRunLength) {
        bufferWritePos = 0;
        process = true;
    }
    
    int sample = 0;
    if (process == true)
     {
         for (int n=0; n<winSize/NStep; n++) {
            for (int k=0; k<10; k++) {
                bandMag[k] = 0;
                bandMagdB[k] = 0;
                bandMagMax[k] = 0;
            }
            for (int channelId=0; channelId<getNumInputChannels(); channelId++) {
                for (int k=0; k<N; k++) {
                    sample = bufferReadPos*winSize + n*NStep + k;
                    if (sample >= bufferSampleSize)
                        sample -= bufferSampleSize;
                    fftIn[k] = inputBuffer.getSample(channelId, sample);
                }
                
                pffft_transform_ordered(s, fftIn, fftOut, NULL, PFFFT_FORWARD);
                // Frequency Domain Processing
                
                float freqMax = 0.0;
                for (int k=0; k<N/2+1; k++) {
                    fM[k] = sqrtf(powf(fftOut[k*2], 2.0)+powf(fftOut[k*2+1],2.0));
                    fA[k] = atan2f(fftOut[k*2+1], fftOut[k*2]);
                }
                freqMaxIndex = 0.0;
                float temp = 0.0;
                for (int k=0; k<N/2+1; k++) {
                    if (fM[k] < std::numeric_limits<float>::infinity( ) && fM[k] > -std::numeric_limits<float>::infinity( )) {
                        bandMag[fftBinBand[k]] += fM[k] / (float)fftBinCount[fftBinBand[k]];
                        if (fM[k] >= bandMagMax[fftBinBand[k]])
                            bandMagMax[fftBinBand[k]] = fM[k];
                        if (fM[k] > temp  && detect[fftBinBand[k]]) {
                            temp = fM[k];
                            freqMaxIndex = k;
                        }
                    }
                }
                for (int k=0; k<10; k++) {
                    if (detect[k] && bandMagMax[k] >= freqMax)
                        freqMax = bandMagMax[k];
                }
                for (int k=0; k<10; k++)
                    bandMagdB[k] = 20*log10f(bandMag[k]/freqMax);
                
                double dB1 = 0.0, dB2 = 0.0;
                if (freqMax > 0 && freqMax < std::numeric_limits<float>::infinity( )) {
                    for (int k=0; k<N/2+1; k++) {
                        if (fM[k] > 0 && fM[k] < std::numeric_limits<float>::infinity( )) {
                            freqMag[k] = 20 *log10f(fM[k]/freqMax);
                            dB1 += 20*log10f(fM[k]);
                        }
                    }
                    double re, im;
                    for (int k=0; k<N/2+1; k++) {
                        if (act[fftBinBand[k]]) {
                            if (freqMag[k] >= T)
                                G[k] = releaseAlpha*cutLim+(1.0-releaseAlpha)*G[k];
                            else
                                G[k] = attackAlpha*boostLim+(1.0-attackAlpha)*G[k];
                            if (G[k] >= boostLim)
                                G[k] = boostLim;
                            else if (G[k] <= cutLim)
                                G[k] = cutLim;
                            if (act[fftBinBand[k]] == false)
                                G[k] = 1.0;
                            fM[k] *= G[k];
                            re = fM[k] * cos(fA[k]);
                            im = fM[k] * sin(fA[k]);
                            fftOut[k*2] = re;
                            fftOut[k*2+1] = im;
                        }
                        else
                            G[k] = 1;
                        if (fM[k] >0 && fM[k]<std::numeric_limits<float>::infinity( ))
                            dB2 += 20*log10f(fM[k]);
                    }
                    dBDiff = (dB2/(float)(N/2+1))-(dB1/(float)(N/2+1));
                }
                fftOut[0] = 0.0;
                fftOut[1] = 0.0;
                for (int k=0; k<10; k++)
                    GBand[k] = 0.0;
                for (int k=0; k<N/2+1; k++)
                    GBand[fftBinBand[k]] += G[k];
                for (int k=0; k<10; k++)
                    GBand[k] = 20*log10(GBand[k]/(float)fftBinCount[k]);
                
                pffft_transform_ordered(s, fftOut, fftIn, NULL, PFFFT_BACKWARD);
                
                for (int k=0; k<N; k++) {
                    sample = n*NStep + k;
                    outputBuffer.addSample(channelId, sample, fftIn[k]*scale);
                    //outputBuffer.setSample(channelId, sample, inputBuffer.getSample(channelId, sample));
                }
            }
        }
        bufferReadPos++;
        if (bufferReadPos >= bufferRunLength)
            bufferReadPos = 0;
    }
    else {
        outputBuffer.clear();
    }
    
    for (int k=0; k<winSize; k++) {
        for (int channelId=0; channelId<getNumInputChannels(); channelId++) {
            buffer.setSample(channelId, k, outputBuffer.getSample(channelId, k)/((float)nBuf*2.0));
            outputBuffer.setSample(channelId, k, 0.0);
        }
    }
    
    for (int channelId=0; channelId<getNumInputChannels(); channelId++) {
        for (int k=0; k<N; k++) {
            outputBuffer.setSample(channelId, k, outputBuffer.getSample(channelId, k+winSize));
        }
        for (int k=0; k<winSize; k++)
            outputBuffer.setSample(channelId, k+N, 0.0);
    }

    
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

bool Fft_gateAudioProcessor::getAct(int index)
{
    return act[index];
}

bool Fft_gateAudioProcessor::getDetect(int index)
{
    return detect[index];
}

void Fft_gateAudioProcessor::setAct(int index, bool val)
{
    act[index] = val;
}

void Fft_gateAudioProcessor::setDetect(int index, bool val)
{
    detect[index] = val;
}

float Fft_gateAudioProcessor::getBanddB(int index) {
    if (index >= 0 && index < 10)
        return bandMagdB[index];
    else
        return 0;
}

float Fft_gateAudioProcessor::getThreshold() {return T;}

void Fft_gateAudioProcessor::setThreshold(float val)
{
    if (val < -60.0f)
        val = -60.0f;
    else if (val > 0.0f)
        val = 0.0f;
    
    T = val;
}

void Fft_gateAudioProcessor::setCutLimit(float val)
{
    if (val <= -36.0f)
        val = -36.0f;
    else if (val >= 0.0f)
        val = -0.0f;
    
    cutLim = powf(10,val/20);
}

void Fft_gateAudioProcessor::setBoostLimit(float val)
{
    if (val >= 36.0f)
        val = 36.0f;
    else if (val <= 0.0f)
        val = 0.0f;
    
    boostLim = powf(10,val/20);
}

float Fft_gateAudioProcessor::setTau(float secs)
{
    if (secs <= 0.0)
        secs = 0.0;
    float Fs2 = Fs/(float)NStep;
    float tau = 1.0 - exp(-1.0/Fs2*secs);
    return tau;
}

void Fft_gateAudioProcessor::setAttack(float tau)
{
    if (tau >= 1.0)
        tau = 1.0;
    else if (tau <= 0.0)
        tau = 0.0;
    attackAlpha = tau;
}

void Fft_gateAudioProcessor::setRelease(float tau)
{
    if (tau >= 1.0)
        tau = 1.0;
    else if (tau <= 0.0)
        tau = 0.0;
    releaseAlpha = tau;
}

//==============================================================================
bool Fft_gateAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Fft_gateAudioProcessor::createEditor()
{
    return new Fft_gateAudioProcessorEditor (this);
}

//==============================================================================
void Fft_gateAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Fft_gateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Fft_gateAudioProcessor();
}
