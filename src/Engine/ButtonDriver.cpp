#include "ButtonDriver.hpp"

#include <Arduino.h>

void ButtonDriver::Task() {
  for (std::size_t i = 0; i < callbackMaps.size(); i++) {
    int pinState = digitalRead(callbackMaps[i].pin);
    if (pinState == callbackMaps[i].currentState)
      continue;

    if (pinState == LOW)
      callbackMaps[i].callback();
    callbackMaps[i].currentState = pinState;
  }
}

void ButtonDriver::RegisterKeyPress(int pin, Callback callback) {
  for (std::size_t i = 0; i < callbackMaps.size(); i++) {
    if (callbackMaps[i].pin != pin)
      continue;
    callbackMaps[i].callback = callback;
    callbackMaps[i].currentState = digitalRead(pin);
    return;
  }

  pinMode(pin, INPUT_PULLUP);
  callbackMaps.push_back( {
    pin,
    digitalRead(pin),
    callback
  });
}
