//
//  GistSwift.cpp
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/11/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#include <stdio.h>
#include "Gist.h"

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

    void processAudioFrame(GistSwiftWrapper* gistSwift, float *buffer, unsigned long sample) {
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

    float complexSpectralDifference(GistSwiftWrapper* gistSwift) {
        return gistSwift->gist.complexSpectralDifference();
    }
}
