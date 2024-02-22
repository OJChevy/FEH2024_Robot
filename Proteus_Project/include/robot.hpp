#pragma once

#include "controller.hpp"

class Robot {

    Controller controller;

    public:

        void MoveTowardRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, float speed) {

            controller.SetMotor(leftIGWAN, speed);
            controller.SetMotor(rightIGWAN, speed);

        }

        void HelloWorld() {

            LCD.Clear();

            LCD.WriteLine("Hello World");

            Sleep(2.0);

        }

        void SystemCheck() {

            LCD.Clear();
            LCD.SetFontColor(WHITE);

            //TODO: GO FORWARD 1 REVOLUTION
            LCD.Write("Go Forward...   ");
            Sleep(5.0);
            LCD.SetFontColor(GREEN);
            LCD.Write("_/");

            LCD.WriteLine("");

            //TODO: GO BACKWARD 1 REVOLUTION
            LCD.SetFontColor(WHITE);
            LCD.Write("Go Backward...   ");
            Sleep(5.0);
            LCD.SetFontColor(GREEN);
            LCD.Write("_/");

            //TODO: TURN RIGHT 90 DEGREES

            //TODO: GO BACK TO CENTER

            //TODO: TURN LEFT 90 DEGREES


            Sleep(2.0);

        }

        void Calibrate() {

            LCD.Clear();

            Sleep(2.0);

        }

        void RunProgressCheck1(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN) {

            //Go forward a little

            //Turn right

            //Go forward

            //Turn left (square up with ramp)

            //Go forward

            //Turn left

            //Turn right (square up with ticket kiosk)

            //Turn left

        }

};