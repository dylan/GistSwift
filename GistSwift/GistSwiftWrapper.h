//
//  GistSwiftWrapper.h
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/12/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#ifndef GistSwiftWrapper_h
#define GistSwiftWrapper_h

struct GistSwift* initGist(int audioFrameSize, int sampleRate);

void deinitGist(struct GistSwift* gistSwift);

void processAudioFrame(struct GistSwift* gistSwift, float *buffer, unsigned long sample);

float rootMeanSquare(struct GistSwift* gistSwift);

float peakEnergy(struct GistSwift* gistSwift);

float zeroCrossingRate(struct GistSwift* gistSwift);

float spectralDifference(struct GistSwift* gistSwift);

float spectralCentroid(struct GistSwift* gistSwift);

float spectralCrest(struct GistSwift* gistSwift);

float spectralFlatness(struct GistSwift* gistSwift);

float spectralRolloff(struct GistSwift* gistSwift);

float spectralKurtosis(struct GistSwift* gistSwift);

float energyDifference(struct GistSwift* gistSwift);

float spectralDifferenceHWR(struct GistSwift* gistSwift);

float complexSpectralDifference(struct GistSwift* gistSwift);

float highFrequencyContent(struct GistSwift* gistSwift);

float pitch(struct GistSwift* gistSwift);

#endif /* GistSwiftWrapper_h */
