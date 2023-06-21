




for(int n = 0; n < order; n++){
   v[n] = x[n];

    if(n>= 1) {

        for(int i = 1; i <=n;i++) {
            v[n]-= pCoeffA[i] * v[n-1];
        }
    }


}

   



for(int n = 0;n <order; n++ ) {
 
    y[n] = pCoeffB[0] * v[n];

    if(n >= 1) {
        for(int i = 1; i <= n; i++) {

        y[n] += pCoeffB[i] * v[n-1];
    }
    }
        
   

    
}

#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 8000
#define COEFFICIENT 0.5
#define DELAY_MIN 0.025
#define DELAY_MAX 25.0
#define AMPLITUDE 1.0

float delayLine[(int)(DELAY_MAX * SAMPLE_RATE)];
int delayIndex = 0;

float flanger(float input) {
    // Calculate the delay time based on the current sample index
    float delayTime = (DELAY_MIN + (DELAY_MAX - DELAY_MIN) * (1 + sin(2 * M_PI * 0.25 * delayIndex / SAMPLE_RATE))) * SAMPLE_RATE;
    
    // Calculate the fractional and integer parts of the delay time
    int delayInt = (int)delayTime;
    float delayFrac = delayTime - delayInt;
    
    // Get the delayed sample using interpolation
    float delayedSample = delayLine[(delayIndex - delayInt - 1 + (int)DELAY_MAX * SAMPLE_RATE) % ((int)DELAY_MAX * SAMPLE_RATE)];
    float nextSample = delayLine[(delayIndex - delayInt) % ((int)DELAY_MAX * SAMPLE_RATE)];
    
    // Interpolate between delayed samples
    float interpolatedSample = (1 - delayFrac) * delayedSample + delayFrac * nextSample;
    
    // Update the delay line with the current input
    delayLine[delayIndex] = input;
    
    // Increment the delay index
    delayIndex = (delayIndex + 1) % ((int)DELAY_MAX * SAMPLE_RATE);
    
    // Apply the flanger effect by adding the interpolated sample to the input
    return input + COEFFICIENT * interpolatedSample;
}

int main() {
    // Assuming you have an array of audio samples
    float audioSamples[/*number of samples*/];
    
    for (int i = 0; i < /*number of samples*/; i++) {
        float input = audioSamples[i] / AMPLITUDE;  // Normalize the input to the range [-1, 1]
        float output = flanger(input);
        audioSamples[i] = output * AMPLITUDE;  // Scale the output back to the original range
    }
    
    // Rest of your code...
    
    return 0;
}

