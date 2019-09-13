echo off
if "%1" == "" goto COMPILE

if "%1" == "clean" goto CLEAN

if "%1" == "config" goto CONFIG
echo on


:COMPILE
if exist build (
    cd build
    cmake --build . --config Release
    cd ..
    echo Compile done!
) else (
    echo Run "make config" before running "make" command!
)
goto DONE

:CLEAN
if exist build (
    rmdir /s /q build
    echo Clean done!
) else (
    echo Already clean!
)
goto DONE

:CONFIG
mkdir build 
cd build
cmake .. -G "Visual Studio 15 2017 Win64"
type NUL > __init__.py
cd ..
echo Config done!
goto DONE


:DONE
