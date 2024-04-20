#pragma once

#include "controller.hpp"

class Robot
{

    int forward = 0;
    int backward = 1;

    float forwardSpeed = 40;
    float slowForwardSpeed = 36;
    
    float backwardSpeed = -40;
    float slowBackwardSpeed = -36;

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

        controller().MoveStraight(backward, 5);

        controller().MoveStraight(forward, 5);

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

    void finalRun() {

        int leverNumber = 0;

        armServo->SetDegree(120);
        frontServo->SetDegree(95);

        //RCS.InitializeTouchMenu("E7TOyD6Qc");

        Sleep(2.0);

        //Hit start button
        controller().MoveStraight(forward, 0.5);
        controller().MoveStraight(backward, 0.5);

        switch(leverNumber) {

            case 0:

                controller().MoveStraightWithSlightTurnBackward(leftTurn, 15);

                controller().TurnDirection(rightTurn, 35);

                frontServo->SetDegree(160);

                controller().MoveStraight(forward, 2.5);

                frontServo->SetDegree(175);

                controller().MoveStraight(backward, 3.8);

                frontServo->SetDegree(95);

                controller().TurnDirection(leftTurn, 65);

                controller().MoveStraight(backward, 8.5);

                leftIGWAN->SetPercent(25);
                rightIGWAN->SetPercent(-25);

                Sleep(2.0);

                controller().StopBothMotors();

                controller().MoveStraight(forward, 2);

                controller().TurnDirection(rightTurn, 65);

                break;

            case 1:

                break;

            case 2:
            
                break;

        }

        //21 inches to top of the ramp
        controller().MoveStraight(backward, 32.5);

        controller().TurnDirection(leftTurn, 60);

        controller().MoveStraight(forward, 8.5);

        controller().TurnDirection(rightTurn, 65);

        controller().MoveStraight(forward, 5);

        forwardSpeed = 55;

        controller().MoveStraight(forward, 2);

        forwardSpeed = 40;

        armServo->SetDegree(0);

        Sleep(2.0);

        controller().MoveStraight(backward, 12);

        controller().TurnDirection(leftTurn, 20);

        controller().MoveStraight(backward, 8);

    }

    void finalRun2() {

        int leverNumber = 0;

        armServo->SetDegree(120);
        frontServo->SetDegree(95);

        //RCS.InitializeTouchMenu("E7TOyD6Qc");

        Sleep(2.0);

        // Hit start button
        controller().MoveStraight(forward, 0.5);
        controller().MoveStraight(backward, 0.5);

                switch(leverNumber) {

            case 0:

                //controller().MoveStraightWithSlightTurnBackward(leftTurn, 15);

                controller().MoveStraight(backward, 10);

                frontServo->SetDegree(160);

                controller().TurnDirection(rightTurn, 40);

                //controller().MoveStraight(forward, 2.5);

                frontServo->SetDegree(175);

                controller().MoveStraight(backward, 2.5);

                frontServo->SetDegree(95);

                controller().TurnDirection(leftTurn, 65);

                controller().MoveStraight(forward, 10);

                controller().StopBothMotors();

                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(1.5);

                controller().StopBothMotors();

                controller().MoveStraight(backward, 0.5);

                controller().TurnDirection(rightTurn, 80);

                controller().MoveStraight(backward, 30);

                // controller().MoveStraight(backward, 8.5);

                // leftIGWAN->SetPercent(25);
                // rightIGWAN->SetPercent(-25);

                // Sleep(2.0);

                // controller().StopBothMotors();

                // controller().MoveStraight(forward, 2);

                //controller().TurnDirection(rightTurn, 65);

                break;

            case 1:

                break;

            case 2:
            
                break;

        }

        // // Go up small ramp
        // controller().TurnDirection(rightTurn, 35);
        // controller().MoveStraight(backward, 20);

        // Drive to read light
        controller().TurnDirection(leftTurn, 35);
        controller().MoveStraight(backward, 18);

        // Read light
        // ** Code to read light **
        // Sleep to read light
        // lightColor = ** what value we read **

    //     // Drive to luggage
    //     controller().MoveStraight(forward, 10);
    //     controller().TurnDirection(rightTurn, 35);
    //     controller().MoveStraight(forward, 4);

    //     // Drop luggage
    //     armServo->SetDegree(0);
    //     Sleep(2.0);
        
        // // Drive to light
        // // if light is red
        // controller().MoveStraight(backward, 10);
        // controller().TurnDirection(rightTurn, 180);
        // // potentially lower the forward drive speed for the light to limit movement
        // controller().MoveStraight(forward, 4);
        // // set frontServo for pressing red or blue button
        // frontServo->SetDegree(145);
        // // set armServo for pressing white button
        // armServo->SetDegree(125);

    //     // Drive to passport
    //     controller().MoveStraight(backward, 12);
    //     controller().TurnDirection(leftTurn, 90);

    //     // Reset frontServo for passport lever
    //     controller().MoveStraight(forward, 5);
    //     frontServo->SetDegree(95);

    //     // Flip passport
    //     // lower the drive speed for moving forward
    //     controller().MoveStraight(forward, 3);
     }

