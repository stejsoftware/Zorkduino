#include <Arduino.h>
#include <ZMachine.h>

#include "SerialKeyboard.h"
#include "SerialScreen.h"

void setup()
{
    uint8_t story[] = {};
    uint16_t length = 0;

    ZMachine.setKeyboard(SerialKeyboard);
    ZMachine.setScreen(SerialScreen);
    ZMachine.loadStory((zbyte_t *)story, (zword_t)length);
    ZMachine.run();
}

void loop()
{
}
