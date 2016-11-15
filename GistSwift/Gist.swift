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
    fileprivate let gist: OpaquePointer

    public init(frameSize: Int, sampleRate: Int) {
        gist = initGist(Int32(frameSize), Int32(sampleRate))
    }

    public func processAudio(frame: [Float], sample: UInt) {
        var frame = frame
        GistSwiftWrapper.processAudioFrame(gist, &frame, sample)
    }

// MARK: - Core Time Domain Features

    /// - returns: The root mean square (RMS) of the currently stored audio frame.
    public func rootMeanSquare() -> Float {
        return GistSwiftWrapper.rootMeanSquare(gist)
    }

    /// - returns: The peak energy of the currently stored audio frame.
    public func peakEnergy() -> Float {
        return GistSwiftWrapper.peakEnergy(gist)
    }

    /// - returns: The peak energy of the currently stored audio frame. the zero crossing rate of the currently stored audio frame.
    public func zeroCrossingRate() -> Float {
        return GistSwiftWrapper.zeroCrossingRate(gist)
    }

// MARK: - Core Frequency Domain Features

    /// - returns: The spectral centroid from the magnitude spectrum.
    public func spectralCentroid() -> Float {
        return GistSwiftWrapper.spectralCentroid(gist)
    }

    /// - returns: The spectral crest.
    public func spectralCrest() -> Float {
        return GistSwiftWrapper.spectralCrest(gist)
    }

    /// - returns: The spectral flatness of the magnitude spectrum.
    public func spectralFlatness() -> Float {
        return GistSwiftWrapper.spectralFlatness(gist)
    }

    /// - returns: The spectral rolloff of the magnitude spectrum.
    public func spectralRolloff() -> Float {
        return GistSwiftWrapper.spectralRolloff(gist)
    }

    /// - returns: The spectral kurtosis of the magnitude spectrum.
    public func spectralKurtosis() -> Float {
        return GistSwiftWrapper.spectralKurtosis(gist)
    }

// MARK: - Onset Detection

    /// - returns: Calculates the energy difference onset detection function.
    public func energyDifference() -> Float {
        return GistSwiftWrapper.energyDifference(gist)
    }
    /// - returns: the spectral difference onset detection function sample for the magnitude spectrum frame.
    public func spectralDifference() -> Float {
        return GistSwiftWrapper.spectralDifference(gist)
    }

    /// - returns: Calculates the half wave rectified spectral difference between the current magnitude spectrum and the previous magnitude spectrum.
    public func spectralDifferenceHWR() -> Float {
        return GistSwiftWrapper.spectralDifferenceHWR(gist)
    }

    /// - returns: Calculates the complex spectral difference from the real and imaginary parts of the FFT.
    public func complexSpectralDifference() -> Float {
        return GistSwiftWrapper.complexSpectralDifference(gist)
    }

    /// - returns: Calculates the high frequency content onset detection function from the magnitude spectrum.
    public func highFrequencyContent() -> Float {
        return GistSwiftWrapper.highFrequencyContent(gist)
    }

// MARK: - Pitch Detection

    /// - returns: A monophonic pitch estimate according to the Yin algorithm.
    public func pitch() -> Float {
        return GistSwiftWrapper.pitch(gist)
    }

    deinit {
        GistSwiftWrapper.deinitGist(gist)
    }
}
