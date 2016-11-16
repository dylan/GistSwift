/////    ___ _    _   ___        _  __ _
////    / __(_)__| |_/ __|_ __ _(_)/ _| |_
///    | (_ | (_-<  _\__ \ V  V / |  _|  _|
//      \___|_/__/\__|___/\_/\_/|_|_|  \__|

#ifndef GistSwiftWrapper_h
#define GistSwiftWrapper_h

struct GistSwift* initGist(int audioFrameSize, int sampleRate);

void deinitGist(struct GistSwift* gistSwift);

void processAudioFrame(struct GistSwift* gistSwift, float *buffer, unsigned long sample);

const float rootMeanSquare(struct GistSwift* gistSwift);

const float peakEnergy(struct GistSwift* gistSwift);

const float zeroCrossingRate(struct GistSwift* gistSwift);

const float spectralDifference(struct GistSwift* gistSwift);

const float spectralCentroid(struct GistSwift* gistSwift);

const float spectralCrest(struct GistSwift* gistSwift);

const float spectralFlatness(struct GistSwift* gistSwift);

const float spectralRolloff(struct GistSwift* gistSwift);

const float spectralKurtosis(struct GistSwift* gistSwift);

const float energyDifference(struct GistSwift* gistSwift);

const float spectralDifferenceHWR(struct GistSwift* gistSwift);

const float complexSpectralDifference(struct GistSwift* gistSwift);

const float highFrequencyContent(struct GistSwift* gistSwift);

const float pitch(struct GistSwift* gistSwift);

typedef struct FloatArray {
    int numElements;
    float *elements;
} FloatArray;

FloatArray melFrequencySpectrum(struct GistSwift* gistSwift);

FloatArray melFrequencyCepstralCoefficients(struct GistSwift* gistSwift);

#endif /* GistSwiftWrapper_h */
