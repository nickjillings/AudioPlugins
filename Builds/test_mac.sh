#!/bin/sh
cd ~/
mkdir test
cd test

echo "Get Source"
git clone --depth 1 https://github.com/nickjillings/AudioPlugins

echo "Compile JUCE"
git clone --depth 1 https://github.com/julianstorer/JUCE
cd ./JUCE/extras/Projucer/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
mv ./build/Release/Projucer.app ~/test/
cd ~/test/

echo "Update Projects"
./Projucer.app/Contents/MacOS/Projucer --resave ./AudioPlugins/Overdrive/Overdrive.jucer > /dev/null
./Projucer.app/Contents/MacOS/Projucer --resave ./AudioPlugins/DelayLine/DelayLine.jucer > /dev/null

echo "Build Plugin"
cd ./AudioPlugins/Overdrive/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ./AudioPlugins/DelayLine/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null

echo "Done"

cd ..
