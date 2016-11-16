/////    ___ _    _   ___        _  __ _
////    / __(_)__| |_/ __|_ __ _(_)/ _| |_
///    | (_ | (_-<  _\__ \ V  V / |  _|  _|
//      \___|_/__/\__|___/\_/\_/|_|_|  \__|

#include "Gist.h"
#include <stdio.h>

struct GistSwiftWrapper {
    Gist<float> gist;
    GistSwiftWrapper(int audioFrameSize, int fs) :  gist(Gist<float>(audioFrameSize, fs)) {}
};

extern "C" {
    struct GistSwiftWrapper* initGist(int audioFrameSize, int fs) {
        return new GistSwiftWrapper(audioFrameSize, fs);
    }

    void deinitGist(struct GistSwiftWrapper* gistSwift) {
        delete gistSwift;
    }

    void processAudioFrame(GistSwiftWrapper* gistSwift, float* buffer, unsigned long sample) {
        gistSwift->gist.processAudioFrame(buffer, sample);
    }

    float rootMeanSquare(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.rootMeanSquare();
    }

    float peakEnergy(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.peakEnergy();
    }

    float zeroCrossingRate(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.zeroCrossingRate();
    }

    float spectralDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralDifference();
    }

    float spectralCentroid(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralCentroid();
    }

    float spectralCrest(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralCrest();
    }

    float spectralFlatness(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralFlatness();
    }

    float spectralRolloff(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralRolloff();
    }

    float spectralKurtosis(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralKurtosis();
    }

    float energyDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.energyDifference();
    }

    float spectralDifferenceHWR(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralDifferenceHWR();
    }

    float complexSpectralDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.complexSpectralDifference();
    }

    float highFrequencyContent(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.highFrequencyContent();
    }

    float pitch(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.pitch();
    }

    float *melFrequencySpectrum(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.melFrequencySpectrum().data();
    }

    float *melFrequencyCepstralCoefficients(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.melFrequencyCepstralCoefficients().data();
    }

}
