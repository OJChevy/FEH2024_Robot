#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    /**
     * menuLabels = labels for icon array on Proteus starting screen
     * leftIGWAN = shared pointer for left igwan motor
     * rightIGWAN = shared pointer for right igwan motor
     * cdsSensor = shared pointer for cds sensor
     * leftEncoder = shared pointer for left encoder
     * rightEncoder = shared pointer for right encoder
     * armServo = shared pointer for servo located on left side of robot
     * frontServo = shared pointer for servo located on front of robot
     * selection = int value that controls the switch statement based on icon array input
    */
   
    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Bty Life" };

    auto leftIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor0, 9.0);
    auto rightIGWAN = std::make_shared<FEHMotor>(FEHMotor::Motor1, 9.0);

    auto cdsSensor = std::make_shared<AnalogInputPin>(FEHIO::P1_0);

    auto leftEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_7);
    auto rightEncoder = std::make_shared<DigitalEncoder>(FEHIO::P0_0);

    auto armServo = std::make_shared<FEHServo>(FEHServo::Servo0);
    auto frontServo = std::make_shared<FEHServo>(FEHServo::Servo7);

    int selection = -2;

    // armServo->SetMin(1290);
    // armServo->SetMax(2215);

    //Setting the min and max values for the arm servo
    armServo->SetMin(1132);
    armServo->SetMax(2000);

    //Setting the min and max values for the front servo
    frontServo->SetMin(500);
    frontServo->SetMax(2320);

    //Creating an object of robot class using custom constructor
    Robot robot = Robot(leftIGWAN, rightIGWAN, cdsSensor, leftEncoder, rightEncoder, armServo, frontServo);

    //While loop for icon array, returns back to icon array after each function completes
    while (selection != -1) {

        //Getting value of selection from robot.GUIControl function, pass in menuLabels to
        // label icon array
        selection = robot.GUIControl(menuLabels);

        //Switch statement based on gui control selection
        switch (selection) {

            case 0:

                //Run robot.SystemCheck() when System check is selected in icon array
                //Iteration for System Check: 27
                robot.SystemCheck();
                //controller.MoveStraight(leftIGWAN, rightIGWAN, -40, rightEncoder, 20, 1.75);
                //controller.DisplayCDSSensorValue(cdsSensor);
                break;

            case 1:

                //Run robot.Run() when Run is selected in icon array
                //Iterations for Third Progress Check: 24
                //Iterations for Fourth Progress Check: 28
                //Iterations for Fifth Progress Check: 13 
                //Owen is a bitch
                robot.RunProgressCheck5();
                break;

            case 2:

                //Call a calibrate function so servos can be easily calibrated
                //Iteration: 4
                robot.Calibrate();
                break;

            case 3:

                //Call a battery life function to check battery life of Proteus when it has been selected from menu
                //Iteration: 16
                robot.BatteryLife();
                break;

            default:

                //Quit out of the icon array if something goes wrong
                break;

        }

    }

	return 0;
}
