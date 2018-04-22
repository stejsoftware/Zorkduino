#ifndef __SERIALSCREEN_H__
#define __SERIALSCREEN_H__

#include <Screen.h>

class SerialScreenClass : public Screen
{
public:
  SerialScreenClass();
  ~SerialScreenClass();

  virtual void write(char c);

private:
  SerialScreenClass(const SerialScreenClass &rhs);
  SerialScreenClass &operator=(const SerialScreenClass &rhs);
};

extern SerialScreenClass SerialScreen;

#endif // __SERIALSCREEN_H__
