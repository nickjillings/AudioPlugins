//
//  IIR_LR4.cpp
//  MultibandCompressor
//
//  Created by Nicholas Jillings on 04/03/2015.
//
//

#include "IIR_LR4.h"

Butterworth::Butterworth()
{
    clearZ();
    a[0] = 0;
    a[1] = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
}

Butterworth::~Butterworth()
{
}

bool Butterworth::clearZ() {
    z[0] = 0;
    z[1] = 0;
    return true;
}

bool Butterworth::updateCoefficients(IIR_LR4_Coeff Coefficients)
{
    a[0] = Coefficients.a[0];
    a[1] = Coefficients.a[1];
    b[0] = Coefficients.b[0];
    b[1] = Coefficients.b[1];
    b[2] = Coefficients.b[2];
    return clearZ();
}

bool Butterworth::processFilter(float* data, int numSamples) {
    for (int n=0; n<numSamples; n++)
    {
        float v = data[n] - z[0]*a[0] - z[1]*a[1];
        data[n] = v*b[0] + z[0]*b[1] + z[1]*b[2];
        z[1] = z[0];
        z[0] = v;
    }
    return true;
}

float Butterworth::processSample(float sample) {
    float v = sample - z[0]*a[0] - z[1]*a[1];
    float ret = v*b[0] + z[0]*b[1] + z[1]*b[2];
    z[1] = z[0];
    z[0] = v;
    return ret;
}

IIR_LR4::IIR_LR4()
{
    // Constructor for the Linkwitz-Riley LR4 Filter
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    
    a[0] = 0;
    a[1] = 0;
    b = 0;
}

IIR_LR4::~IIR_LR4()
{
}

bool IIR_LR4::processFilter(float* data, int numSamples, bool highpass) {
    
    // Process one frame of data using the LR4 model, enhanced to only need 7 multiplies
    // Does not use extra two stores method
    float v;
    if (highpass) {
        for (int n=0; n<numSamples; n++) {
            v = data[n]*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
            data[n] = v - 4.0*z[0] + 6.0*z[1] - 4.0*z[2] + z[3];
            z[3] = z[2];
            z[2] = z[1];
            z[1] = z[0];
            z[0] = v;
            if (z[0] == INFINITY)
                return false;
        }
        
    } else {
        for (int n=0; n<numSamples; n++) {
            v = data[n]*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
            data[n] = v + 4.0*z[0] + 6.0*z[1] + 4.0*z[2] + z[3];
            z[3] = z[2];
            z[2] = z[1];
            z[1] = z[0];
            z[0] = v;
            if (z[0] == INFINITY)
                return false;
        }
    }
    return true;
}

float IIR_LR4::processSample(float sample, bool highpass) {
    float v;
    if (highpass) {
        v = sample*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
        sample = v - 4.0*z[0] + 6.0*z[1] - 4.0*z[2] + z[3];
        z[3] = z[2];
        z[2] = z[1];
        z[1] = z[0];
        z[0] = v;
    } else {
        v = sample*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
        sample = v + 4.0*z[0] + 6.0*z[1] + 4.0*z[2] + z[3];
        z[3] = z[2];
        z[2] = z[1];
        z[1] = z[0];
        z[0] = v;
    }
    return sample;
}

bool IIR_LR4::updateCoefficients(IIR_LR4_Coeff Coefficients) {
    // Reset the filter and set the coefficients using Kite's method to reduce the b coefficient counts
    b = Coefficients.b[0]*Coefficients.b[0];
    a[0] = 2.0 * Coefficients.a[0];
    a[1] = 2.0*Coefficients.a[1] + Coefficients.a[0]*Coefficients.a[0];
    a[2] = 2.0 * Coefficients.a[0]*Coefficients.a[1];
    a[3] = Coefficients.a[1]*Coefficients.a[1];
    clearZ();
    return true;
}

bool IIR_LR4::clearZ()
{
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    return true;
}

IIR_LR4_Coeff::IIR_LR4_Coeff()
{
    // Create a class to compute the coefficients
    T_ = 0;
    Fs_ = 0;
    Q_ = 0;
    c_ = 0;
    cSq_ = 0;
    a[0] = 0;
    a[1] = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
}

IIR_LR4_Coeff::~IIR_LR4_Coeff()
{
}

