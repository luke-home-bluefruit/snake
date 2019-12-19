#ifndef BUTTON_DRIVER_HPP
#define BUTTON_DRIVER_HPP

#include <vector>
#include <functional>

class ButtonDriver {
public:
  typedef std::function<void()> Callback;
  
  void Task();
  void RegisterKeyPress(int pin, Callback callback);

private:
  struct CallbackMap {
    int pin;
    int currentState;
    Callback callback;
  };
  std::vector<CallbackMap> callbackMaps;
};

#endif
