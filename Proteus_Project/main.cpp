#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    const float SPEED = 50;

    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Quit" };
    //bump switches
    DigitalInputPin frontSwitch(FEHIO::P0_3);
    //cds sensor
    AnalogInputPin cdsSensor(FEHIO::P1_0);
    //IGWAN motor shaft encoders
    DigitalEncoder leftEncoder(FEHIO::P0_7);
    DigitalEncoder rightEncoder(FEHIO::P0_0);


    //IGWAN Motors
    FEHMotor leftIGWAN(FEHMotor::Motor0, 9.0);
    FEHMotor rightIGWAN(FEHMotor::Motor1, 9.0);

    // //Servo Motors
    // FEHServo plateServo(FEHServo::Servo0);
     FEHServo armServo(FEHServo::Servo0);

     armServo.SetMin(1290);
     armServo.SetMax(2085);

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
                //Iteration for System Check: 10
                //robot.SystemCheck(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder);
                //controller.MoveStraight(leftIGWAN, rightIGWAN, -40, rightEncoder, 20, 1.75);
                controller.DisplayCDSSensorValue(cdsSensor);
                break;

            case 1:

                //TODO: Call run function for course
                //robot.MoveTowardRamp(leftIGWAN, rightIGWAN, SPEED);
                //Iterations for First Progress Check: 75
                //Iterations for Second Progress Check: 78
                //Iterations for Third Progress Check: 23
                robot.RunProgressCheck3(leftIGWAN, rightIGWAN, leftEncoder, rightEncoder, cdsSensor, armServo);
                break;

            case 2:

                //TODO: Calibrate various motors
                //Iteration: 3
                robot.Calibrate(armServo);
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
