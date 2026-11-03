#ifndef MotorControllerL298_hpp
#define MotorControllerL298_hpp

#include "MotorController.hpp"
#include <Arduino.h>

class MotorControllerL298 : public MotorController {
  private:
    int _dirA;
    int _enable;
    int _dirB;
    bool _reverse;

  public:
    MotorControllerL298(int dirA, int enable, int dirB, bool reverse) {
      _dirA = dirA;
      _enable = enable;
      _dirB = dirB;
      _reverse = reverse;
    }

    void init() override {
      pinMode(_dirA, OUTPUT);
      pinMode(_dirB, OUTPUT);
      pinMode(_enable, OUTPUT);
      stop();
    }

    void setSpeed(int speed) override {
      if (_reverse) speed = -speed;
      
      if (speed > 0) {
        digitalWrite(_dirA, HIGH);
        digitalWrite(_dirB, LOW);
      } else if (speed < 0) {
        digitalWrite(_dirA, LOW);
        digitalWrite(_dirB, HIGH);
        speed = -speed;
      } else {
        digitalWrite(_dirA, LOW);
        digitalWrite(_dirB, LOW);
      }
      
      // Standard analogWrite handles ESP32 PWM automatically on modern IDE cores
      analogWrite(_enable, constrain(abs(speed), 0, 255));
    }

    void stop() override {
      digitalWrite(_dirA, LOW);
      digitalWrite(_dirB, LOW);
      analogWrite(_enable, 0);
    }
};

#endif
