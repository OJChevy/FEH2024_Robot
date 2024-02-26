#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    const float SPEED = 50;

    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Quit" };


    DigitalEncoder leftEncoder(FEHIO::P0_7);
    DigitalEncoder rightEncoder(FEHIO::P0_0);


    //IGWAN Motors
    FEHMotor leftIGWAN(FEHMotor::Motor0, 9.0);
    FEHMotor rightIGWAN(FEHMotor::Motor1, 9.0);

    // //Servo Motors
    // FEHServo plateServo(FEHServo::Servo0);
    // FEHServo armServo(FEHServo::Servo1);

    //this is a test commit


    float xPos;
    float yPos;

    Controller controller;
    Robot robot;

    int selection = -2;

    while (selection != -1) {

        selection = controller.GUIControl(menuLabels);

        switch (selection) {

            case 0:

                //TODO: Call System check
                robot.SystemCheck(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder);
                break;

            case 1:

                //TODO: Call run function for course
                //robot.MoveTowardRamp(leftIGWAN, rightIGWAN, SPEED);
                //Iteration 16
                robot.RunProgressCheck1(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder);
                break;

            case 2:

                //TODO: Calibrate various motors
                robot.Calibrate();
                break;

            default:

                //TODO: Quit out of program, tell user that proteus controller has been quit
                break;

        }

    }

    // controller.SetMotor(leftIGWAN, 15);
    // controller.SetMotor(rightIGWAN, -15);

    // rightEncoder.ResetCounts();

    // while (rightEncoder.Counts() < 300);

    // controller.SetMotor(leftIGWAN, 0);
    // controller.SetMotor(rightIGWAN, 0);

	return 0;
}
