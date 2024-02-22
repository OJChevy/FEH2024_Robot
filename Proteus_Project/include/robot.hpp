#pragma once

#include "controller.hpp"

class Robot {

    Controller controller;

    public:

        void MoveTowardRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, float speed) {

            controller.SetMotor(leftIGWAN, speed);
            controller.SetMotor(rightIGWAN, speed);

        }

};