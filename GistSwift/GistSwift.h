//
//  GistSwift.h
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/11/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for GistSwift.
FOUNDATION_EXPORT double GistSwiftVersionNumber;

//! Project version string for GistSwift.
FOUNDATION_EXPORT const unsigned char GistSwiftVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GistSwift/PublicHeader.h>

void initGist();
void processAudioFrame(float *buffer, unsigned long sample);
float peakEnergy();
float rootMeanSquare();
float spectralDifference();
float complexSpectralDifference();
void deinitGist();

