# GistSwift - A Swift wrapper for Gist

GistSwift is a wrapper framework for the awesome [Gist](https://github.com/adamstark/Gist) C++ Real-Time Audio Analysis Library by [Adam Stark](https://github.com/adamstark/).

## Requirements

| Supported | Version |
| :--- | :---: |
| OS    | macOS, iOS |
| Swift | 3.01 |
| Xcode | 8.x |

## Installation

### Carthage
```OGDL
github "dylan/GistSwift" "master"
```

## Usage

**NOTE:** Right now GistSwift only supports ```Float``` value types, and uses the FFT in Apple's Accelerate.framework.

```swift
import GistSwift

// Initialize a swift wrapped Gist instance...
let gist = Gist(frameSize: 512, sampleRate: 44100)

// First get a frame of audio samples to analyze, this is usually done in a loop as you work your way through the file...
let frame = [SomeFloatAudioData]()

// Process the sample frame...
gist.processAudio(frame: frame)

// Get a Float value representing the peak energy of this frame. Other methods can be found in the Gist class...
gist.peakEnergy()

```


## License

Copyright (c) 2016 Dylan Wreggelsworth

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.



