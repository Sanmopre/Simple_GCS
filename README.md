![LOGO](assets/images/logo.png)

# Simple GCS

Simple GCS (Ground Control Station) is a simpler version of a GCS for remote drone piloting. The application sends UDP packets with request information for the UAV (velocity, thrust etc…), and receives packets from the drone with position and status. The application is developed using C++ with ImGui as the UI of choice, and currently simulating the drone there is a python script. The intention of this project is to create an actual drone to be controlled with this GCS. This project was inspired by my work at Airbus Defence and Space where I am currently working on simulations for SIRTAP.



## Table of Contents

- [Showcase](#Showcase)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Showcase

![Demo](images/showcase.gif)

## Installation

This project was built using CMake and vcpkg as the package manager, so the instructions will be tailored to those tools. Before you proceed with the setup, ensure that you have CMake and vcpkg installed on your system. If you haven't installed them yet, you can find comprehensive installation instructions on their respective official websites.

- [CMake](https://cmake.org/download/)
- [vcpkg](https://vcpkg.io/en/getting-started)

Once you have CMake and vcpkg set up, change the CMakeLists CMAKE_TOOLCHAIN_FILE to fit with your vcpkg path and follow these steps to build and run the project:

```
vcpkg install glfw3 nlohmann-json boost-asio
vcpkg integrate install
mkdir build
cd build
cmake ..
make
```



## Usage

To start using the program just change the configuration file to make the ip addresses point to the right locations, and then run the python scripts under the tests folder for a simple dummy simulation of the UAV.

## Contributing

If you want to contribute or improve the code feel free to do it, just remember that configuration changes won't be accepted since this setup is meant for a particular environment. If you want to change the configuration feel free to fork the repo and make your changes accordingly.

## License

MIT License

Copyright (c) 2023 Santiago Moliner Prejano

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
