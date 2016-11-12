//
//  GistSwiftWrapper.h
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/12/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#ifndef GistSwiftWrapper_h
#define GistSwiftWrapper_h

struct GistSwift* gistInit();
void gistDeinit(struct GistSwift* gistSwift);

void processAudioFrame(struct GistSwift* gistSwift, float *buffer, unsigned long sample);

float peakEnergy(struct GistSwift* gistSwift);

float rootMeanSquare(struct GistSwift* gistSwift);

float spectralDifference(struct GistSwift* gistSwift);

float complexSpectralDifference(struct GistSwift* gistSwift);

#endif /* GistSwiftWrapper_h */
