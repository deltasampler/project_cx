# CMake Build
## Setup
### Windows
* Install dependencies:
  * [Visual Studio](https://visualstudio.microsoft.com/) (Desktop development with C++)
  * [Python](https://www.python.org/downloads/)
* Build project

      git clone git@github.com:deltasampler/cmake_build.git
      cd cmake_build
      python build.py
### Linux
* Install dependencies:

      sudo apt install g++ cmake ninja-build python3
* Install vcpkg

      git clone https://github.com/microsoft/vcpkg.git
      cd vcpkg
      ./bootstrap-vcpkg.sh
      echo "export PATH=\"$(pwd):\$PATH\"" >> ~/.profile
* Build project

      git clone git@github.com:deltasampler/cmake_build.git
      cd cmake_build
      python3 build.py
* Install additional dependencies (optional):

      sudo apt install libegl1-mesa-dev libibus-1.0-dev libltdl-dev libwayland-dev libx11-dev libxext-dev libxft-dev libxkbcommon-dev
