#ifndef MotorController_hpp
#define MotorController_hpp

class MotorController {
  public:
    virtual void init() = 0;
    virtual void setSpeed(int speed) = 0;
    virtual void stop() = 0;
};

#endif
