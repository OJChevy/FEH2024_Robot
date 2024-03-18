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

        float radius = 1.50;
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

        //controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 360.0, radius);    

        //Sleep(2.0);

        // Practice turning robot correct degrees
        // Turn right 90 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 90.0, radius);
        // Wait 3 seconds
        Sleep(2.0);
        // Move forward 8 inches
        //controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 4, radius);
        // Move backward 8 inches
        //controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 4, radius);
        // wait 3 secconds
        // Sleep(3.0);
        // Turn left 180 degrees

        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 180.0, radius);
        // Wait 3 seconds
        Sleep(3.0);
        // Turn right 135 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 135.0, radius);
        // Wait 2 seconds
        Sleep(2.0);
        // Turn left 45 degrees
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 45.0, radius);
    }

    void Calibrate(FEHServo &armServo)
    {

        LCD.Clear();

        controller.CalibrateServoArm(armServo);

    }

    void RunProgressCheck1(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        // while (1.0 < cdsSensor.Value())
        // {
        // }

        // float forwardSpeed = -40;     // flipped to make robot go "backwards" (motors in front)
        // float backwardSpeed = 40;     // flipped to make robot go "backwards" (motors in front)
        // float turnSpeedForward = -25; // Lower turn speed to match the predetermined turn lengths
        // float turnSpeedBackward = 25;

        // int rightTurn = 0;
        // int leftTurn = 1;

        // float radius = 1.75;
        // float firstDistance = 30;
        // float secondDistance = 38;

        // int numOfTransitions = 0;

        // // 30 forward straight
        //  controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, firstDistance, radius);

        // // numOfTransitions = controller.ShaftEncoderTransition(30, radius);

        // // // left 45

        //  controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 45, radius);

        // // // forward 10
        //  controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 25, radius);

        // // // right 45
        //  controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

        //  numOfTransitions = controller.ShaftEncoderTransition((TURNDISTANCE90 * 0.5) * 1.45, radius);

        //  rightEncoder.ResetCounts();

        //  while (rightEncoder.Counts() < numOfTransitions)
        // //     ;

        //  controller.StopMotor(leftIGWAN);
        // // controller.StopMotor(rightIGWAN);

        //  // forward (up to the kiosk) until the switch is bumped (trying a do while loop)
        // // // do
        // // // {
        // // //Move straight to kiosk at slower speed to not hurt the wires or bumpswitch
        // // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed * .75);

        // // numOfTransitions = controller.ShaftEncoderTransition(21, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions);
        // // // } while (frontSwitch.Value());

        // controller.StopMotor(leftIGWAN);
        // // controller.StopMotor(rightIGWAN);
        // // // //back 7
        // // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);

        // numOfTransitions = controller.ShaftEncoderTransition(13, radius);

        // rightEncoder.ResetCounts();

        // while (rightEncoder.Counts() < numOfTransitions)
        // //     ;

        // controller.StopMotor(leftIGWAN);
        // // controller.StopMotor(rightIGWAN);
        // // // right 180
        // // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn);

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

            // //Backup 5 inches
            // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed);
            // numOfTransitions = controller.ShaftEncoderTransition(5, radius);
            // rightEncoder.ResetCounts();

            // while (rightEncoder.Counts() < numOfTransitions);

            // controller.StopMotor(leftIGWAN);
            // controller.StopMotor(rightIGWAN);

            // //Turn 135 right
            // controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, rightTurn);
            // numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*1.5, radius);

            // rightEncoder.ResetCounts();

            // while (rightEncoder.Counts() < numOfTransitions);

            // controller.StopMotor(leftIGWAN);
            // controller.StopMotor(rightIGWAN);

            // //Drive forward 20 inches
            // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
            // numOfTransitions = controller.ShaftEncoderTransition(20, radius);
            // rightEncoder.ResetCounts();

            // while (rightEncoder.Counts() < numOfTransitions);

            // controller.StopMotor(leftIGWAN);
            // controller.StopMotor(rightIGWAN);

            // //Turn around 45 degrees right
            // controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn);
            // numOfTransitions = controller.ShaftEncoderTransition(TURNDISTANCE90*0.5, radius);

            // rightEncoder.ResetCounts();

            // while (rightEncoder.Counts() < numOfTransitions);

            // controller.StopMotor(leftIGWAN);
            // controller.StopMotor(rightIGWAN);

            // //Drive forward 30 inches to the end
            // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed);
            // numOfTransitions = controller.ShaftEncoderTransition(30, radius);
            // rightEncoder.ResetCounts();

            // while (rightEncoder.Counts() < numOfTransitions);

            // controller.StopMotor(leftIGWAN);
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

        float degreeTurn = 70;

        // 2. Turn right toward ramp
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, degreeTurn, radius);
    }

    void ProgressCheck2MoveUpRamp(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = -50;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int distance = 28;

        // 3. Move forward up ramp
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, distance, radius);
    }

    void ProgressCheck2MoveTowardLight(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float fastForwardSpeed = -40;
        float slowForwardSpeed = -35;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int firstDistance = 22;

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

        int distance = 20;

        // 6. Move toward luggage
        controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, distance, radius);
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

        int distance = 10;

        // 8. Move toward kiosk
        controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, fastForwardSpeed, slowForwardSpeed, rightTurn, rightEncoder, distance, radius);
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
        // Turn degree for red
        float degreeTurn = 160;
        if (color == 1)
        {
            // Turn degree for blue
            degreeTurn = 145;
        }

        // 9. Turn toward kiosk light given detected color
        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, degreeTurn, radius);
    }
    void ProgressCheck2MoveTowardTicketButton(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {

        float forwardSpeed = 25;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;
        int rightTurn = 0;
        int leftTurn = 1;

        int distance = 6;

        // 10. Move toward ticket kiosk button and press into it
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, distance, radius);
    }

    void ProgressCheck2MoveTowardWhiteButton(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch) {

        float forwardSpeed = 25;
        float backwardSpeed = 40;

        float radius = 1.75;

        int numOfTransitions = 0;

        int rightTurn = 0;
        int leftTurn = 1;

        //TODO: Do some stuff

    }

    void RunProgressCheck2(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch)
    {
        // Start when Red light turns on
        while (1.0 < cdsSensor.Value());

        //Slight turn to the left toward the steep ramp
        ProgressCheck2MoveTowardRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        //Turn right 85 degrees toward the steep ramp
        ProgressCheck2TurnTowardRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        //Move forward **24** inches straight up the steep ramp and a little past
        ProgressCheck2MoveUpRamp(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        //Slight turn right to the light 
        ProgressCheck2MoveTowardLight(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // Collect light value
        int color = 0;
        // Check for Red else, assume blue
        if (0.0 < cdsSensor.Value() < 1.0)
        {
            // Red
            color = 0;
        }
        else
        {
            // Blue
            color = 1;
        }
        // Clear LCD
        LCD.Clear();
        // Display color detected on screen
        if (color == 0)
        {
            LCD.SetFontColor(RED);
        }
        else
        {
            LCD.SetFontColor(BLUE);
        }
        LCD.DrawRectangle(140, 100, 40, 40);
        LCD.FillRectangle(140, 100, 40, 40);
        // // Sleep to check location and see color displayed
        Sleep(5.0);
        // // Left turn ***35*** degrees toward luggage
        // ProgressCheck2TurnTowardLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // // Move backward ***20*** inches toward luggage
        // ProgressCheck2MoveTowardLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // // Square up with luggage by turning
        // ProgressCheck2SquareUpLuggage(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // // Drive forward toward kiosk and turn toward the detected color
        // ProgressCheck2MoveTowardKiosk(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // ProgressCheck2FlipToKiosk(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch, color);
        // // Drive forward to press ticket kiosk button
        // ProgressCheck2MoveTowardTicketButton(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, frontSwitch);
        // Press white boarding pass button
        
        // Backup from kiosk

        // Turn right 135 degrees

        // Drive down ramp
    }

    void ProgressCheck2(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, AnalogInputPin &cdsSensor, DigitalInputPin &frontSwitch) {

        while (2.0 < cdsSensor.Value());

        float slowForwardSpeed = 40;
        float forwardSpeed = 45;     // flipped to make robot go "backwards" (motors in front)
        float backwardSpeed = -45;     // flipped to make robot go "backwards" (motors in front)
        float turnSpeedForward = 25; // Lower turn speed to match the predetermined turn lengths
        float turnSpeedBackward = -25;

        int rightTurn = 1;
        int leftTurn = 0;

        float radius = 1.50;
        float firstDistance = 32;
        float secondDistance = 38;

        int numOfTransitions = 0;

        // 30 forward straight
         controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, forwardSpeed, slowForwardSpeed + 3, rightTurn, rightEncoder, 32.5, radius);

        // numOfTransitions = controller.ShaftEncoderTransition(30, radius);

        // // left 35

        controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 57.8, radius);

        // // forward 27
        controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 24.5, radius);
        
        //Initailize color variable
        int color = 0;
        // Check for Red else, assume blue

        // Sleep on the light to check location and see color displayed
        Sleep(2.0);
        
        // Clear LCD
        LCD.Clear();
        
        // Display color detected on screen
        if (cdsSensor.Value() < 1.0)
        {
            // Red
            color = 0;
            LCD.SetFontColor(RED);
            LCD.DrawRectangle(140, 100, 40, 40);
            LCD.FillRectangle(140, 100, 40, 40);
        }
        else
        {
            // Blue
            color = 1;
            LCD.SetFontColor(BLUE);
            LCD.DrawRectangle(140, 100, 40, 40);
            LCD.FillRectangle(140, 100, 40, 40);
        }
        
        // Sleep on the light to check location and see color displayed
        Sleep(2.0);
        
        //If color is blue
        if (color == 1) {
            //Move backwards 8 inches for blue light
            controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 6, radius);

            ////Turn right 35 degrees to square up to kiosk (same degree turn right as the left turn) (HIT WITH FRONT)
            //controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 35, radius);
            //Turn right 145 degrees to square up to kiosk (same degree turn right as the left turn) (HIT WITH BACK)
            controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 50, radius);
            //Move backward 10 inches to press(IF HIT WITH BACK)
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 6, radius);
            
            // //CODE FOR PRESSING THE WHITE BUTTON (BOARDING PASS BUTTON)
            // //Line up with white button
            // controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, forwardSpeed, slowForwardSpeed, leftTurn, rightEncoder, 10, radius);

            // //Turn in direction of white button
            // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 15, radius);

            // //Go straight toward kiosk
            // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 12, radius);


            //Backup 5 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 5, radius);
   

            //Turn 135 right
            controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, rightTurn, rightEncoder, 135, radius);
     

            //Drive forward 20 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 17, radius);

            //Turn around 45 degrees right
            controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn, rightEncoder, 35 - 7.5, radius);
 

            //Drive forward 30 inches to the end
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 25, radius);

            
        //If color is red
        } else {
            //Move backwards 12 inches for red light
            controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 13.5, radius);
            
            ////Turn right 35 degrees to square up to kiosk (same degree turn right as the left turn) (HIT WITH FRONT)
            //controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 35, radius);
            //Turn right 145 degrees to square up to kiosk (same degree turn right as the left turn) (HIT WITH BACK)
            controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, rightTurn, rightEncoder, 43.5, radius);
            //Move backward 10 inches to press(IF HIT WITH BACK)
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 10, radius);

            // //CODE FOR PRESSING THE WHITE BUTTON (BOARDING PASS BUTTON)
            // //Line up with white button
            // controller.MoveStraightWithSlightTurn(leftIGWAN, rightIGWAN, forwardSpeed, slowForwardSpeed, rightTurn, rightEncoder, 10, radius);

            // //Turn in direction of white button
            // controller.TurnDirection(leftIGWAN, rightIGWAN, turnSpeedForward, turnSpeedBackward, leftTurn, rightEncoder, 15, radius);

            // //Go straight toward kiosk
            // controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 12, radius);


            //Backup 5 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 8, radius);
   

            //Turn 135 right
            controller.TurnDirection(leftIGWAN, rightIGWAN, forwardSpeed, backwardSpeed, rightTurn, rightEncoder, 135, radius);
     

            //Drive forward 20 inches
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 8, radius);

            //Turn around 45 degrees right
            controller.TurnDirection(leftIGWAN,rightIGWAN,forwardSpeed,backwardSpeed,rightTurn, rightEncoder, 35 - 3, radius);
 

            //Drive forward 30 inches to the end
            controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 25, radius);            

        }

        // BREAK FOR DOWN


    }

    void RunProgressCheck3(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, DigitalEncoder &leftEncoder, DigitalEncoder &rightEncoder, FEHServo &armServo) {

        float forwardSpeed = -40;

        float radius = 1.5;

        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 16, radius);
        armServo.SetDegree(0);

        Sleep(3.0);

        armServo.SetDegree(180);



    }

};