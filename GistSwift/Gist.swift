//
//  Gist.swift
//  GistSwift
//
//  Created by Dylan Wreggelsworth on 11/12/16.
//  Copyright © 2016 Dylan Wreggelsworth. All rights reserved.
//

import Foundation
import GistSwiftWrapper

public final class Gist {
    let gist = GistSwiftWrapper.gistInit()

    public init() {}

    public func processAudio(frame: [Float], sample: UInt) {
        var frame = frame
        GistSwiftWrapper.processAudioFrame(gist, &frame, sample)
    }

    public func peakEnergy() -> Float {
        return GistSwiftWrapper.peakEnergy(gist)
    }

    public func rootMeanSquare() -> Float {
        return GistSwiftWrapper.rootMeanSquare(gist)
    }

    public func spectralDifference() -> Float {
        return GistSwiftWrapper.spectralDifference(gist)
    }

    public func complexSpectralDifference() -> Float {
        return GistSwiftWrapper.complexSpectralDifference(gist)
    }

    deinit {
        GistSwiftWrapper.gistDeinit(gist)
    }
}
