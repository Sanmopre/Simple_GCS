#ifndef JOYSTICK_INPUT_H
#define JOYSTICK_INPUT_H

#include <iostream>
#include <GLFW/glfw3.h>


struct InputState 
{
    float roll;
    float pitch;
    float yaw;
    float throttle;
    int flaps_land;
    int flaps_takeoff;
    int flaps_cruise;
};

class JoystickInput 
{
public:
    JoystickInput();
    ~JoystickInput() = default;

    void update();

    std::string getJoystickName() 
    {
        if (glfwJoystickPresent(GLFW_JOYSTICK_1)) {
            const char* name = glfwGetJoystickName(GLFW_JOYSTICK_1);
            return std::string(name);
        } else {
            return "No joystick connected";
        }
    }

    InputState getInputState() 
    {
        return m_state;
    }

private:

    std::string m_joystickName;

    int m_axesCount;
    int m_buttonCount;
    InputState m_state;
};

JoystickInput::JoystickInput() 
{
    m_joystickName = getJoystickName();
    m_axesCount = 0;
    m_buttonCount = 0;
}


void JoystickInput::update() 
{
        InputState state;
        state.roll = 0.0f;
        state.pitch = 0.0f;
        state.yaw = 0.0f;
        state.throttle = 0.0f;
        state.flaps_land = 0;
        state.flaps_takeoff = 0;
        state.flaps_cruise = 0;

        if (glfwJoystickPresent(GLFW_JOYSTICK_1)) 
        {
            const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &m_axesCount);
            const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &m_buttonCount);

            state.roll = axes[0];
            state.pitch = axes[1];
            state.yaw = axes[2];
            state.throttle = axes[3] * 0.5f + 0.5f;

            state.flaps_land = buttons[10];
            state.flaps_takeoff = buttons[11];
            state.flaps_cruise = buttons[12];
        }

        m_state = state;
}
#endif // JOYSTICK_INPUT_H