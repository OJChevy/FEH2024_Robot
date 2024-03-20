#pragma once

#include "controller.hpp"

#define TURNDISTANCE90 6.385

class Robot
{

    int forward = 0;
    int backward = 1;

    float forwardSpeed = 40;
    float slowForwardSpeed = 35;
    
    float backwardSpeed = -40;
    float slowBackwardSpeed = -35;

    float radius = 1.5;

    int rightTurn = 1;
    int leftTurn = 0;

    std::shared_ptr<FEHMotor> leftIGWAN;
    std::shared_ptr<FEHMotor> rightIGWAN;

    std::shared_ptr<AnalogInputPin> cdsSensor;
    
    std::shared_ptr<DigitalEncoder> leftEncoder;
    std::shared_ptr<DigitalEncoder> rightEncoder;

    std::shared_ptr<FEHServo> armServo;

    Controller controller = Controller(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, 
                                        rightEncoder, armServo, forwardSpeed, slowForwardSpeed, 
                                        backwardSpeed, slowBackwardSpeed, radius, rightTurn, leftTurn);

public:

    //Constructor for Robot class
    Robot(std::shared_ptr<FEHMotor> leftMotor, 
    std::shared_ptr<FEHMotor> rightMotor,
    std::shared_ptr<AnalogInputPin> cds,
    std::shared_ptr<DigitalEncoder> leftEncode,
    std::shared_ptr<DigitalEncoder> rightEncode,
    std::shared_ptr<FEHServo> clawArm) {

        leftIGWAN = leftMotor;
        rightIGWAN = rightMotor;

        cdsSensor = cds;

        leftEncoder = leftEncode;
        rightEncoder = rightEncode;

        armServo = clawArm;

    }

    int displayGUIControl(char menuLabels[4][20]) {

        controller.GUIControl(menuLabels);

    }

    void SystemCheck()
    {

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
        controller.TurnDirection(rightTurn, 90.0);
        // Wait 3 seconds
        Sleep(2.0);
        // Move forward 8 inches
        //controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 4, radius);
        // Move backward 8 inches
        //controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 4, radius);
        // wait 3 secconds
        // Sleep(3.0);
        // Turn left 180 degrees

        controller.TurnDirection(leftTurn, 180.0);
        // Wait 3 seconds
        Sleep(3.0);
        // Turn right 135 degrees
        controller.TurnDirection(rightTurn, 135.0);
        // Wait 2 seconds
        Sleep(2.0);
        // Turn left 45 degrees
        controller.TurnDirection(leftTurn, 45.0);
    }

    void Calibrate(std::shared_ptr<FEHServo> armServo)
    {

        LCD.Clear();

        controller.CalibrateServoArm(armServo);

    }

    void RunProgressCheck3() {

        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 16, radius);
        //RCS.InitializeTouchMenu("B7p93noDy");

        int leverNumber = 0;
        //int leverNumber = RCS.GetCorrectLever();

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value());

        armServo->SetDegree(115);

        switch(leverNumber) {

            case 0:

                controller.MoveStraight(forward, 1);
                controller.MoveStraightWithSlightTurn(forward, 11);

                break;
            
            case 1:

                controller.MoveStraightWithSlightTurn(forward, 16);

                break;

            case 2:

                break;

            default:

                break;

        }

        armServo->SetDegree(145);

        Sleep(7.0);

        armServo->SetDegree(40);



    }

};