bool IIR_LR4_Coeff::calculateLowPass(float fc, float Fs)
{
    // Calculate 2nd order Butterworth a low-pass filter
    T_ = 1.0/Fs;
    double wd = 2.0*M_PI*fc*T_;
    double Omega = (2.0*Fs)*tan(wd/2.0);
    Q_ = sqrt(2.0)/2.0;
    c_ = 2.0*Fs; // 2/T = 2*(1/T)
    double OmSq = pow(Omega,2.0);
    cSq_ = pow(c_,2.0);
    
    double d = cSq_ + (Omega/Q_)*c_ + OmSq;
    a[0] = (2.0*OmSq - 2.0*cSq_)/d;
    a[1] = (cSq_ - (Omega/Q_)*c_ + OmSq)/d;
    
    double b0,b1;
    b0 = OmSq/d;
    b1 = 2.0*b0;
    
    b[0] = b0;
    b[1] = b1;
    b[2] = b0;
    return true;
}

bool IIR_LR4_Coeff::calculateHighPass(float fc, float Fs)
{
    // Calculate a 2nd order Butterworth high-pass filter
    Fs_ = Fs;
    T_ = 1.0/Fs_;
    double wd = 2.0*M_PI*fc*T_;
    double Omega = (2.0*Fs_)*tan(wd/2.0);
    Q_ = sqrt(2.0)/2.0;
    c_ = 2.0*Fs; // 2/T = 2*(1/T)
    double OmSq = pow(Omega,2.0);
    cSq_ = pow(c_,2.0);
    
    double d = cSq_ + (Omega/Q_)*c_ + OmSq;
    a[0] = (2.0*OmSq - 2.0*cSq_)/d;
    a[1] = (cSq_ - (Omega/Q_)*c_ + OmSq)/d;
    
    double b0,b1;
    b0 = cSq_/d;
    b1 = -2.0*b0;
    
    b[0] = b0;
    b[1] = b1;
    b[2] = b0;
    return true;
}

bool IIR_LR4_Coeff::importJUCE(bool highpass, float a1, float a2, float b0) {
    b[0] = b0;
    b[2] = b0;
    a[0] = a1;
    a[1] = a2;
    
    if (highpass)
        b[1] = -2.0*b0;
    else
        b[1] = 2.0*b0;
    return true;
}

IIR_LR4_LowPass::IIR_LR4_LowPass()
{
    // Create a Linkwitz-Riley 4th order Low Pass filter object
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    b = 0;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
}

IIR_LR4_LowPass::~IIR_LR4_LowPass()
{
}

bool IIR_LR4_LowPass::processFilter(float* data, int numSamples){
    // Process one frame of data using the LR4 model, enhanced to only need 7 multiplies
    // Does not use extra two stores method
    double v;
    for (int n=0; n<numSamples; n++) {
        v = data[n]*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
        data[n] = v + 4.0*z[0] + 6.0*z[1] + 4.0*z[2] + z[3];
        z[3] = z[2];
        z[2] = z[1];
        z[1] = z[0];
        z[0] = v;
        if (z[0] >= 10.0 || z[0] < -10.0)
            clearZ();
    }
    return true;
}

float IIR_LR4_LowPass::processSample(float sample) {
    float v = sample*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
    sample = v + 4.0*z[0] + 6.0*z[1] + 4.0*z[2] + z[3];
    z[3] = z[2];
    z[2] = z[1];
    z[1] = z[0];
    z[0] = v;
    return sample;
}

bool IIR_LR4_LowPass::updateCoefficients(IIR_LR4_Coeff Coefficients) {
    // Update filter coefficients using from the IIR_LR4_Coeff class
    // MUST HAVE USED CALCULATELOWPASS!!!!
    b = Coefficients.b[0]*Coefficients.b[0];
    a[0] = 2.0 * Coefficients.a[0];
    a[1] = 2.0*Coefficients.a[1] + Coefficients.a[0]*Coefficients.a[0];
    a[2] = 2.0 * Coefficients.a[0]*Coefficients.a[1];
    a[3] = Coefficients.a[1]*Coefficients.a[1];
    clearZ();
    return true;
}

bool IIR_LR4_LowPass::clearZ() {
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    return true;
}

IIR_LR4_HighPass::IIR_LR4_HighPass()
{
    // Create a 4th order Linkwitz-Riley filter for high-pass filtering
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    b = 0;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
}

IIR_LR4_HighPass::~IIR_LR4_HighPass()
{
}

bool IIR_LR4_HighPass::processFilter(float* data, int numSamples){
    // Process one frame of data using the LR4 model, enhanced to only need 7 multiplies
    // Does not use extra two stores method
    float v;
    for (int n=0; n<numSamples; n++) {
        v = data[n]*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
        data[n] = v - 4.0*z[0] + 6.0*z[1] - 4.0*z[2] + z[3];
        z[3] = z[2];
        z[2] = z[1];
        z[1] = z[0];
        z[0] = v;
        if (z[0] == INFINITY)
            return false;
    }
    return true;
}

