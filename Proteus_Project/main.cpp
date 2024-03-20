#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    const float SPEED = 50;

    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Quit" };

    //IGWAN Motors
    auto leftIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor0, 9.0);
    auto rightIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor1, 9.0);

    auto cdsSensor = std::make_shared<AnalogInputPin>(FEHIO::P1_0);

    auto leftEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_7);
    auto rightEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_0);

    auto armServo = std::make_shared<FEHServo>(FEHServo::Servo0);

     armServo->SetMin(1290);
     armServo->SetMax(2085);

    float xPos;
    float yPos;

    Robot robot = Robot(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, rightEncoder, armServo);

    int selection = -2;

    while (selection != -1) {

        selection = robot.displayGUIControl(menuLabels);

        switch (selection) {

            case 0:

                //TODO: Call System check
                //Iteration for System Check: 11
                robot.SystemCheck();
                //controller.MoveStraight(leftIGWAN, rightIGWAN, -40, rightEncoder, 20, 1.75);
                //controller.DisplayCDSSensorValue(cdsSensor);
                break;

            case 1:

                //TODO: Call run function for course
                //Iterations for Third Progress Check: 18
                robot.RunProgressCheck3();
                //2
                //robot.MoveTest();
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
