#pragma once

#include "controller.hpp"

#define TURNDISTANCE90 5.5875

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

        void SystemCheck(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder) {

            float forwardSpeed = 25;
            float backwardSpeed = -25;

            LCD.Clear();
            LCD.SetFontColor(WHITE);

            //TODO: GO FORWARD 1 REVOLUTION
            LCD.Write("Go Forward...   ");
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN, forwardSpeed);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < 318);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            LCD.SetFontColor(GREEN);
            LCD.Write("_/");

            Sleep(1.0);

            LCD.WriteLine("");

            //TODO: GO BACKWARD 1 REVOLUTION
            LCD.SetFontColor(WHITE);
            LCD.Write("Go Backward...   ");

            controller.SetMotor(leftIGWAN, backwardSpeed);
            controller.SetMotor(rightIGWAN, backwardSpeed);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < 318);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            LCD.SetFontColor(GREEN);
            LCD.Write("_/");

            Sleep(1.0);

            //TODO: TURN RIGHT 90 DEGREES

            //TODO: GO BACK TO CENTER

            //TODO: TURN LEFT 90 DEGREES


            Sleep(2.0);

        }

        void Calibrate() {

            LCD.Clear();

            Sleep(2.0);

        }

        void RunProgressCheck1(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder) {

            float forwardSpeed = 25;
            float backwardSpeed = -25;


            float radius = 1.25;
            float firstDistance = 1;
            float secondDistance = 38;

            int numOfTransitions = 0;

            //Go forward 2 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(firstDistance, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            //Turn right 45 degrees
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN, backwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Turn left 45 degrees
            controller.SetMotor(leftIGWAN, backwardSpeed);
            controller.SetMotor(rightIGWAN, forwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

            leftEncoder.ResetCounts();

            while (leftEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Turn right 45 degrees
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN, backwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);


            //Go forward 38 inches (up ramp and 10 inches past ramp)
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(secondDistance, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);


            //Turn left 45 degrees
            controller.SetMotor(leftIGWAN, backwardSpeed);
            controller.SetMotor(rightIGWAN, forwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

            leftEncoder.ResetCounts();

            while (leftEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Go forward 12 inches to touch kiosk
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN, forwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(12, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);
            
            //Turn right (square up with ticket kiosk) **ADJUST THE ANGLE BASED ON THE CASTER WHEELS**
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN, backwardSpeed);

            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.65, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Drive straight 10 inches to touch the kiosk
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(10, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Backup 5 inches 
            controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(5, radius);
            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Turn 135 right
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN,backwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*1.5, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Drive forward 20 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(20, radius);
            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);

            //Turn around 45 degrees right
            controller.SetMotor(leftIGWAN, forwardSpeed);
            controller.SetMotor(rightIGWAN,backwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*0.5, radius);

            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);
            
            //Drive forward 30 inches to the end
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
            numOfTransitions = controller.ShaftEncoderTransition(30, radius);
            rightEncoder.ResetCounts();

            while (rightEncoder.Counts() < numOfTransitions);

            controller.StopMotor(leftIGWAN);
            controller.StopMotor(rightIGWAN);
        }

};