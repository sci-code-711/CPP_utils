# Dev Instructions:

This repository is set up to use cmake for building and google test for testing

## C++ compiler:

You can get hold of a C++ compiler by following these instructions:

https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022

you should only need to build tools and then to add them to your path to be
able to use them from command line

## cmake:

Cmake can be downloaded from here: https://cmake.org/download/ choose the
binary download and the appropriate installer for your system.

You can configure your cmake build using the script:

`./DevGuide/utils/configureBuild.bat`

This set up the build configuration in a directory called testingBuild. To
actually build run the script:

`./DevGuide/utils/runBuild.bat`

Currently this is set up to

## Google test:

This  should be cloned locally into your repository under the `googletest`
folder in the root of the repository.

to do this run the script:

`./DevGuide/utils/getDependencies.bat`

## Running the build (tests):

To run the tests you can use the command:

`./DevGuide/utils/runTests.bat`
