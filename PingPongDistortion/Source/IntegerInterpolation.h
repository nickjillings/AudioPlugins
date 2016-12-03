//
//  IntegerInterpolation.h
//  PingPongDistortion
//
//  Created by Nicholas Jillings on 22/03/2015.
//
//

#ifndef __PingPongDistortion__IntegerInterpolation__
#define __PingPongDistortion__IntegerInterpolation__

#include <stdio.h>
#include "IIR_LR4.h"

class IntInterp {
public:
    IntInterp();
    ~IntInterp();
    void upsample(float* inputBuffer, float* destination);
    void downsample(float* inputBuffer, float* destination);
    void initialise(float sampleRate, int ratio, int windowSize);
    void resetFilters();
private:
    int ratio;
    int blockSize;
    float* buffer;
    float Fs1;
    float Fs2;
    IIR_LR4_Coeff design;
    IIR_LR4_LowPass upFilter;
    IIR_LR4_LowPass downFilter;
};

#endif /* defined(__PingPongDistortion__IntegerInterpolation__) */
