#pragma once

#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHLCD.h>
#include <FEHServo.h>
#include <FEHRCS.h>
#include <FEHBattery.h>
#include <memory>

/**
 * PI = const value of pi, used for turning calculations
*/
#define PI 3.14159265358979323846264338327

class Controller
{

    /**
     * forwardSpeed = normal forward speed for robot
     * slowForwardSpeed = slower forward speed that is used for move with slight turn
     * backwardSpeed = normal backward speed for robot
     * slowBackwardSpeed = slower backward speed that is used for move with slight turn
     * radius = radius value of wheels
     * leftIGWAN = shared pointer for left igwan motor
     * rightIGWAN = shared pointer for right igwan motor
     * cdsSensor = shared pointer for cds sensor
     * leftEncoder = shared pointer for left encoder
     * rightEncoder = shared pointer for right encoder
     * armServo = shared pointer for servo located on left side of robot
     * frontServo = shared pointer for servo located on front side of robot
    */
   
    float forwardSpeed;
    float slowForwardSpeed;
    
    float backwardSpeed;
    float slowBackwardSpeed;

    float radius;

    std::shared_ptr<FEHMotor> leftIGWAN;
    std::shared_ptr<FEHMotor> rightIGWAN;

    std::shared_ptr<AnalogInputPin> cdsSensor;
    
    std::shared_ptr<DigitalEncoder> leftEncoder;
    std::shared_ptr<DigitalEncoder> rightEncoder;

    std::shared_ptr<FEHServo> armServo;
    std::shared_ptr<FEHServo> frontServo;

public:

    /**
     * Custom constructor for controller class.
     * 
     * @param leftMotor
     *      shared pointer for left igwan motor
     * @param rightMotor
     *      shared pointer for right igwan motor
     * @param cds
     *      shared pointer for cds sensor
     * @param leftEncode
     *      shared pointer for left encoder
     * @param rightEncode
     *      shared pointer for right encoder
     * @param clawArm
     *      shared pointer for servo located on left side of the robot
     * @param frontArmServo
     *      shared pointer for servo located on the front side of the robot
     * @param fSpeed
     *      normal forward speed
     * @param sFSpeed
     *      slow forward speed
     * @param bSpeed
     *      normal backward speed
     * @param sBSpeed
     *      slow backward speed
     * @param radi
     *      radius of robot wheels
    */
    Controller(std::shared_ptr<FEHMotor> leftMotor, 
    std::shared_ptr<FEHMotor> rightMotor,
    std::shared_ptr<AnalogInputPin> cds,
    std::shared_ptr<DigitalEncoder> leftEncode,
    std::shared_ptr<DigitalEncoder> rightEncode,
    std::shared_ptr<FEHServo> clawArm,
    std::shared_ptr<FEHServo> frontArmServo,
    float fSpeed, float sFSpeed, float bSpeed,
    float sBSpeed, float radi){

        leftIGWAN = leftMotor;
        rightIGWAN = rightMotor;

        cdsSensor = cds;

        leftEncoder = leftEncode;
        rightEncoder = rightEncode;

        armServo = clawArm;
        frontServo = frontArmServo;

        forwardSpeed = fSpeed;
        slowForwardSpeed = sFSpeed;
        backwardSpeed = bSpeed;
        slowBackwardSpeed = sBSpeed;
        radius = radi;

    }

    /**
     * Test function used for running motors with shared pointers.
    */
    void moveTest() {

        //Clear screen
        LCD.Clear();

        //Show calling function
        LCD.WriteLine("Calling function");

        //Set percentage of motors
        rightIGWAN->SetPercent(25);
        leftIGWAN->SetPercent(25);

        //Sleep for a couple seconds
        Sleep(2.0);

        //Stop both of the motors after time has elapsed
        StopBothMotors();

        //Show that the function has ended
        LCD.WriteLine("Ending function");

    }

