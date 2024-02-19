#include "include/controller.hpp"

int main(void)
{
    
    //IGWAN Motors
    FEHMotor leftIGWAN(FEHMotor::Motor0, 9.0);
    FEHMotor rightIGWAN(FEHMotor::Motor1, 9.0);

    //Servo Motors
    FEHServo plateServo(FEHServo::Servo0);
    FEHServo armServo(FEHServo::Servo1);

    

	return 0;
}
