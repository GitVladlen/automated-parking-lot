@echo off
mkdir build
cd build
cmake -Wno-dev -G "Visual Studio 16 2019" ..
cd ..
