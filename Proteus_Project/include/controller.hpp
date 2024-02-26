#pragma once

#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHLCD.h>
#include <FEHServo.h>

#define PI 3.14159265358979323846264338327

class Controller
{

public:
    /**
     * @author Owen Chevalier
     *
     * Sets the percentage of the specified motor
     *
     * @param motor
     *      motor to set percentage of
     * @param percent
     *      percentage to set motor power to
     */
    void SetMotor(FEHMotor &motor, float percent)
    {

        motor.SetPercent(percent);
    }

    /**
     * @author Owen Chevalier
     *
     * Stops the power to passed in motor
     *
     * @param motor
     *      motor to stop
     */
    void StopMotor(FEHMotor &motor)
    {

        motor.Stop();
    }

    /**
     * @author Owen Chevalier
     *
     * Displays the value of the CDS sensor to the Proteus display
     *
     * @param cdsSensor
     *      cdsSensor to display value of to Proteus
     */
    void DisplayCDSSensorValue(AnalogInputPin &cdsSensor)
    {

        while (true) {

            LCD.Clear();
            LCD.WriteLine(cdsSensor.Value());

        }
    }

    /**
     * @author Owen Chevalier
     *
     * Activate the calibration screen of the servo arm to gather min and max values
     *
     * @param servo
     *      servo motor to calibrate
     */
    void CalibrateServoArm(FEHServo &servo)
    {

        servo.TouchCalibrate();
    }

    int ShaftEncoderTransition(float distance, float radius)
    {

        int numTransitionPerRot = 318;

        int numOfTransitions = 0;

        numOfTransitions = (distance * numTransitionPerRot) / (2.0 * PI * radius);

        return numOfTransitions;
    }

    /**
     * @author Owen Chevalier
     *
     * Displays and controls the custom GUI on the Proteus display
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

    void MoveStraight(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, float speed)
    {

        leftIGWAN.SetPercent(speed * (-1));
        rightIGWAN.SetPercent(speed);
    }

    void TurnDirection(FEHMotor &leftIGWAN, FEHMotor &rightIGWAN, float forwardSpeed, float backwardSpeed, bool direction)
    {
        // direction 0 is right else turn left
        if (direction == 0)
        {
            //turn left
            leftIGWAN.SetPercent(forwardSpeed); //Testing forward speed instead of backward speed
            rightIGWAN.SetPercent(forwardSpeed);

        } else {

            //turn right
            leftIGWAN.SetPercent(backwardSpeed); //Testing backward speed instead of forward speed
            rightIGWAN.SetPercent(backwardSpeed);
        }
    }
};