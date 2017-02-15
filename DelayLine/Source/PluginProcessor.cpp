/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
DelayLineAudioProcessor::DelayLineAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
	readPointer(0),
	writePointer(0),
	delayLines(0x0),
	delayLineSamples(0),
	numDelayLines(0)
#endif
{
}

DelayLineAudioProcessor::~DelayLineAudioProcessor()
{
}

//==============================================================================
const String DelayLineAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DelayLineAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DelayLineAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double DelayLineAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DelayLineAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DelayLineAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DelayLineAudioProcessor::setCurrentProgram (int index)
{
}

const String DelayLineAudioProcessor::getProgramName (int index)
{
    return String();
}

void DelayLineAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DelayLineAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	if (delayLines == 0x0) {
		delayLineSamples = sampleRate;
	}
	readPointer = 0;
	writePointer = sampleRate*0.5;
}

void DelayLineAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
	if (!delayLines == 0x0) {
		for (unsigned int i = 0; i < numDelayLines; i++) {
			delete[] delayLines[i];
		}
		delayLines = 0x0;
		delayLineSamples = 0;
	}
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DelayLineAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DelayLineAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Only here doe we now have the total number of channels!
	// So now we can allocate the memory
	if (delayLines == 0x0) {
		delayLines = new float*[totalNumInputChannels];
		for (int i = 0; i < totalNumInputChannels; i++) {
			delayLines[i] = new float[delayLineSamples];
			for (unsigned int n = 0; n < delayLineSamples; n++) {
				delayLines[i][n] = 0.0f;
			}
		}
	}

	float** channelBuffers = buffer.getArrayOfWritePointers();
	for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
		for (int i = 0; i < buffer.getNumChannels(); i++) {
			delayLines[i][writePointer] = channelBuffers[i][sample];
			channelBuffers[i][sample] = delayLines[i][readPointer];
		}
		readPointer++;
		writePointer++;
		if (readPointer >= delayLineSamples) {
			readPointer = 0;
		}
		if (writePointer >= delayLineSamples) {
			writePointer = 0;
		}
	}
}

//==============================================================================
bool DelayLineAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DelayLineAudioProcessor::createEditor()
{
    return new DelayLineAudioProcessorEditor (*this);
}

//==============================================================================
void DelayLineAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DelayLineAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayLineAudioProcessor();
}
