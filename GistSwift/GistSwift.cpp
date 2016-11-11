//
//  GistSwift.cpp
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/11/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#include <stdio.h>
#include "Gist.h"

class GistSwift {
public:
    Gist<float> gist = Gist<float>(512, 44100);
};

GistSwift *gistSwift;

extern "C" {
    void initGist() {
        gistSwift = new GistSwift();
    }

    void processAudioFrame(float *buffer, unsigned long sample) {
        gistSwift->gist.processAudioFrame(buffer, sample);
    }

    float peakEnergy() {
        return gistSwift->gist.peakEnergy();
    }

    float rootMeanSquare() {
        return gistSwift->gist.rootMeanSquare();
    }

    float spectralDifference() {
        return gistSwift->gist.spectralDifference();
    }

    float complexSpectralDifference() {
        return gistSwift->gist.complexSpectralDifference();
    }

    void deinitGist() {
        delete gistSwift;
    }
}

