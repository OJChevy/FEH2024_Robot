#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    const float SPEED = 50;

    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Bty Life" };

    //IGWAN Motors
    auto leftIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor0, 9.0);
    auto rightIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor1, 9.0);

    auto cdsSensor = std::make_shared<AnalogInputPin>(FEHIO::P1_0);

    auto leftEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_7);
    auto rightEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_0);

    auto armServo = std::make_shared<FEHServo>(FEHServo::Servo0);
    auto frontServo = std::make_shared<FEHServo>(FEHServo::Servo7);

    // armServo->SetMin(1290);
    // armServo->SetMax(2215);

    armServo->SetMin(1132);
    armServo->SetMax(2000);

    frontServo->SetMin(500);
    frontServo->SetMax(2320);

    float xPos;
    float yPos;

    Robot robot = Robot(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, rightEncoder, armServo, frontServo);

    int selection = -2;

    while (selection != -1) {

        selection = robot.GUIControl(menuLabels);

        switch (selection) {

            case 0:

                //TODO: Call System check
                //Iteration for System Check: 27
                robot.CalibrateArm();
                //controller.MoveStraight(leftIGWAN, rightIGWAN, -40, rightEncoder, 20, 1.75);
                //controller.DisplayCDSSensorValue(cdsSensor);
                break;

            case 1:

                //TODO: Call run function for course
                //Iterations for Third Progress Check: 24
                //Iterations for Fourth Progress Check: 28
                //Iterations for Fifth Progress Check: 13 
                //Owen is a bitch
                robot.RunProgressCheck5();
                //2
                //robot.MoveTest();
                break;

            case 2:

                //TODO: Calibrate various motors
                //Iteration: 4
                robot.Calibrate();
                break;

            case 3:

                //Iteration: 16
                robot.BatteryLife();
                break;

            default:

                //TODO: Quit out of program, tell user that proteus controller has been quit
                break;

        }

    }

	return 0;
}