float IIR_LR4_HighPass::processSample(float sample) {
    float v = sample*b - a[0]*z[0]-a[1]*z[1]-a[2]*z[2]-a[3]*z[3];
    sample = v - 4.0*z[0] + 6.0*z[1] - 4.0*z[2] + z[3];
    z[3] = z[2];
    z[2] = z[1];
    z[1] = z[0];
    z[0] = v;
    return sample;
}

bool IIR_LR4_HighPass::updateCoefficients(IIR_LR4_Coeff Coefficients) {
    // Update filter coefficients using from the IIR_LR4_Coeff class
    // MUST HAVE USED CALCULATEHIGHPASS!!!!
    b = Coefficients.b[0]*Coefficients.b[0];
    a[0] = 2.0 * Coefficients.a[0];
    a[1] = 2.0*Coefficients.a[1] + Coefficients.a[0]*Coefficients.a[0];
    a[2] = 2.0 * Coefficients.a[0]*Coefficients.a[1];
    a[3] = Coefficients.a[1]*Coefficients.a[1];
    clearZ();
    return true;
}

bool IIR_LR4_HighPass::clearZ() {
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    return true;
}

IIR_LR4_BandPass::IIR_LR4_BandPass()
{
    // Create and initialise the 8th order filter to perform the LR4 bandpass
    b=0;
    for (int i=0; i<8; i++) {
        a[i] = 0.0f;
        z[i] = 0.0f;
    }
}

IIR_LR4_BandPass::~IIR_LR4_BandPass()
{
}

bool IIR_LR4_BandPass::processFilter(float* data, int numSamples){
    // Process the 8th order IIR filter network
    
    double v;
    for (int n=0; n<numSamples; n++) {
        v = data[n]*b;
        for (int i=0; i<8; i++)
            v -= a[i]*z[i];
        data[n] = v - 4.0*z[1] + 6.0*z[3] - 4.0*z[5] + z[7];
        for (int i=7; i>0; i--)
            z[i] = z[i-1];
        z[0] = v;
        if (z[0] == INFINITY || z[0] >= 1.0)
            return false;
    }
    return true;
}

float IIR_LR4_BandPass::processSample(float sample) {
    double v = sample*b;
    for (int i=0; i<8; i++)
        v -= a[i]*z[i];
    sample = v - 4.0*z[1] + 6.0*z[3] - 4.0*z[5] + z[7];
    for (int i=7; i>0; i--)
        z[i] = z[i-1];
    z[0] = v;
    return sample;
}

bool IIR_LR4_BandPass::updateCoefficients(IIR_LR4_Coeff LowCoefficients, IIR_LR4_Coeff HighCoefficients) {
    // Update the 8th order coefficients by convolving the low coefficients and the high coefficients.
    // MUST HAVE USED CALCULATEHIGHPASS!!!!
    double bL = LowCoefficients.b[0]*LowCoefficients.b[0];
    double bH = HighCoefficients.b[0]*HighCoefficients.b[0];
    
    
    double aL[4] = {LowCoefficients.a[0], LowCoefficients.a[1], HighCoefficients.a[0], HighCoefficients.a[1]};
    
    // Convolve together to get the 4th order bandpass
    
    double c[4];
    
    c[0] = aL[0] + aL[2]; // z^-1
    c[1] = aL[3] + aL[0]*aL[2] + aL[1]; // z^-2
    c[2] = aL[0]*aL[3] + aL[1]*aL[2]; // z^-3
    c[3] = aL[1]*aL[3]; // z^-4
    
    // Now convolve with itself to get 8th order filter
    
    a[0] = 2.0*c[0]; // z^-1;
    a[1] = (2.0*c[1] + c[0]*c[0]); // z^-2
    a[2] = (2.0*c[0]*c[1] + 2.0*c[2]); // z^-3;
    a[3] = (2.0*c[3] + 2.0*c[0]*c[2] + c[1]*c[1]); // z^-4
    a[4] = (2.0*c[0]*c[3] + 2.0*c[1]*c[2]); // z^-5
    a[5] = (2.0*c[1]*c[3] + c[2]*c[2]); // z^-6
    a[6] = (2.0*c[2]*c[3]); // z^-7
    a[7] = (c[3]*c[3]); // z^-8
    
    // Set the b coefficient
    
    b = (bL*bH)*(bL*bH);
    
    return clearZ();

}

bool IIR_LR4_BandPass::clearZ() {
    for (int i=0; i<8; i++)
        z[i] = 0.0;
    return true;
}