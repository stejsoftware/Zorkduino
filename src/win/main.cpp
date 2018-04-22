#include <iostream>
#include <fstream>

#include <ZMachine.h>
#include <Keyboard.h>
#include <Screen.h>

using namespace std;

class WinKeyboard : public Keyboard
{
public:
  WinKeyboard(){};
  ~WinKeyboard(){};

private:
  WinKeyboard(const WinKeyboard &rhs);
  WinKeyboard &operator=(const WinKeyboard &rhs);
};

class WinScreen : public Screen
{
public:
  WinScreen(){};
  ~WinScreen(){};

  virtual void write(char c)
  {
    cout << c;
  };

private:
  WinScreen(const WinScreen &rhs);
  WinScreen &operator=(const WinScreen &rhs);
};

int main()
{
  const char *filename = "C:\\Projects\\zmachine\\Zorkduino\\stories\\zork1.z3";
  char story[1024 * 512] = {};
  ifstream file(filename);

  //get length of file
  file.seekg(0, file.end);
  size_t length = file.tellg();
  file.seekg(0, file.beg);

  // don't overflow the buffer!
  if (length > sizeof(story))
  {
    length = sizeof(story);
  }

  //read file
  file.read(story, length);

  cout << "file:   " << filename << endl
       << "length: " << length << endl
       << endl;

  WinKeyboard keyboard;
  WinScreen screen;

  ZMachine.setKeyboard(keyboard);
  ZMachine.setScreen(screen);
  ZMachine.loadStory((zbyte_t *)story, (zword_t)length);
  ZMachine.run();
}
