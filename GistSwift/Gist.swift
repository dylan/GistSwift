/////    ___ _    _   ___        _  __ _
////    / __(_)__| |_/ __|_ __ _(_)/ _| |_
///    | (_ | (_-<  _\__ \ V  V / |  _|  _|
//      \___|_/__/\__|___/\_/\_/|_|_|  \__|

import Foundation
import GistSwiftWrapper

public final class Gist {
    fileprivate let gist: OpaquePointer

    /// The class for all performing all Gist audio analyses.
    /// - parameters:
    ///     - frameSize:   The input audio frame size.
    ///     - sampleRate: The input sample rate.
    public init(frameSize: Int, sampleRate: Int) {
        gist = initGist(Int32(frameSize), Int32(sampleRate))
    }

    /// Process an audio frame.
    /// - parameters:
    ///     - frame:   The audio frame to process.
    ///     - samples: The number of samples in the audio frame.
    public func processAudio(frame: [Float]) {
        var frame = frame
        GistSwiftWrapper.processAudioFrame(gist, &frame, UInt(frame.count))
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

// MARK: - Mel Frequency Related

    /// - returns: The Mel Frequency Spectrum.
    public func melFrequencySpectrum() -> [Float] {
        let value = GistSwiftWrapper.melFrequencySpectrum(gist)
        let bufferPointer = UnsafeBufferPointer<Float>(start: value.elements, count: Int(value.numElements))
        defer {
            free(value.elements)
        }
        return Array(bufferPointer)
    }

    /// - returns: the Mel Frequency Cepstral Coefficients as an array of ```Float```.
    public func melFrequencyCepstralCoefficients() -> [Float] {
        let value = GistSwiftWrapper.melFrequencyCepstralCoefficients(gist)
        let bufferPointer = UnsafeBufferPointer<Float>(start: value.elements, count: Int(value.numElements))
        defer {
            free(value.elements)
        }
        return Array(bufferPointer)
    }
// MARK: -

    deinit {
        GistSwiftWrapper.deinitGist(gist)
    }
}
