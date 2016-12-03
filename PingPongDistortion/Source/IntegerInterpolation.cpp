//
//  IntegerInterpolation.cpp
//  PingPongDistortion
//
//  Created by Nicholas Jillings on 22/03/2015.
//
//

#include "IntegerInterpolation.h"

IntInterp::IntInterp()
{
    buffer = NULL;
    ratio = 1;
    blockSize = 1;
    Fs1 = 0;
    Fs2 = 0;
}

IntInterp::~IntInterp()
{
    if (buffer != NULL)
        delete[] buffer;
}

void IntInterp::initialise(float sampleRate, int newRatio, int windowSize)
{
    if (newRatio >= 1 && sampleRate > 0.0f) {
        ratio = newRatio;
        blockSize = windowSize;
        Fs1 = sampleRate;
        Fs2 = Fs1 * (float)ratio;
        buffer = new float[windowSize*ratio];
        design.calculateLowPass(Fs1/2.0, Fs2);
        upFilter.updateCoefficients(design);
        downFilter.updateCoefficients(design);
    } else {
        newRatio = 0;
        Fs1 = 0;
        Fs2 = 0;
    }
}

void IntInterp::upsample(float *inputBuffer, float *destination)
{
    // Perform sample by sample upsampling
    for (int i=0; i<blockSize*ratio; i++)
        buffer[i] = 0;
    
    for (int n=0; n<blockSize; n++) {
        buffer[n*ratio] = inputBuffer[n];
    }
    
    upFilter.processFilter(buffer, ratio*blockSize);
    
    for (int n=0; n<blockSize*ratio; n++) {
        destination[n] = buffer[n];
    }
}

void IntInterp::downsample(float *inputBuffer, float *destination)
{
    // Perform sample by sample downsampling
    for (int n=0; n<blockSize*ratio; n++)
        buffer[n] = inputBuffer[n];
    
    downFilter.processFilter(buffer, ratio*blockSize);
    for (int n=0; n<blockSize; n++)
        destination[n] = buffer[n*ratio];
}

void IntInterp::resetFilters()
{
    upFilter.clearZ();
    downFilter.clearZ();
}