     void finalRun3() {

        armServo->SetDegree(120);
        frontServo->SetDegree(95);

        controller().TurnDirection(leftTurn, 15);

        Sleep(0.5);

        controller().TurnDirection(rightTurn, 15);

        controller().MoveStraight(backward, 32);

        controller().TurnDirection(leftTurn, 15);

        controller().MoveStraight(backward, 26);

        Sleep(3.0);

        controller().MoveStraight(forward, 8);

        controller().TurnDirection(rightTurn, 25);

        controller().MoveStraight(forward, 8);

        // Drop luggage
        armServo->SetDegree(0);
        Sleep(2.0);    

        // Drive to light
        // if light is red
        controller().MoveStraight(backward, 10);
        controller().TurnDirection(rightTurn, 145);
        // potentially lower the forward drive speed for the light to limit movement
        controller().MoveStraight(forward, 4);
        // set frontServo for pressing red or blue button
        frontServo->SetDegree(145);
        // set armServo for pressing white button
        armServo->SetDegree(125);

     }

     void finalRun4A() {

        int color = 0;
        int currentRegion = 0;
        int leverNumber = 0;

        armServo->SetDegree(120);
        frontServo->SetDegree(95);

        RCS.InitializeTouchMenu("E7TOyD6Qc");

        currentRegion = RCS.CurrentRegion();

        LCD.Clear();

        LCD.WriteLine(currentRegion);

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value()) {

            leverNumber = RCS.GetCorrectLever();

        }

