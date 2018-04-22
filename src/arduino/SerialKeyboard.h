#ifndef __SERIALKEYBOARD_H__
#define __SERIALKEYBOARD_H__

#include <Keyboard.h>

class SerialKeyboardClass : public Keyboard
{
public:
  SerialKeyboardClass();
  ~SerialKeyboardClass();

private:
  SerialKeyboardClass(const SerialKeyboardClass &rhs);
  SerialKeyboardClass &operator=(const SerialKeyboardClass &rhs);
};

extern SerialKeyboardClass SerialKeyboard;

#endif // __SERIALKEYBOARD_H__
