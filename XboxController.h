#pragma once

// https://katyscode.wordpress.com/2013/08/30/xinput-tutorial-part-1-adding-gamepad-support-to-your-windows-game/

// We need the Windows Header and the XInput Header
#include <windows.h>
#include <iostream>
#include <cmath>
#include <chrono>
#include <XInput.h>

// Now, the XInput Library
// NOTE: COMMENT THIS OUT IF YOU ARE NOT USING
// A COMPILER THAT SUPPORTS THIS METHOD OF LINKING LIBRARIES
#pragma comment(lib, "XInput.lib")

struct TcXboxController
{
    unsigned int counter;
    bool A;
    bool B;
    bool X;
    bool Y;
    bool LB;
    bool RB;
    bool BACK;
    bool START;
    bool DPAD_UP;
    bool DPAD_DOWN;
    bool DPAD_LEFT;
    bool DPAD_RIGHT;
    bool LEFT_THUMB;
    bool RIGHT_THUMB;
    float LEFT_TRIGGER;
    float RIGHT_TRIGGER;
    float LX;
    float LY;
    float RX;
    float RY;
};

// XBOX Controller Class Definition
class XboxController : public TcXboxController
{
private:
    int cId;
    XINPUT_STATE state;

    // Deadzone settings
    float deadzoneX = 0.1f;
    float deadzoneY = 0.1f;
 
public:
    // Constructor and destructor
    XboxController();
    ~XboxController();
    
    void vibrate(float left, float right);
    bool isConnected();
    void battery();
    bool update();
};