        switch(currentRegion) {

            case 0:

                // Hit start button
                controller().MoveStraight(forward, 1);
                controller().MoveStraight(backward, 1);

                controller().MoveStraight(backward, 10);

                controller().TurnDirection(leftTurn, 22);

                controller().MoveStraight(forward, 8);

                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                controller().TurnDirection(rightTurn, 84);

                //backwardSpeed = -50;

                controller().MoveStraight(backward, 26);

                //backwardSpeed = -40;

                //Pos: At top of ramp, move toward light
                controller().TurnDirection(leftTurn, 15.5);

                controller().MoveStraight(backward, 25);

                //Pos: At top of ramp, move toward light
                // controller().TurnDirection(leftTurn, 30);

                // controller().MoveStraight(backward, 26);

                //TODO: Read light
                Sleep(3.0);

                //Move forward from light, and position at luggage drop
                controller().MoveStraight(forward, 6);

                controller().TurnDirection(rightTurn, 39);

                controller().MoveStraight(forward, 14);

                // Drop luggage
                armServo->SetDegree(0);

                //Sleep
                Sleep(2.0);  

                //Rotate and get in position for kiosk buttons
                controller().MoveStraight(backward, 2);

                controller().TurnDirection(rightTurn, 95);

                controller().MoveStraight(backward, 5);

                controller().TurnDirection(rightTurn, 95);

                //Rotate front servo according to light read
                switch(color) {

                    //If red,
                    case 0:

                        frontServo->SetDegree(162);

                        break;

                    //If blue,
                    case 1:

                        frontServo->SetDegree(65);

                        break;

                    default:

                        frontServo->SetDegree(0);
                        break;

                }

                //Move toward kiosk buttons
                controller().MoveStraight(forward, 11);

                //Back up
                controller().MoveStraight(backward, 2);

                Sleep(0.5);

                //Second attempt at pressing kiosk button moving slower this time
                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                //Back up for passport
                controller().MoveStraight(backward, 1.5);

                //Reset servos to original position
                frontServo->SetDegree(95);
                armServo->SetDegree(120);

                //Rotate towards kiosk
                controller().TurnDirection(rightTurn, 75);

                //Move back to make way for front servo positioning
                controller().MoveStraight(backward, 2);

                //Set servo for passport flip
                frontServo->SetDegree(180);

                //Sleep to check positioning
                Sleep(2.0);

                //Move forward to get under passport lever (maybe back to 1.5)
                controller().MoveStraight(forward, 2);

                //Move servo up to flip passport lever
                frontServo->SetDegree(60);

                Sleep(1.0);

                //Flip servo back down to bring passport lever back down
                frontServo->SetDegree(180);

                Sleep(1.0);

                //Begin moving to steep ramp
                controller().MoveStraight(backward, 14);

                controller().TurnDirection(leftTurn, 55);

                controller().MoveStraight(backward, 34);

                switch (leverNumber) {

                    case 0:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 8.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(135);

                        controller().TurnDirection(leftTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 1:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 4.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 5);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 2:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 2.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 7);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    default:

                        break;

                }

                break;

            case 1:

                // Hit start button
                controller().MoveStraight(forward, 1);
                controller().MoveStraight(backward, 1);

                controller().MoveStraight(backward, 10);

                controller().TurnDirection(leftTurn, 22);

                controller().MoveStraight(forward, 8);

                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                controller().TurnDirection(rightTurn, 83);

                //backwardSpeed = -50;

                controller().MoveStraight(backward, 26);

                //backwardSpeed = -40;

                //Pos: At top of ramp, move toward light
                controller().TurnDirection(leftTurn, 15.5);

                controller().MoveStraight(backward, 25);

                //Pos: At top of ramp, move toward light
                // controller().TurnDirection(leftTurn, 30);

                // controller().MoveStraight(backward, 26);

                //TODO: Read light
                Sleep(3.0);

                //Move forward from light, and position at luggage drop
                controller().MoveStraight(forward, 6);

                controller().TurnDirection(rightTurn, 39);

                controller().MoveStraight(forward, 14);

                // Drop luggage
                armServo->SetDegree(0);

                //Sleep
                Sleep(2.0);  

                //Rotate and get in position for kiosk buttons
                controller().MoveStraight(backward, 2);

                controller().TurnDirection(rightTurn, 95);

                controller().MoveStraight(backward, 4.5);

                controller().TurnDirection(rightTurn, 95);

                //Rotate front servo according to light read
                switch(color) {

                    //If red,
                    case 0:

                        frontServo->SetDegree(162);

                        break;

                    //If blue,
                    case 1:

                        frontServo->SetDegree(65);

                        break;

                    default:

                        frontServo->SetDegree(0);
                        break;

                }

                //Move toward kiosk buttons
                controller().MoveStraight(forward, 11);

                //Back up
                controller().MoveStraight(backward, 2);

                Sleep(0.5);

                //Second attempt at pressing kiosk button moving slower this time
                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                //Back up for passport
                controller().MoveStraight(backward, 1.5);

                //Reset servos to original position
                frontServo->SetDegree(95);
                armServo->SetDegree(120);

                //Rotate towards kiosk
                controller().TurnDirection(rightTurn, 75);

                //Move back to make way for front servo positioning
                controller().MoveStraight(backward, 2);

                //Set servo for passport flip
                frontServo->SetDegree(180);

                //Sleep to check positioning
                Sleep(2.0);

                //Move forward to get under passport lever (maybe back to 1.5)
                controller().MoveStraight(forward, 2);

                //Move servo up to flip passport lever
                frontServo->SetDegree(60);

