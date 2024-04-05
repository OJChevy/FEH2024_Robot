#pragma once

#include "controller.hpp"

class Robot
{

    int forward = 0;
    int backward = 1;

    float forwardSpeed = 40;
    float slowForwardSpeed = 36;
    
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
    std::shared_ptr<FEHServo> frontServo;

public:

    //Constructor for Robot class
    Robot(std::shared_ptr<FEHMotor> leftMotor, 
    std::shared_ptr<FEHMotor> rightMotor,
    std::shared_ptr<AnalogInputPin> cds,
    std::shared_ptr<DigitalEncoder> leftEncode,
    std::shared_ptr<DigitalEncoder> rightEncode,
    std::shared_ptr<FEHServo> clawArm,
    std::shared_ptr<FEHServo> frontArmServo) {

        leftIGWAN = leftMotor;
        rightIGWAN = rightMotor;

        cdsSensor = cds;

        leftEncoder = leftEncode;
        rightEncoder = rightEncode;

        armServo = clawArm;
        frontServo = frontArmServo;

    }

    Controller controller() {

        Controller controller = Controller(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, 
                                    rightEncoder, armServo, frontServo, forwardSpeed, slowForwardSpeed, 
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

                    selection = 3;
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

        frontServo->SetDegree(112);

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

    void BatteryLife() {

        bool quitEnabled = false;

        float x;
        float y;

        FEHIcon::Icon backButton;

        backButton.SetProperties("Quit", 219, 189, 100, 50, RED, RED);

        LCD.Clear();

        backButton.Draw();

        while (!quitEnabled) {

            Sleep(0.25);

            float currentBatteryLife = Battery.Voltage();
            float maxBatteryLife = 11.5;
            float batteryPercentage = (currentBatteryLife / maxBatteryLife) * 100.0;

            LCD.WriteAt(batteryPercentage, 0, 0);

            LCD.SetFontColor(WHITE);

            LCD.DrawRectangle(135, 70, 50, 100);

            if (batteryPercentage >= 75) {

                LCD.SetFontColor(GREEN);

                LCD.FillRectangle(136, 71, 49, 99);

            } else if (batteryPercentage < 75 && batteryPercentage >= 50) {

                LCD.SetFontColor(GREEN);

                LCD.FillRectangle(136, 96, 49, 74);

            } else if (batteryPercentage < 50 && batteryPercentage >= 25) {

                LCD.SetFontColor(YELLOW);

                LCD.FillRectangle(136, 121, 49, 49);

            } else if (batteryPercentage < 25) {

                LCD.SetFontColor(RED);

                LCD.FillRectangle(136, 146, 49, 24);

            }

            LCD.WriteAt(batteryPercentage, 0, 0);

            if (LCD.Touch(&x, &y)) {

                if (backButton.Pressed(x, y, 0)) {

                    quitEnabled = true;

                }

            }

        }

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

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value());

        armServo->SetDegree(0);
        frontServo->SetDegree(112);

        //25.5 inches to the ramp
        controller().MoveStraightWithSlightTurn(leftTurn, 25.5);

        //Turn to square up with ramp
        controller().TurnDirection(leftTurn, 130);

        //21 inches to top of the ramp
        controller().MoveStraight(backward, 33.5);

        //Turn right 110 degrees
        controller().TurnDirection(leftTurn, 80);

        frontServo->SetDegree(180);

        //18 inches to passport 
        controller().MoveStraight(forward, 16);

        // //set front servo to *** degree to rotate passport lever up
        frontServo->SetDegree(60);

        Sleep(2.0);

        // //set front servo to *** degree to rotate lever down if stuck up
        frontServo->SetDegree(180);

        // //back up from passport
        // controller().MoveStraight(forward,5);
        
        // //drive forward to passport to try again
        // controller().MoveStraight(backward,5);

    }

    void ArmCheck() {        

        frontServo->SetDegree(180);

        frontServo->SetDegree(60);

        Sleep(2.0);

        frontServo->SetDegree(180);

    }

    void CalibrateArm() {

        frontServo->SetDegree(90);

    }

    void RunProgressCheck5() {

        int leverNumber = -1;

        RCS.InitializeTouchMenu("E7TOyD6Qc");

        armServo->SetDegree(120);
        frontServo->SetDegree(95);

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value()) {

            leverNumber = RCS.GetCorrectLever();

        }

        //Move back to hit button
        controller().MoveStraight(backward, 0.85);

        //Move forward after hitting button
        controller().MoveStraight(forward, 0.85);

        //25.5 inches to the ramp
        controller().MoveStraightWithSlightTurn(leftTurn, 25.75);

        //Turn to square up with ramp
        controller().TurnDirection(leftTurn, 130);

        //21 inches to top of the ramp
        controller().MoveStraight(backward, 30.5);

        controller().TurnDirection(leftTurn, 60);

        controller().MoveStraight(forward, 8.5);

        controller().TurnDirection(rightTurn, 65);

        controller().MoveStraight(forward, 5);

        forwardSpeed = 55;

        controller().MoveStraight(forward, 2);

        forwardSpeed = 40;

        armServo->SetDegree(0);

        Sleep(3.0);

        controller().MoveStraight(backward, 2);

        controller().TurnDirection(leftTurn, 60);

        controller().MoveStraight(forward, 13.5);

        controller().TurnDirection(rightTurn, 65);

        frontServo->SetDegree(180);

        controller().MoveStraightWithSlightTurn(rightTurn, 31.5);

        controller().TurnDirection(leftTurn, 15);

    }

    void SmallProgressCheck5() {

        int leverNumber = -1;

        RCS.InitializeTouchMenu("E7TOyD6Qc");

        armServo->SetDegree(0);
        frontServo->SetDegree(112);

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value()) {

            leverNumber = RCS.GetCorrectLever();

        }

        //Move back to hit button
        controller().MoveStraight(backward, 0.85);

        //Move forward after hitting button
        controller().MoveStraight(forward, 0.85);

        controller().MoveStraight(forward, 11);

        controller().TurnDirection(rightTurn, 40);

        frontServo->SetDegree(0);

        controller().MoveStraight(forward, 9);

        Sleep(2.0);

        controller().MoveStraight(backward, 8);

        controller().TurnDirection(leftTurn, 25);

        controller().MoveStraight(backward, 8);

        controller().MoveStraight(backward, 0.85);

    }

    void ServoTest() {

        frontServo->SetDegree(95);

        while(true);

        armServo->SetDegree(180);

        Sleep(5.0);

        armServo->SetDegree(120);

        Sleep(2.0);

        armServo->SetDegree(0);

    }

};