/////    ___ _    _   ___        _  __ _
////    / __(_)__| |_/ __|_ __ _(_)/ _| |_
///    | (_ | (_-<  _\__ \ V  V / |  _|  _|
//      \___|_/__/\__|___/\_/\_/|_|_|  \__|

#include "Gist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct FloatArray {
    int numElements;
    float *elements;
} FloatArray;

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

    FloatArray magnitudeSpectrum(GistSwiftWrapper* gistSwift) {
        std::vector<float> vec = gistSwift->gist.getMagnitudeSpectrum();
        FloatArray result = {
            .numElements =  static_cast<int>(vec.size()),
            .elements = (float *)malloc(sizeof(float) * vec.size())
        };
        float *q = result.elements;
        for (float f : vec) {
            *q++ = f;
        }

        return result;
    }

    const float rootMeanSquare(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.rootMeanSquare();
    }

    const float peakEnergy(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.peakEnergy();
    }

    const float zeroCrossingRate(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.zeroCrossingRate();
    }

    const float spectralDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralDifference();
    }

    const float spectralCentroid(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralCentroid();
    }

    const float spectralCrest(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralCrest();
    }

    const float spectralFlatness(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralFlatness();
    }

    const float spectralRolloff(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralRolloff();
    }

    const float spectralKurtosis(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralKurtosis();
    }

    const float energyDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.energyDifference();
    }

    const float spectralDifferenceHWR(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.spectralDifferenceHWR();
    }

    const float complexSpectralDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.complexSpectralDifference();
    }

    const float highFrequencyContent(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.highFrequencyContent();
    }

    const float pitch(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.pitch();
    }


    FloatArray melFrequencySpectrum(GistSwiftWrapper* gistSwift) {
        std::vector<float> vec = gistSwift->gist.melFrequencySpectrum();
        FloatArray result = {
            .numElements =  static_cast<int>(vec.size()),
            .elements = (float *)malloc(sizeof(float) * vec.size())
        };
        float *q = result.elements;
        for (float f : vec) {
            *q++ = f;
        }

        return result;
    }

    FloatArray melFrequencyCepstralCoefficients(GistSwiftWrapper* gistSwift) {
        std::vector<float> vec = gistSwift->gist.melFrequencyCepstralCoefficients();

        FloatArray result = {
            .numElements =  static_cast<int>(vec.size()),
            .elements = (float *)malloc(sizeof(float) * vec.size())
        };
        float *q = result.elements;
        for (float f : vec) {
            *q++ = f;
        }

        return result;
    }

}
