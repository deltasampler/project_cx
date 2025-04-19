# CMake Build
## Setup
### Windows
* Install dependencies:
  * [Visual Studio](https://visualstudio.microsoft.com/) (Desktop development with C++)
  * [NVM](https://github.com/coreybutler/nvm-windows/releases)
* Install Node/NPM

      nvm install lts
* Build project

      git clone git@github.com:deltasampler/project_cx.git
      cd project_cx
      node build.js
### Linux
* Install dependencies:

      sudo apt install g++ cmake ninja-build
* Install vcpkg

      git clone https://github.com/microsoft/vcpkg.git
      cd vcpkg
      ./bootstrap-vcpkg.sh
      echo "export PATH=\"$(pwd):\$PATH\"" >> ~/.profile
* Install NVM

      curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.2/install.sh | bash
* Install Node/NPM

      nvm install lts
* Install additional dependencies (optional):

      sudo apt install libegl1-mesa-dev libibus-1.0-dev libltdl-dev libwayland-dev libx11-dev libxext-dev libxft-dev libxkbcommon-dev
* Build project

      git clone git@github.com:deltasampler/project_cx.git
      cd project_cx
      node build.js
