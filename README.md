# Requirements
1. Windows API
2. Beckhoff TwinCAT and a running ADS Router
3. Microsoft Visual C++ Compiler
4. XInput API

# Build
Before building the executable, ensure that the string specifying the location of `S_TcXboxController` is set correctly. I.e. `char plcVar[] = {"MAIN.xbox"};` inside `main.cpp` source file.
1. `mkdir build && cd build`
2. `cmake .. -G "Visual Studio 15 2017 Win64"`
3. `cmake --build . --config Release`

# Usage
1. Open a new terminal as Administrator and create a new Windows Service using:
   1. `sc create "TcXboxController" binPath=<path-to-binary>\TcXboxController.exe`
2. Start and stop the service using the Windows GUI or by executing:
   1. `sc start TcXboxController` or `sc stop TcXboxController`

# In Case of Xbox ACC Driver Issue
Follow these instructions `https://www.drivereasy.com/knowledge/solved-xbox-acc-driver-issues-on-windows-10-8-7/`