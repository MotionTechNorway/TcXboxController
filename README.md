# Requirements
1. Beckhoff TwinCAT and a running ADS Router
2. Microsoft Visual C++ Compiler
3. XInput API

# Build
1. Execute tha bat script `make.bat` using the following commands depending on what you want to do:
    1. `make config`
    2. `make`

# Usage
1. Make and instance of `ST_TcXboxXontroller` in e.g. `MAIN(PRG)` as `xbox : ST_TcXboxXontroller`
2. Execute `TcXboxController MAIN.xbox` from cmd

# In Case of Xbox ACC Driver Issue
Follow these instructions `https://www.drivereasy.com/knowledge/solved-xbox-acc-driver-issues-on-windows-10-8-7/`