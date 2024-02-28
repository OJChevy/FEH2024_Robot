#pragma once

#include "controller.hpp"

#define TURNDISTANCE90 6.385

class Robot
{

    Controller controller;

public:
    void MoveTowardRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, float speed)
    {

        controller.SetMotor(leftIGWAN, speed);
        controller.SetMotor(rightIGWAN, speed);
    }

    void HelloWorld()
    {

        LCD.Clear();

        LCD.WriteLine("Hello World");

        Sleep(2.0);
    }

    void SystemCheck(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder)
    {

        float forwardSpeed = -25;
        float backwardSpeed = 25;
        float turnSpeedForward = -25; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 25;

        int rightTurn = 0;
        int leftTurn = 1;

        float radius = 1.75;
        float firstDistance = 1;
        float secondDistance = 38;

        int numOfTransitions = 0;

        // LCD.Clear();
        // LCD.SetFontColor(WHITE);

        // // TODO: GO FORWARD 1 REVOLUTION
        // LCD.Write("Go Forward...   ");
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < 318)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // LCD.SetFontColor(GREEN);
        // LCD.Write("_/");

        // Sleep(1.0);

        // LCD.WriteLine("");

        // // TODO: GO BACKWARD 1 REVOLUTION
        // LCD.SetFontColor(WHITE);
        // LCD.Write("Go Backward...   ");

        // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < 318)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // LCD.SetFontColor(GREEN);
        // LCD.Write("_/");

        // Sleep(1.0);

        // // TODO: TURN RIGHT 90 DEGREES

        // // TODO: GO BACK TO CENTER

        // // TODO: TURN LEFT 90 DEGREES

        // Sleep(2.0);

        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions);

        // left 45

        controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, leftTurn);

        numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // move forward
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions);

        // right 45

        controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, rightTurn);

        numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // move forward
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions);

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

    }

    void Calibrate()
    {

        LCD.Clear();

        Sleep(2.0);
    }

    void RunProgressCheck1(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        while (.85 < cdsSensor.Value())
        {
        }

        float forwardSpeed = -40;     // flipped to make robot go "backwards" (motors in front)
        float backwardSpeed = 40;     // flipped to make robot go "backwards" (motors in front)
        float turnSpeedForward = -25; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 25;

        int rightTurn = 0;
        int leftTurn = 1;

        float radius = 1.75;
        float firstDistance = 1;
        float secondDistance = 38;

        int numOfTransitions = 0;

        // 30 forward straight
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(30, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        // left 45
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn);

        numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // forward 10
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // right 45
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        numOfTransitions = controller.ShaftEncoderTransition((TURNDISTANCE90 * 0.5) * 1.45, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // forward (up to the kiosk) until the switch is bumped (trying a do while loop)
        // do
        // {
        //Move straight to kiosk at slower speed to not hurt the wires or bumpswitch
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed * .75);

        numOfTransitions = controller.ShaftEncoderTransition(16, radius);

        //rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions);
        // } while (frontSwitch.Value());

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);
        // //back 7
        controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(8, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);
        // right 180
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 1.3, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // //forward 15
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(17.5, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // right 20
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.55, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // forward 31
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        numOfTransitions = controller.ShaftEncoderTransition(31, radius);

        rightEncoder.ResetCounts();

        while (rightEncoder.Counts() < numOfTransitions)
            ;

        controller.StopMotor(leftIGWAN);
        controller.StopMotor(rightIGWAN);

        // Increment run count

        //***PATH 2 ATTEMPT WITH WEIRD TURNS LEFT RIGHT LEFT AT BEGINNING***

        //     //Go forward 2 inches
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        //     numOfTransitions = controller.ShaftEncoderTransition(firstDistance, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     //Turn right 45 degrees
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn);

        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn left 45 degrees
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,leftTurn);

        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        //     leftEncoder.ResetCounts();

        //     while (leftEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn right 45 degrees
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn);

        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Go forward 38 inches (up ramp and 10 inches past ramp)
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        //     numOfTransitions = controller.ShaftEncoderTransition(secondDistance, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn left 45 degrees
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,leftTurn);
        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        //     leftEncoder.ResetCounts();

        //     while (leftEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Go forward 12 inches to touch kiosk
        //     controller.MoveStraight(leftIGWAN,rightIGWAN,forwardSpeed);

        //     numOfTransitions = controller.ShaftEncoderTransition(12, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn right (square up with ticket kiosk) **ADJUST THE ANGLE BASED ON THE CASTER WHEELS**
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn);

        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Drive straight 10 inches to touch the kiosk
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
        //     numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Backup 5 inches
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);
        //     numOfTransitions = controller.ShaftEncoderTransition(5, radius);
        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn 135 right
        //     controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, rightTurn);
        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*1.5, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Drive forward 20 inches
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
        //     numOfTransitions = controller.ShaftEncoderTransition(20, radius);
        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Turn around 45 degrees right
        //     controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn);
        //     numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*0.5, radius);

        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);

        //     //Drive forward 30 inches to the end
        //     controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
        //     numOfTransitions = controller.ShaftEncoderTransition(30, radius);
        //     rightEncoder.ResetCounts();

        //     while (rightEncoder.Counts() < numOfTransitions);

        //     controller.StopMotor(leftIGWAN);
        //     controller.StopMotor(rightIGWAN);
    }
};