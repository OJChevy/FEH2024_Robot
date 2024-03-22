#pragma once

#include "controller.hpp"

#define TURNDISTANCE90 6.385

class Robot
{

    int forward = 0;
    int backward = 1;

    float forwardSpeed = 40;
    float slowForwardSpeed = 38;
    
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

    Controller controller() {

        Controller controller = Controller(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, 
                                    rightEncoder, armServo, forwardSpeed, slowForwardSpeed, 
                                    backwardSpeed, slowBackwardSpeed, radius);

        return controller;

    }

    void MoveTest() {

        // leftIGWAN->SetPercent(25);
        // rightIGWAN->SetPercent(25);

        // Sleep(2.0);

        // leftIGWAN->Stop();
        // rightIGWAN->Stop();

        controller().moveTest();

    }

    /**
     * @author Owen Chevalier
     *
     * Displays and controls the custom GUI on the Proteus display.
     *
     * @param menuLabels
     *      array to store labels for each menu icon
     *
     * @returns an integer value from -1 to 2 that will control different functions of the robot
     *          based on a switch statement in main
     */
    int GUIControl(char menuLabels[4][20])
    {

        int selection = -1;

        float x = 0;
        float y = 0;

        bool actionSelected = false;

        LCD.Clear();

        FEHIcon::Icon menu[4];

        FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menuLabels, RED, WHITE);

        while (actionSelected == false)
        {

            if (LCD.Touch(&x, &y))
            {

                if (menu[0].Pressed(x, y, 0))
                {

                    selection = 0;
                    actionSelected = true;
                }
                else if (menu[1].Pressed(x, y, 0))
                {

                    selection = 1;
                    actionSelected = true;
                }
                else if (menu[2].Pressed(x, y, 0))
                {

                    selection = 2;
                    actionSelected = true;
                }
                else if (menu[3].Pressed(x, y, 0))
                {

                    selection = -1;
                    actionSelected = true;
                }
            }
        }

        return selection;
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
        // controller.TurnDirection(rightTurn, 90.0);
        // // Wait 3 seconds
        // Sleep(2.0);
        // // Move forward 8 inches
        // //controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 4, radius);
        // // Move backward 8 inches
        // //controller.MoveStraight(leftIGWAN, rightIGWAN, backwardSpeed, rightEncoder, 4, radius);
        // // wait 3 secconds
        // // Sleep(3.0);
        // // Turn left 180 degrees

        controller().TurnDirection(leftTurn, 180.0);
        // Wait 3 seconds
        Sleep(3.0);
        // Turn right 135 degrees
        controller().TurnDirection(rightTurn, 135.0);
        // Wait 2 seconds
        Sleep(2.0);
        // Turn left 45 degrees
        controller().TurnDirection(leftTurn, 45.0);
    }

    void Calibrate()
    {

        LCD.Clear();

        armServo->TouchCalibrate();

    }

    void RunProgressCheck3() {

        // controller.MoveStraight(leftIGWAN, rightIGWAN, forwardSpeed, rightEncoder, 16, radius);
        //RCS.InitializeTouchMenu("B7p93noDy");

        int leverNumber = 0;
        //int leverNumber = RCS.GetCorrectLever();

        // Start when Red light turns on
        //while (1.0 < cdsSensor->Value());

        armServo->SetDegree(115);

        switch(leverNumber) {

            case 0:

                controller().MoveStraight(forward, 1);
                controller().MoveStraightWithSlightTurn(forward, 4);

                break;
            
            case 1:

                controller().MoveStraightWithSlightTurn(forward, 16);

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

    void RunProgressCheck4() {

        // armServo->SetDegree(175);
        
        // Sleep(2.0);

        armServo->SetDegree(0);

        //26 inches to the ramp
        controller().MoveStraightWithSlightTurn(leftTurn, 25.5);

        //Turn to square up with ramp
        controller().TurnDirection(leftTurn, 130);

        //21 inches to top of the ramp
        controller().MoveStraight(backward, 28);

        //Turn right 45 degrees
        controller().TurnDirection(rightTurn, 45);

        //22 inches to passport 
        controller().MoveStraight(backward, 22);

    }

};