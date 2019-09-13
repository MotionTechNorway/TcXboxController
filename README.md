# Requirements
1. Beckhoff TwinCAT and a running ADS Router
2. Microsoft Visual C++ Compiler
3. XInput API

# Build
1. `mkdir build && cd build`
2. `cmake .. -G "Visual Studio 15 2017 Win64"`
3. `cmake --build . --config Release`

# Usage
1. Make and instance of `ST_TcXboxXontroller` in e.g. `MAIN(PRG)` as `xbox : ST_TcXboxXontroller`
2. Execute `TcXboxController MAIN.xbox` from cmd

# In Case of Xbox ACC Driver Issue
Follow these instructions `https://www.drivereasy.com/knowledge/solved-xbox-acc-driver-issues-on-windows-10-8-7/`