    /**
     * @author Owen Chevalier
     *
     * Displays the value of the CDS sensor to the Proteus display.
     *
     * @param cdsSensor
     *      cdsSensor to display value of to Proteus
     */
    void DisplayCDSSensorValue(std::shared_ptr<AnalogInputPin> cdsSensor)
    {
        LCD.Clear();
        while (true) {

            
            LCD.WriteLine(cdsSensor->Value());

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
    void CalibrateServoArm(std::shared_ptr<FEHServo> servo)
    {

        servo->TouchCalibrate();
    }

    /**
     * Returns the number of transitions the motors will go based on linear distance
     * 
     * @param distance
     *      linear distance the robot should travel
     * @param radius
     *      radius of the wheels
     * @returns the number of transitions based on linear distance
    */
    int ShaftEncoderTransition(float distance, float radius)
    {

        int numTransitionPerRot = 318;

        int numOfTransitions = 0;

        numOfTransitions = (distance * numTransitionPerRot) / (2.0 * PI * radius);

        return numOfTransitions;
    }

    /**
     * Moves the robot in a straight direction.
     * 
     * @param direction
     *      direction the robot should travel in
     * @param distance
     *      linear distance the robot should travel
    */
    void MoveStraight(int direction, float distance)
    {

        //Calculating actual forward speed based on the voltage of the battery
        float actualForwardSpeed = 11.5 / Battery.Voltage();
        actualForwardSpeed *= forwardSpeed;

        //Calculating actual backward speed based on the voltage of the battery
        float actualBackwardSpeed = 11.5 / Battery.Voltage();
        actualBackwardSpeed *= backwardSpeed;

        //Checking direction inputted by user
        if (direction == 0) {

            //Set motors to correct speed and move forward
            leftIGWAN->SetPercent(actualForwardSpeed * (-1));
            rightIGWAN->SetPercent(actualForwardSpeed);

        } else if (direction == 1) {

            //Set motors to correct speed and move backward
            leftIGWAN->SetPercent(actualBackwardSpeed * (-1));
            rightIGWAN->SetPercent(actualBackwardSpeed);

        }

        //Move the robot the intended distance
        moveRobot(distance);
    }

    /**
     * Turns the robot a certain number of degrees while stationary.
     * 
     * @param direction
     *      direction the robot should to turn
     * @param distance
     *      the number of degrees the robot should turn
    */
    void TurnDirection(bool direction, float distance)
    {

        //Calculate actual forward speed based on the voltage of the battery
        float actualForwardSpeed = 11.5 / Battery.Voltage();
        actualForwardSpeed *= forwardSpeed;

        //Calculate actual backward speed based on the voltage of the battery
        float actualBackwardSpeed = 11.5 / Battery.Voltage();
        actualBackwardSpeed *= backwardSpeed;


        //Get direction value from argument
        if (direction == 0)
        {
            //Turn left by setting the motors their respective speeds
            leftIGWAN->SetPercent(actualForwardSpeed);
            rightIGWAN->SetPercent(actualForwardSpeed);

        } else {

            //Turn right by setting the motors their respective speeds
            leftIGWAN->SetPercent(actualBackwardSpeed);
            rightIGWAN->SetPercent(actualBackwardSpeed);
        }

        //Keep moving the robot until the desired degrees have been reached
        moveRobot(turnDistance(distance));

    }

    /**
     * Move the robot mostly straight with a slight curve to the left or the right.
     * 
     * @param direction
     *      The direction of the curve in which the robot should travel
     * @param distance
     *      The linear distance the robot should travel
    */
    void MoveStraightWithSlightTurn(int direction, float distance) {

        //Calculating actual forward speed based on the voltage of the battery
        float actualForwardSpeed = 11.5 / Battery.Voltage();
        actualForwardSpeed *= forwardSpeed;

        //Calculating actual backward speed based on the voltage of the battery
        float actualSlowForwardSpeed = 11.5 / Battery.Voltage();
        actualSlowForwardSpeed *= slowForwardSpeed;

        if (direction == 0) {

            //Turn right
            leftIGWAN->SetPercent(actualSlowForwardSpeed * (-1));
            rightIGWAN->SetPercent(actualForwardSpeed);

        } else {

            //Turn left
            leftIGWAN->SetPercent(actualForwardSpeed * (-1));
            rightIGWAN->SetPercent(actualSlowForwardSpeed);

        }

        //Move the robot until the distance has been reached
        moveRobot(distance);
    }

    /**
     * Stops both of the motors simultaneously.
    */
    void StopBothMotors() {

        //Stop both of the motors by calling the built-in Stop() function
        leftIGWAN->Stop();
        rightIGWAN->Stop();

    }

    /**
     * Returns the linear distance the robot should travel to turn a certain number of degrees.
     * 
     * @param degree
     *  The number of degrees the robot should turn
     * 
     * @returns the linear distance the robot's motors have to travel to turn a certain amount
    */
    float turnDistance(float degree) {

        //Calculate the turnDistance based on the equation
        float turnDistance = (degree/360.0)*23.3;
        return turnDistance;
    }

    /**
     * Keeps the robot moving until the specified distance has been reached.
     * 
     * @param distance
     *      The linear distance the robot should travel
    */
    void moveRobot(float distance) {

        //Calculate numOfTransitions based on the value returned by the following function
        int numOfTransitions  = ShaftEncoderTransition(distance, radius);
        
        //Reset the counts of the right encoder
        rightEncoder->ResetCounts();
        
        //Empty while loop until number of transitions has been reached
        while (rightEncoder->Counts() < numOfTransitions);

        //Stop both of the motors after distance has been reached
        StopBothMotors();
    }
};