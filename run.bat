@echo off
setlocal

set OUT=AirlineManagement.exe
g++ main.cpp User.cpp ConsoleManipulation.cpp Flight.cpp -o %OUT%
%OUT%
endlocal