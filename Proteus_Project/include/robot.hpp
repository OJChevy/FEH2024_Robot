#pragma once

#include "controller.hpp"

#define TURNDISTANCE90 6.385

class Robot
{

    Controller controller;

public:
    void HelloWorld()
    {

        LCD.Clear();

        LCD.WriteLine("Hello World");

        Sleep(2.0);
    }

    void SystemCheck(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder)
    {

        float forwardSpeed = -35;
        float backwardSpeed = 35;
        float turnSpeedForward = -35; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 35;

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

        // Practice turning robot correct degrees
        // Turn right 90 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 90, radius);
        // Wait 3 seconds
        Sleep(2.0);
        // Move forward 8 inches
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 8, radius);
        // Move backward 8 inches
        controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 8, radius);
        // wait 3 secconds
        Sleep(3.0);
        // Turn left 180 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 180, radius);
        // Wait 3 seconds
        Sleep(3.0);
        // Turn right 135 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 135, radius);
        // Wait 2 seconds
        Sleep(2.0);
        // Turn left 45 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 45, radius);
    }

    void Calibrate()
    {

        LCD.Clear();

        Sleep(2.0);
    }

    void RunProgressCheck1(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        while (1.0 < cdsSensor.Value())
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
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(30, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // // left 45
        // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn);

        // numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.5, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // forward 10
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(10, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // right 45
        // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        // numOfTransitions = controller.ShaftEncoderTransition((TURNDISTANCE90 * 0.5) * 1.45, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // forward (up to the kiosk) until the switch is bumped (trying a do while loop)
        // // do
        // // {
        // //Move straight to kiosk at slower speed to not hurt the wires or bumpswitch
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed * .75);

        // numOfTransitions = controller.ShaftEncoderTransition(21, radius);

        // //rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions);
        // // } while (frontSwitch.Value());

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);
        // // //back 7
        // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(13, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);
        // // right 180
        // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        // numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 1.3, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // //forward 15
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(16.5, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // right 20
        // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        // numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90 * 0.575, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

        // // forward 31
        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(31, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        //     ;

        // controller.StopMotor(leftIGWAN);
        // controller.StopMotor(rightIGWAN);

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

    /**
     * PROGRESS CHECK 2 CODE
     */

    void ProgressCheck2MoveTowardRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float fastForwardSpeed = -40;
        float slowForwardSpeed = -35;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int firstDistance = 20;

        // 1. Move forward with slight turn from start box
        controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, fastForwardSpeed, slowForwardSpeed, leftTurn, rightEncoder, firstDistance, radius);
    }

    void ProgressCheck2TurnTowardRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -40;
        float backwardSpeed = 40;
        float turnSpeedForward = -35; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 35;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        float degreeTurn = 80;

        // 2. Turn right toward ramp
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, degreeTurn, radius);
    }

    void ProgressCheck2MoveUpRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -55;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int moveUpRampDistance = 24;

        // 3. Move forward up ramp
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, moveUpRampDistance, radius);
    }

    void ProgressCheck2MoveTowardLight(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float fastForwardSpeed = -40;
        float slowForwardSpeed = -32;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int firstDistance = 24;

        // 4. Move forward with slight turn from to detect light
        controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, fastForwardSpeed, slowForwardSpeed, rightTurn, rightEncoder, firstDistance, radius);
    }

    void ProgressCheck2TurnTowardLuggage(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -40;
        float backwardSpeed = 40;
        float turnSpeedForward = -35; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 35;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        float degreeTurn = 35;

        // 5. Turn toward luggage
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, degreeTurn, radius);
    }

    void ProgressCheck2MoveTowardLuggage(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -40;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int moveUpRampDistance = 20;

        // 6. Move toward luggage
        controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, moveUpRampDistance, radius);
    }

        void ProgressCheck2SquareUpLuggage(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -40;
        float backwardSpeed = 40;
        float turnSpeedForward = -35; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 35;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        float degreeTurn = 22.5;

        // 7. Square up with luggage
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, degreeTurn, radius);
    }

        void ProgressCheck2MoveTowardKiosk(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float fastForwardSpeed = -40;
        float slowForwardSpeed = -35;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int moveUpRampDistance = 10;

        // 6. Move toward luggage
        controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, fastForwardSpeed, slowForwardSpeed, rightTurn, rightEncoder, moveUpRampDistance, radius);
    }
        void ProgressCheck2FlipToKiosk(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch, int color)
    {

        float forwardSpeed = -40;
        float backwardSpeed = 40;
        float turnSpeedForward = -35; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = 35;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;
        float degreeTurn = 160;
        if (color == 1) {
            degreeTurn = 145;
        }

        // 7. Square up with kiosk
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, degreeTurn, radius);
    }





    void RunProgressCheck2(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        ProgressCheck2MoveTowardRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // turn right 85 degrees
        ProgressCheck2TurnTowardRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // move forward **24** inches straight
        ProgressCheck2MoveUpRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // slight turn right to the light
        ProgressCheck2MoveTowardLight(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        //Sleep to check location
        Sleep(5.0);
        //collect light value
        int color = 0;
        if (1.0 < cdsSensor.Value()) {
            //red
            color = 0;
        } else {
            //blue
            color = 1;
        }
        // left turn 35 degrees
        ProgressCheck2TurnTowardLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // move backward 20 inches toward luggage
        ProgressCheck2MoveTowardLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // square up with luggage?
        ProgressCheck2SquareUpLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // drive forward toward kiosk
        ProgressCheck2MoveTowardKiosk(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        ProgressCheck2FlipToKiosk(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch, color);
        // backup from kiosk

        // turn right 135 degrees

        // drive down ramp
    }
};