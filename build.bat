@echo off
mkdir build && cd src && g++ -g -o ../build/ConfigurationParser ConfigParser.cpp main.cpp
