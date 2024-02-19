#pragma once

#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHLCD.h>
#include <FEHServo.h>

class Controller {

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
        void SetMotor(FEHMotor motor, float percent) {

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
        void StopMotor(FEHMotor motor) {

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
        void DisplayCDSSensorValue(AnalogInputPin cdsSensor)
        {

            int counter = 5;
            int i = 0;

            LCD.Clear();
            LCD.WriteLine(cdsSensor.Value());
        }

        /**
         * @author Owen Chevalier
         * 
         * Activate the calibration screen of the servo arm to gather min and max values
         * 
         * @param servo
         *      servo motor to calibrate
        */
        void CalibrateServoArm(FEHServo servo) {

            servo.TouchCalibrate();

        }

};