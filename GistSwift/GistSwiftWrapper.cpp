//
//  GistSwift.cpp
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/11/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#include "Gist.h"
#include <stdio.h>

struct GistSwiftWrapper {
  Gist<float> gist = Gist<float>(512, 44100);
};

extern "C" {
    struct GistSwiftWrapper* initGist() {
      return new GistSwiftWrapper;
    }

    void deinitGist(struct GistSwiftWrapper* gistSwift) {
      delete gistSwift;
    }

    void processAudioFrame(GistSwiftWrapper* gistSwift,
                           float* buffer,
                           unsigned long sample) {
      gistSwift->gist.processAudioFrame(buffer, sample);
    }

    float peakEnergy(GistSwiftWrapper* gistSwift) {
      return gistSwift->gist.peakEnergy();
    }

    float rootMeanSquare(GistSwiftWrapper* gistSwift) {
      return gistSwift->gist.rootMeanSquare();
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
}
