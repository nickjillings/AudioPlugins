//
//  IIR_LR4.h
//  MultibandCompressor
//
//  Created by Nicholas Jillings on 04/03/2015.
//
//

#ifndef __MultibandCompressor__IIR_LR4__
#define __MultibandCompressor__IIR_LR4__

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif
#include <math.h>

class IIR_LR4_Coeff;

class Butterworth {
public:
    Butterworth();
    ~Butterworth();
    bool updateCoefficients(IIR_LR4_Coeff Coefficients);
    bool processFilter(float* data, int numSamples);
    float processSample(float sample);
    bool clearZ();
private:
    float z[2];
    float a[2];
    float b[3];
};

class IIR_LR4 {
    // Implement a mono Linkwitz-Riley -24dB per octave filter
    
public:
    IIR_LR4();
    ~IIR_LR4();
    
    bool processFilter(float* data, int numSamples, bool highpass);
    bool updateCoefficients(IIR_LR4_Coeff Coefficients);
    float processSample(float sample, bool highpass);
    bool clearZ();
private:
    float z[4];
    float a[4];
    float b;
};

class IIR_LR4_LowPass {
    // Efficient LowPass filter using 7 multiplies
public:
    IIR_LR4_LowPass();
    ~IIR_LR4_LowPass();
    
    bool processFilter(float* data, int numSamples);
    bool updateCoefficients(IIR_LR4_Coeff Coefficients);
    bool clearZ();
    float processSample(float sample);
private:
    double z[4];
    double b;
    double a[4];
};

class IIR_LR4_HighPass {
    // Efficient HighPass filter using 7 multiplies
public:
    IIR_LR4_HighPass();
    ~IIR_LR4_HighPass();
    
    bool processFilter(float* data, int numSamples);
    bool updateCoefficients(IIR_LR4_Coeff Coefficients);
    bool clearZ();
    float processSample(float sample);
private:
    double z[4];
    double b;
    double a[4];
};

class IIR_LR4_BandPass {
    // Efficient BandPass using two LR4 Filters in one 8th order Direct Form 2
    // Uses 11 muls per sample not normal 17!
public:
    IIR_LR4_BandPass();
    ~IIR_LR4_BandPass();
    
    bool processFilter(float* data, int numSamples);
    bool updateCoefficients(IIR_LR4_Coeff LowCoefficients, IIR_LR4_Coeff HighCoefficients);
    float processSample(float sample);
private:
    bool clearZ();
    double z[8];
    double b;
    double a[8];
};

class IIR_LR4_Coeff {
    // Allows for single calculation of coefficients into filters
    friend class IIR_LR4;
    friend class Butterworth;
    friend class IIR_LR4_LowPass;
    friend class IIR_LR4_HighPass;
    friend class IIR_LR4_BandPass;
public:
    IIR_LR4_Coeff();
    ~IIR_LR4_Coeff();
    bool calculateLowPass(float fc, float Fs);
    bool calculateHighPass(float fc, float Fs);
    bool importJUCE(bool highpass, float a1, float a2, float b0);
private:
    double T_;
    double Fs_;
    double Q_;
    double c_;
    double cSq_;
    double a[2];
    double b[3];
};

#endif /* defined(__MultibandCompressor__IIR_LR4__) */