                Sleep(1.0);

                //Flip servo back down to bring passport lever back down
                frontServo->SetDegree(180);

                Sleep(1.0);

                //Begin moving to steep ramp
                controller().MoveStraight(backward, 14);

                controller().TurnDirection(leftTurn, 55);

                controller().MoveStraight(backward, 34);

                switch (leverNumber) {

                    case 0:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 8.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(135);

                        controller().TurnDirection(leftTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 1:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 4.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 5);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 2:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 2.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 7);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    default:

                        break;

                }

                break;

            case 2:

                // Hit start button
                controller().MoveStraight(forward, 1);
                controller().MoveStraight(backward, 1);

                controller().MoveStraight(backward, 10);

                controller().TurnDirection(leftTurn, 22);

                controller().MoveStraight(forward, 8);

                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                controller().TurnDirection(rightTurn, 84);

                //backwardSpeed = -50;

                controller().MoveStraight(backward, 26);

                //backwardSpeed = -40;

                //Pos: At top of ramp, move toward light
                controller().TurnDirection(leftTurn, 15.5);

                controller().MoveStraight(backward, 25);

                //Pos: At top of ramp, move toward light
                // controller().TurnDirection(leftTurn, 30);

                // controller().MoveStraight(backward, 26);

                //TODO: Read light
                Sleep(3.0);

                //Move forward from light, and position at luggage drop
                controller().MoveStraight(forward, 6);

                controller().TurnDirection(rightTurn, 39);

                controller().MoveStraight(forward, 14);

                // Drop luggage
                armServo->SetDegree(0);

                //Sleep
                Sleep(2.0);  

                //Rotate and get in position for kiosk buttons
                controller().MoveStraight(backward, 2);

                controller().TurnDirection(rightTurn, 95);

                controller().MoveStraight(backward, 4.5);

                controller().TurnDirection(rightTurn, 95);

                //Rotate front servo according to light read
                switch(color) {

                    //If red,
                    case 0:

                        frontServo->SetDegree(162);

                        break;

                    //If blue,
                    case 1:

                        frontServo->SetDegree(65);

                        break;

                    default:

                        frontServo->SetDegree(0);
                        break;

                }

                //Move toward kiosk buttons
                controller().MoveStraight(forward, 11);

                //Back up
                controller().MoveStraight(backward, 2);

                Sleep(0.5);

                //Second attempt at pressing kiosk button moving slower this time
                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                //Back up for passport
                controller().MoveStraight(backward, 1.5);

                //Reset servos to original position
                frontServo->SetDegree(95);
                armServo->SetDegree(120);

                //Rotate towards kiosk
                controller().TurnDirection(rightTurn, 75);

                //Move back to make way for front servo positioning
                controller().MoveStraight(backward, 2);

                //Set servo for passport flip
                frontServo->SetDegree(180);

                //Sleep to check positioning
                Sleep(2.0);

                //Move forward to get under passport lever (maybe back to 1.5)
                controller().MoveStraight(forward, 2);

                //Move servo up to flip passport lever
                frontServo->SetDegree(60);

                Sleep(1.0);

                //Flip servo back down to bring passport lever back down
                frontServo->SetDegree(180);

                Sleep(1.0);

                //Begin moving to steep ramp
                controller().MoveStraight(backward, 14);

                controller().TurnDirection(leftTurn, 55);

                controller().MoveStraight(backward, 34);

                switch (leverNumber) {

                    case 0:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 8.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(135);

                        controller().TurnDirection(leftTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 1:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 4.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 5);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 2:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 2.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 7);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    default:

                        break;

                }

                break;

            case 3:

                // Hit start button
                controller().MoveStraight(forward, 1);
                controller().MoveStraight(backward, 1);

                controller().MoveStraight(backward, 10);

                controller().TurnDirection(leftTurn, 22);

                controller().MoveStraight(forward, 8);

                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                controller().TurnDirection(rightTurn, 84);

                //backwardSpeed = -50;

                controller().MoveStraight(backward, 26);

                //backwardSpeed = -40;

                //Pos: At top of ramp, move toward light
                controller().TurnDirection(leftTurn, 15.5);

                controller().MoveStraight(backward, 25);

                //Pos: At top of ramp, move toward light
                // controller().TurnDirection(leftTurn, 30);

                // controller().MoveStraight(backward, 26);

                //TODO: Read light
                Sleep(3.0);

                //Move forward from light, and position at luggage drop
                controller().MoveStraight(forward, 6);

                controller().TurnDirection(rightTurn, 25);

                controller().MoveStraight(forward, 14);

                // Drop luggage
                armServo->SetDegree(0);

                //Sleep
                Sleep(2.0);  

                //Rotate and get in position for kiosk buttons
                controller().MoveStraight(backward, 2);

                controller().TurnDirection(rightTurn, 95);

                controller().MoveStraight(backward, 4.5);

                controller().TurnDirection(rightTurn, 95);

                //Rotate front servo according to light read
                switch(color) {

                    //If red,
                    case 0:

                        frontServo->SetDegree(162);

                        break;

                    //If blue,
                    case 1:

                        frontServo->SetDegree(65);

                        break;

                    default:

                        frontServo->SetDegree(0);
                        break;

                }

                //Move toward kiosk buttons
                controller().MoveStraight(forward, 11);

                //Back up
                controller().MoveStraight(backward, 2);

                Sleep(0.5);

                //Second attempt at pressing kiosk button moving slower this time
                leftIGWAN->SetPercent(-20);
                rightIGWAN->SetPercent(20);

                Sleep(2.0);

                controller().StopBothMotors();

                //Back up for passport
                controller().MoveStraight(backward, 1.5);

                //Reset servos to original position
                frontServo->SetDegree(95);
                armServo->SetDegree(120);

                //Rotate towards kiosk
                controller().TurnDirection(rightTurn, 75);

                //Move back to make way for front servo positioning
                controller().MoveStraight(backward, 2);

                //Set servo for passport flip
                frontServo->SetDegree(180);

                //Sleep to check positioning
                Sleep(2.0);

                //Move forward to get under passport lever (maybe back to 1.5)
                controller().MoveStraight(forward, 2);

                //Move servo up to flip passport lever
                frontServo->SetDegree(60);

                Sleep(1.0);

                //Flip servo back down to bring passport lever back down
                frontServo->SetDegree(180);

                Sleep(1.0);

                //Begin moving to steep ramp
                controller().MoveStraight(backward, 14);

                controller().TurnDirection(leftTurn, 55);

                controller().MoveStraight(backward, 34);

                switch (leverNumber) {

                    case 0:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 8.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(135);

                        controller().TurnDirection(leftTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 1:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 4.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 5);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    case 2:

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 2.5);

                        frontServo->SetDegree(120);

                        controller().TurnDirection(rightTurn, 90);

                        controller().MoveStraight(forward, 0.5);

                        frontServo->SetDegree(180);

                        Sleep(5.0);

                        frontServo->SetDegree(120);

                        controller().MoveStraight(backward, 0.5);

                        controller().TurnDirection(leftTurn, 90);

                        controller().MoveStraight(forward, 7);

                        controller().TurnDirection(rightTurn, 45);

                        controller().MoveStraight(forward, 40);

                        break;

                    default:

                        break;

                }

                break;

            default:

                break;

        }

        //Sleep(3.0);

     }

     void finalRun4C(int leverNumber, char region) {

        int color = 0;

        LCD.Clear();

        LCD.WriteLine(region);

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value()) {

            //leverNumber = RCS.GetCorrectLever();

        }

        //Sleep(3.0);

        // Hit start button
        controller().MoveStraight(forward, 1);
        controller().MoveStraight(backward, 1);

        controller().MoveStraight(backward, 10);

        controller().TurnDirection(leftTurn, 22);

        controller().MoveStraight(forward, 8);

        leftIGWAN->SetPercent(-20);
        rightIGWAN->SetPercent(20);

        Sleep(2.0);

        controller().StopBothMotors();

        controller().TurnDirection(rightTurn, 84);

        //backwardSpeed = -50;

        controller().MoveStraight(backward, 26);

        //backwardSpeed = -40;

        //Pos: At top of ramp, move toward light
        controller().TurnDirection(leftTurn, 15.5);

        controller().MoveStraight(backward, 25);

        //Pos: At top of ramp, move toward light
        // controller().TurnDirection(leftTurn, 30);

        // controller().MoveStraight(backward, 26);

        //TODO: Read light
        Sleep(3.0);

        //Move forward from light, and position at luggage drop
        controller().MoveStraight(forward, 6);

        controller().TurnDirection(rightTurn, 39);

        controller().MoveStraight(forward, 14);

        // Drop luggage
        armServo->SetDegree(0);

        //Sleep
        Sleep(2.0);  

        //Rotate and get in position for kiosk buttons
        controller().MoveStraight(backward, 2);

        controller().TurnDirection(rightTurn, 95);

        controller().MoveStraight(backward, 4.5);

        controller().TurnDirection(rightTurn, 95);

        //Rotate front servo according to light read
        switch(color) {

            //If red,
            case 0:

                frontServo->SetDegree(162);

                break;

            //If blue,
            case 1:

                frontServo->SetDegree(65);

                break;

            default:

                frontServo->SetDegree(0);
                break;

        }

        //Move toward kiosk buttons
        controller().MoveStraight(forward, 11);

        //Back up
        controller().MoveStraight(backward, 2);

        Sleep(0.5);

        //Second attempt at pressing kiosk button moving slower this time
        leftIGWAN->SetPercent(-20);
        rightIGWAN->SetPercent(20);

        Sleep(2.0);

        controller().StopBothMotors();

        //Back up for passport
        controller().MoveStraight(backward, 1.5);

        //Reset servos to original position
        frontServo->SetDegree(95);
        armServo->SetDegree(120);

        //Rotate towards kiosk
        controller().TurnDirection(rightTurn, 75);

        //Move back to make way for front servo positioning
        controller().MoveStraight(backward, 2);

        //Set servo for passport flip
        frontServo->SetDegree(180);

        //Sleep to check positioning
        Sleep(2.0);

        //Move forward to get under passport lever (maybe back to 1.5)
        controller().MoveStraight(forward, 2);

        //Move servo up to flip passport lever
        frontServo->SetDegree(60);

        Sleep(1.0);

        //Flip servo back down to bring passport lever back down
        frontServo->SetDegree(180);

        Sleep(1.0);

        //Begin moving to steep ramp
        controller().MoveStraight(backward, 14);

        controller().TurnDirection(leftTurn, 55);

        controller().MoveStraight(backward, 34);

        switch (leverNumber) {

            case 0:

                controller().TurnDirection(rightTurn, 90);

                controller().MoveStraight(forward, 10);

                frontServo->SetDegree(145);

                controller().TurnDirection(rightTurn, 90);

                frontServo->SetDegree(160);

                Sleep(5.0);

                frontServo->SetDegree(145);

                //controller().MoveStraightWithSlightTurn(rightTurn, 50);

                // controller().TurnDirection(rightTurn, 75);

                // controller().MoveStraight(forward, 0.5);



                break;

            case 1:

                break;

            case 2:

                break;

            default:

                break;

        }

     }

     void finalRun4D(int leverNumber, char region) {

        int color = 0;

        //LCD.Clear();

        //LCD.WriteLine(region);

        // Start when Red light turns on
        while (1.0 < cdsSensor->Value()) {

            //leverNumber = RCS.GetCorrectLever();

        }

        //Sleep(3.0);

        // Hit start button
        controller().MoveStraight(forward, 1);
        controller().MoveStraight(backward, 1);

        controller().MoveStraight(backward, 10);

        controller().TurnDirection(leftTurn, 22);

        controller().MoveStraight(forward, 8);

        leftIGWAN->SetPercent(-20);
        rightIGWAN->SetPercent(20);

        Sleep(2.0);

        controller().StopBothMotors();

        controller().TurnDirection(rightTurn, 84);

        //backwardSpeed = -50;

        controller().MoveStraight(backward, 26);

        //backwardSpeed = -40;

        //Pos: At top of ramp, move toward light
        controller().TurnDirection(leftTurn, 15.5);

        controller().MoveStraight(backward, 25);

        //Pos: At top of ramp, move toward light
        // controller().TurnDirection(leftTurn, 30);

        // controller().MoveStraight(backward, 26);

        //TODO: Read light
        Sleep(3.0);

        //Move forward from light, and position at luggage drop
        controller().MoveStraight(forward, 6);

        controller().TurnDirection(rightTurn, 39);

        controller().MoveStraight(forward, 14);

        // Drop luggage
        armServo->SetDegree(0);

        //Sleep
        Sleep(2.0);  

        //Rotate and get in position for kiosk buttons
        controller().MoveStraight(backward, 2);

        controller().TurnDirection(rightTurn, 95);

        controller().MoveStraight(backward, 4.5);

        controller().TurnDirection(rightTurn, 95);

        //Rotate front servo according to light read
        switch(color) {

            //If red,
            case 0:

                frontServo->SetDegree(162);

                break;

            //If blue,
            case 1:

                frontServo->SetDegree(65);

                break;

            default:

                frontServo->SetDegree(0);
                break;

        }

        //Move toward kiosk buttons
        controller().MoveStraight(forward, 11);

        //Back up
        controller().MoveStraight(backward, 2);

        Sleep(0.5);

        //Second attempt at pressing kiosk button moving slower this time
        leftIGWAN->SetPercent(-20);
        rightIGWAN->SetPercent(20);

        Sleep(2.0);

        controller().StopBothMotors();

        //Back up for passport
        controller().MoveStraight(backward, 1.5);

        //Reset servos to original position
        frontServo->SetDegree(95);
        armServo->SetDegree(120);

        //Rotate towards kiosk
        controller().TurnDirection(rightTurn, 75);

        //Move back to make way for front servo positioning
        controller().MoveStraight(backward, 2);

        //Set servo for passport flip
        frontServo->SetDegree(180);

        //Sleep to check positioning
        Sleep(2.0);

        //Move forward to get under passport lever (maybe back to 1.5)
        controller().MoveStraight(forward, 2);

        //Move servo up to flip passport lever
        frontServo->SetDegree(60);

        Sleep(1.0);

        //Flip servo back down to bring passport lever back down
        frontServo->SetDegree(180);

        Sleep(1.0);

        //Begin moving to steep ramp
        controller().MoveStraight(backward, 14);

        controller().TurnDirection(leftTurn, 55);

        controller().MoveStraight(backward, 34);

        switch (leverNumber) {

            case 0:

                controller().TurnDirection(rightTurn, 90);

                controller().MoveStraight(forward, 10);

                frontServo->SetDegree(145);

                controller().TurnDirection(rightTurn, 90);

                frontServo->SetDegree(160);

                Sleep(5.0);

                frontServo->SetDegree(145);

                //controller().MoveStraightWithSlightTurn(rightTurn, 50);

                // controller().TurnDirection(rightTurn, 75);

                // controller().MoveStraight(forward, 0.5);



                break;

            case 1:

                break;

            case 2:

                break;

            default:

                break;

        }

     }

    //  void begin() {

    //     armServo->SetDegree(120);
    //     frontServo->SetDegree(95);

    //     Sleep(3.0);

    //     // Hit start button
    //     controller().MoveStraight(forward, 0.5);
    //     controller().MoveStraight(backward, 0.5);

    //     controller().MoveStraight(backward, 10);

    //     controller().TurnDirection(leftTurn, 25);

    //     controller().MoveStraight(forward, 8);

    //     leftIGWAN->SetPercent(-20);
    //     rightIGWAN->SetPercent(20);

    //     Sleep(2.0);

    //     controller().StopBothMotors();

    //     controller().TurnDirection(rightTurn, 85);

    //     controller().MoveStraight(backward, 25);

    //     //Pos: At top of ramp, move toward light
    //     controller().TurnDirection(leftTurn, 15);

    //     controller().MoveStraight(backward, 26);
        
    //  }

};